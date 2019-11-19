/* ////////////////////////////////////////////////////////////

File Name: main.cpp
Copyright (c) 2017 Soji Yamakawa.  All rights reserved.
http://www.ysflight.com

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//////////////////////////////////////////////////////////// */

#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include <fslazywindow.h>
#include "ysclass.h"
#include "ysavltree.h"

#include "ysshellext.h"
#include "glutil.h"




class CollapseCandidate
{
public:
	unsigned int v[2];
};

bool operator==(const CollapseCandidate &c1,const CollapseCandidate &c2)
{
	return (c1.v[0]==c2.v[0] && c1.v[1]==c2.v[1]);
}

template <>
struct std::hash <CollapseCandidate>
{
public:
	size_t operator()(CollapseCandidate const &s) const
	{
		return s.v[0]+7*s.v[1];
	}
};

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	double angle=0.0;

	YsVec3 mouse[2];
	YsVec3 highlightVtPos;
	std::vector <YsShellExt::VertexHandle> highlightVtHd;

	YsShellExt::VertexHandle edVtHd[2];

	YsAVLTree <double,CollapseCandidate> avlTree;
	std::unordered_map <CollapseCandidate,YsAVLTree<double,CollapseCandidate>::NodeHandle> edgeToTreeNode;

	YsVec3 viewTarget;
	YsMatrix4x4 viewRot;
	double viewDistance;
	double nearZ,farZ;

	YsMatrix4x4 projection,modelView;

public:
	YsShellExt mesh;
	std::vector <float> vtx,nom,col;
	std::vector <float> wireVtx,wireCol;

	YsShellExt::PolygonHandle PickedPlHd(int mx,int my) const;
	YsShellExt::VertexHandle PickedVtHd(int mx,int my) const; 


	void RemakeVertexArray(void);
	void SetUpHeadLight(void);

	void SetUPQEMSimplification(void);

	void CollapseEdge(YsShellExt::VertexHandle fromVtHd,YsShellExt::VertexHandle toVtHd);
	double QuadricErrorMetric(YsShellExt::VertexHandle fromVtHd,YsShellExt::VertexHandle toVtHd) const;
	YsShell::Edge FindMinimumQEMEdge(void) const;
	void CollapseMinimumQEMEdge(void);

	void CollapseMinimumQEMEdgeExhaustive(void);

	FsLazyWindowApplication();
	virtual void BeforeEverything(int argc,char *argv[]);
	virtual void GetOpenWindowOption(FsOpenWindowOption &OPT) const;
	virtual void Initialize(int argc,char *argv[]);
	virtual void Interval(void);
	virtual void BeforeTerminate(void);
	virtual void Draw(void);
	virtual bool UserWantToCloseProgram(void);
	virtual bool MustTerminate(void) const;
	virtual long long int GetMinimumSleepPerInterval(void) const;
	virtual bool NeedRedraw(void) const;
};


YsShellExt::PolygonHandle FsLazyWindowApplication::PickedPlHd(int mx,int my) const
{
	int winWid,winHei;
	FsGetWindowSize(winWid,winHei);

	YsVec3 mouse[2]=
	{
		WindowToViewPort(winWid,winHei,mx,my),
		WindowToViewPort(winWid,winHei,mx,my)
	};
	mouse[0].SetZ(-1.0);
	mouse[1].SetZ( 1.0);

	YsVec3 mouseDir=mouse[1]-mouse[0];

	projection.MulInverse(mouse[0],mouse[0],1.0);
	modelView.MulInverse(mouse[0],mouse[0],1.0);
	projection.MulInverse(mouse[1],mouse[1],1.0);
	modelView.MulInverse(mouse[1],mouse[1],1.0);

	YsShellExt::PolygonHandle pickedPlHd=nullptr;
	double dMin=0.0;
	for(auto plHd=mesh.FindNextPolygon(nullptr); mesh.NullPolygon()!=plHd; plHd=mesh.FindNextPolygon(plHd))
	{
		auto plVtHd=mesh.GetPolygonVertex(plHd);
		if(3<=plVtHd.size())
		{
			YsVec3 vtPos[3]=
			{
				mesh.GetVertexPosition(plVtHd[0]),
				mesh.GetVertexPosition(plVtHd[1]),
				mesh.GetVertexPosition(plVtHd[2]),
			};

			YsPlane pln;
			YsVec3 itsc;
			if(YSOK==pln.MakePlaneFromTriangle(vtPos[0],vtPos[1],vtPos[2]) &&
			   YSOK==pln.GetPenetration(itsc,mouse[0],mouse[1]) &&
			   YSINSIDE==YsCheckInsidePolygon3(itsc,3,vtPos))
			{
				auto d=itsc*mouseDir;
				if(mesh.NullPolygon()==pickedPlHd || d>dMin)
				{
					pickedPlHd=plHd;
					dMin=d;
				}
			}
		}
	}
	return pickedPlHd;
}


YsShellExt::VertexHandle FsLazyWindowApplication::PickedVtHd(int mx,int my) const
{
	int winWid,winHei;
	FsGetWindowSize(winWid,winHei);

	YsShellExt::VertexHandle pickedVtHd=mesh.NullVertex();
	double pickedVtHdZ=0.0;

	for(auto vtHd=mesh.FindNextVertex(nullptr); mesh.NullVertex()!=vtHd; vtHd=mesh.FindNextVertex(vtHd))
	{
		auto vtPos=mesh.GetVertexPosition(vtHd);
		vtPos=projection*modelView*vtPos;

		auto vtPosW=ViewPortToWindow(winWid,winHei,vtPos);		

		int dx=mx-vtPosW.x();
		int dy=my-vtPosW.y();
		if(-8<=dx && dx<=8 && -8<=dy && dy<=8)
		{
			if(mesh.NullVertex()==pickedVtHd || vtPos.z()<pickedVtHdZ)
			{
				pickedVtHd=vtHd;
				pickedVtHdZ=vtPos.z();
			}
		}
	}

	return pickedVtHd;
}

void FsLazyWindowApplication::RemakeVertexArray(void)
{
	vtx.clear();
	nom.clear();
	col.clear();


	for(auto plHd=mesh.FindNextPolygon(nullptr); mesh.NullPolygon()!=plHd; plHd=mesh.FindNextPolygon(plHd))
	{
		auto plVtHd=mesh.GetPolygonVertex(plHd);
		if(3<=plVtHd.size())
		{
			auto plNom=mesh.GetNormal(plHd);
			auto plCol=mesh.GetColor(plHd);
			YsVec3 vtPos[3]=
			{
				mesh.GetVertexPosition(plVtHd[0]),
				mesh.GetVertexPosition(plVtHd[1]),
				mesh.GetVertexPosition(plVtHd[2]),
			};
			for(int i=0; i<3; ++i)
			{
				vtx.push_back(vtPos[i].xf());
				vtx.push_back(vtPos[i].yf());
				vtx.push_back(vtPos[i].zf());
				nom.push_back(plNom.xf());
				nom.push_back(plNom.yf());
				nom.push_back(plNom.zf());
				col.push_back(plCol.Rf());
				col.push_back(plCol.Gf());
				col.push_back(plCol.Bf());
				col.push_back(plCol.Af());
			}
		}
	}

	wireVtx.clear();
	wireCol.clear();

	YsShellEdgeEnumHandle edHd=nullptr;
	while(YSOK==mesh.MoveToNextEdge(edHd))
	{
		auto edge=mesh.GetEdge(edHd);
		YsVec3 vtPos[2]={mesh.GetVertexPosition(edge[0]),mesh.GetVertexPosition(edge[1])};

		wireVtx.push_back(vtPos[0].xf());
		wireVtx.push_back(vtPos[0].yf());
		wireVtx.push_back(vtPos[0].zf());
		wireVtx.push_back(vtPos[1].xf());
		wireVtx.push_back(vtPos[1].yf());
		wireVtx.push_back(vtPos[1].zf());

		wireCol.push_back(0);
		wireCol.push_back(0);
		wireCol.push_back(0);
		wireCol.push_back(1);
		wireCol.push_back(0);
		wireCol.push_back(0);
		wireCol.push_back(0);
		wireCol.push_back(1);
	}
}

void FsLazyWindowApplication::SetUpHeadLight(void)
{
	float lightParam[4]={0,1/(float)sqrt(2.0),1/(float)sqrt(2.0),0};

	glLightfv(GL_LIGHT0,GL_POSITION,lightParam);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void FsLazyWindowApplication::SetUPQEMSimplification(void)
{
	YsShellEdgeEnumHandle edHd=nullptr;
	while(YSOK==mesh.MoveToNextEdge(edHd))
	{
		auto edge=mesh.GetEdge(edHd);
		for(int i=0; i<1; ++i)
		{
			auto from=edge[i];
			auto to=edge[1-i];
			auto qem=QuadricErrorMetric(from,to);

			CollapseCandidate c;
			c.v[0]=mesh.GetSearchKey(from);
			c.v[1]=mesh.GetSearchKey(to);

			auto treeNdHd=avlTree.Insert(qem,c);
			edgeToTreeNode[c]=treeNdHd;
		}
	}
}

void FsLazyWindowApplication::CollapseEdge(YsShellExt::VertexHandle fromVtHd,YsShellExt::VertexHandle toVtHd)
{
	for(auto plHd : mesh.FindPolygonFromEdgePiece(fromVtHd,toVtHd))
	{
		mesh.DeletePolygon(plHd);
	}

	for(auto plHd : mesh.FindPolygonFromVertex(fromVtHd))
	{
		auto plVtHd=mesh.GetPolygonVertex(plHd);
		for(auto &vtHd : plVtHd)
		{
			if(vtHd==fromVtHd)
			{
				vtHd=toVtHd;
			}
		}
		mesh.SetPolygonVertex(plHd,plVtHd);
	}

	mesh.DeleteVertex(fromVtHd);
}

double FsLazyWindowApplication::QuadricErrorMetric(YsShellExt::VertexHandle fromVtHd,YsShellExt::VertexHandle toVtHd) const
{
	double qem=0.0;
	auto newVtPos=mesh.GetVertexPosition(toVtHd);
	for(auto plHd : mesh.FindPolygonFromVertex(fromVtHd))
	{
		auto plVtPos=mesh.GetPolygonVertexPosition(plHd);

		YsVec3 v1=plVtPos[1]-plVtPos[0],v2=plVtPos[2]-plVtPos[0];
		YsVec3 nom=v1^v2;
		nom.Normalize();

		auto d=(newVtPos-plVtPos[0])*nom;
		qem+=(d*d);
	}
	return qem;
}

YsShell::Edge FsLazyWindowApplication::FindMinimumQEMEdge(void) const
{
	auto ndHd0=avlTree.First();
	if(ndHd0!=nullptr)
	{
		auto edge=avlTree[ndHd0];
		YsShellExt::VertexHandle edVtHd[2]=
		{
			mesh.FindVertex(edge.v[0]),
			mesh.FindVertex(edge.v[1])
		};

		YsShell::Edge e;
		e[0]=edVtHd[0];
		e[1]=edVtHd[1];
		return e;
	}
	else
	{
		printf("No more edges.\n");
		YsShell::Edge e;
		e[0]=nullptr;
		e[1]=nullptr;
		return e;
	}
}

void FsLazyWindowApplication::CollapseMinimumQEMEdge(void)
{
	auto minQemEdge=FindMinimumQEMEdge();
	if(nullptr!=minQemEdge[0] && nullptr!=minQemEdge[1])
	{

		for(int i=0; i<2; ++i)
		{
			for(auto connVtHd : mesh.GetConnectedVertex(minQemEdge[i]))
			{
				CollapseCandidate c;
				c.v[0]=mesh.GetSearchKey(minQemEdge[i]);
				c.v[1]=mesh.GetSearchKey(connVtHd);
				for(int j=0; j<2; ++j)
				{
					auto found=edgeToTreeNode.find(c);
					if(found!=edgeToTreeNode.end())
					{
						avlTree.Delete(found->second);
						edgeToTreeNode.erase(found);
					}
					std::swap(c.v[0],c.v[1]);
				}
			}
		}

		CollapseEdge(minQemEdge[0],minQemEdge[1]);

		for(auto connVtHd : mesh.GetConnectedVertex(minQemEdge[1]))
		{
			YsShellExt::VertexHandle edVtHd[2]=
			{
				minQemEdge[1],
				connVtHd
			};

			for(int j=0; j<2; ++j)
			{
				CollapseCandidate c;
				c.v[0]=mesh.GetSearchKey(edVtHd[0]);
				c.v[1]=mesh.GetSearchKey(edVtHd[1]);

				auto qem=QuadricErrorMetric(edVtHd[0],edVtHd[1]);
				auto treeNdHd=avlTree.Insert(qem,c);
				edgeToTreeNode[c]=treeNdHd;

				std::swap(edVtHd[0],edVtHd[1]);
			}
		}
	}
	else
	{
		printf("No more edge to collapse.\n");
	}
}

void FsLazyWindowApplication::CollapseMinimumQEMEdgeExhaustive(void)
{
	YsShell::Edge minQemEdge;
	double minQem;

	minQemEdge[0]=nullptr;
	minQemEdge[1]=nullptr;

	YsShellEdgeEnumHandle edHd=nullptr;
	while(YSOK==mesh.MoveToNextEdge(edHd))
	{
		auto edge=mesh.GetEdge(edHd);

		YsShellExt::VertexHandle collapseCandidate[2][2]=
		{
			{edge[0],edge[1]},
			{edge[1],edge[0]}
		};
		double qem[2]=
		{
			QuadricErrorMetric(edge[0],edge[1]),
			QuadricErrorMetric(edge[1],edge[0]),
		};

		int smaller=0;
		if(qem[1]<qem[0])
		{
			smaller=1;
		}

		if(nullptr==minQemEdge[0] || qem[smaller]<minQem)
		{
			minQem=qem[smaller];
			minQemEdge[0]=collapseCandidate[smaller][0];
			minQemEdge[1]=collapseCandidate[smaller][1];
		}
	}

	if(nullptr!=minQemEdge[0] && nullptr!=minQemEdge[1])
	{
		CollapseEdge(minQemEdge[0],minQemEdge[1]);
	}
}

FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;

	viewTarget=YsVec3::Origin();
	viewDistance=5.0;

	highlightVtPos=YsVec3::Origin();

	edVtHd[0]=mesh.NullVertex();
	edVtHd[1]=mesh.NullVertex();

	mesh.EnableSearch();
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{
}
/* virtual */ void FsLazyWindowApplication::GetOpenWindowOption(FsOpenWindowOption &opt) const
{
	opt.x0=0;
	opt.y0=0;
	opt.wid=1200;
	opt.hei=800;
}
/* virtual */ void FsLazyWindowApplication::Initialize(int argc,char *argv[])
{
	if(2<=argc && YSOK==mesh.LoadStl(argv[1]))
	{
		YsColor blue;
		blue.SetIntRGB(0,255,0);
		for(auto plHd : mesh.AllPolygon())
		{
			mesh.SetPolygonColor(plHd,blue);
		}

		printf("%d vertices\n",(int)mesh.GetNumVertex());
		printf("%d polygons\n",(int)mesh.GetNumPolygon());

		//printf("Stitching Vertices together.\n");
		//mesh.StitchVertexN2(); <- Slow method
		//printf("Stitching done.\n");

		RemakeVertexArray();

		YsVec3 min,max;
		mesh.GetBoundingBox(min,max);

		viewTarget=(min+max)/2.0;

		auto dim=(max-min).GetLength();
		viewDistance=1.31*dim;

		farZ=viewDistance+dim*1.1;
		nearZ=viewDistance-dim*1.1;

		SetUPQEMSimplification();

		printf("STL loaded.\n");
	}
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}
	if(FSKEY_Z==key)
	{
		viewDistance/=1.1;
		if(viewDistance<1.0)
		{
			viewDistance=1.0;
		}
	}
	else if(FSKEY_M==key)
	{
		viewDistance*=1.1;
	}
	else if(FSKEY_C==key)
	{
		if(nullptr!=edVtHd[0] && nullptr!=edVtHd[1])
		{
			CollapseEdge(edVtHd[0],edVtHd[1]);
			RemakeVertexArray();
			edVtHd[0]=nullptr;
			edVtHd[1]=nullptr;
		}
	}
	else if(FSKEY_D==key)
	{
		auto minQemEdge=FindMinimumQEMEdge();
		edVtHd[0]=minQemEdge[0];
		edVtHd[1]=minQemEdge[1];
	}
	else if(FSKEY_SPACE==key)
	{
		for(int i=0; i<500; ++i)
		{
			CollapseMinimumQEMEdge();
		}

		/* This was an exhaustive method.
		auto minQemEdge=FindMinimumQEMEdge();
		if(nullptr!=minQemEdge[0] && nullptr!=minQemEdge[1])
		{
			CollapseEdge(minQemEdge[0],minQemEdge[1]);
			edVtHd[0]=nullptr;
			edVtHd[1]=nullptr;
		} */

		RemakeVertexArray();
	}
	else if(FSKEY_ENTER==key)
	{
		for(int i=0; i<500; ++i)
		{
			CollapseMinimumQEMEdgeExhaustive();
		}
		RemakeVertexArray();
	}

	if(0!=FsGetKeyState(FSKEY_LEFT))
	{
		YsMatrix4x4 mat;
		mat.RotateXZ(YsPi/60.0);
		viewRot=mat*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_RIGHT))
	{
		YsMatrix4x4 mat;
		mat.RotateXZ(-YsPi/60.0);
		viewRot=mat*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_UP))
	{
		YsMatrix4x4 mat;
		mat.RotateYZ(YsPi/60.0);
		viewRot=mat*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_DOWN))
	{
		YsMatrix4x4 mat;
		mat.RotateYZ(-YsPi/60.0);
		viewRot=mat*viewRot;
	}


	int winWid,winHei;
	FsGetWindowSize(winWid,winHei);

	int lb,mb,rb,mx,my;
	auto evt=FsGetMouseEvent(lb,mb,rb,mx,my);
	if(FSMOUSEEVENT_LBUTTONDOWN==evt)
	{
		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			edVtHd[0]=edVtHd[1];
			edVtHd[1]=pickedVtHd;
		}


		/* For testing mouse to line
		YsVec3 vtPos[2]=
		{
			WindowToViewPort(winWid,winHei,mx,my),
			WindowToViewPort(winWid,winHei,mx,my)
		};
		vtPos[0].SetZ(-1.0);
		vtPos[1].SetZ( 1.0);

		projection.MulInverse(vtPos[0],vtPos[0],1.0);
		modelView.MulInverse(vtPos[0],vtPos[0],1.0);
		projection.MulInverse(vtPos[1],vtPos[1],1.0);
		modelView.MulInverse(vtPos[1],vtPos[1],1.0);

		mouse[0]=vtPos[0];
		mouse[1]=vtPos[1];

		printf("%s\n",mouse[0].Txt());
		printf("%s\n",mouse[1].Txt());
		printf("\n"); */

		/* auto pickedPlHd=PickedPlHd(mx,my);
		if(mesh.NullPolygon()!=pickedPlHd)
		{
			mesh.SetPolygonColor(pickedPlHd,YsRed());
			RemakeVertexArray();
		} */

		/*

		edVtHd[1]=edVtHd[0];
		edVtHd[0]=pickedVtHd;
		for(auto plHd : mesh.FindPolygonFromEdgePiece(edVtHd[0],edVtHd[1]))
		{
			mesh.SetPolygonColor(plHd,YsYellow());
		} */
		RemakeVertexArray();
	}


	angle+=YsPi/60.0;

	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1,1);

	int wid,hei;
	FsGetWindowSize(wid,hei);
	auto aspect=(float)wid/(float)hei;

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	projection=MakePerspective(45.0,aspect,nearZ,farZ);

	float projectionF[16];
	projection.GetOpenGlCompatibleMatrix(projectionF);
	glMultMatrixf(projectionF);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SetUpHeadLight();


	modelView.LoadIdentity();
	modelView.Translate(0,0,-viewDistance);
	modelView*=viewRot;
	modelView.Translate(-viewTarget);

	float modelViewF[16];
	modelView.GetOpenGlCompatibleMatrix(modelViewF);
	glMultMatrixf(modelViewF);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3,GL_FLOAT,0,vtx.data());
	glNormalPointer(GL_FLOAT,0,nom.data());
	glColorPointer(4,GL_FLOAT,0,col.data());
	glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	glDisable(GL_LIGHTING);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	{
		glVertexPointer(3,GL_FLOAT,0,wireVtx.data());
		glColorPointer(4,GL_FLOAT,0,wireCol.data());
		glDrawArrays(GL_LINES,0,wireVtx.size()/3);
	}
	{
		float vtx[6]={
			mouse[0].x(),mouse[0].y(),mouse[0].z(),
			mouse[1].x(),mouse[1].y(),mouse[1].z(),
		};
		float col[8]={
			0,1,0,1,
			0,1,0,1,
		};
		glVertexPointer(3,GL_FLOAT,0,vtx);
		glColorPointer(4,GL_FLOAT,0,col);
		glDrawArrays(GL_LINES,0,2);
	}
	{
		float vtx[6];
		float col[8];

		int n=0;
		for(int i=0; i<2; ++i)
		{
			if(nullptr!=edVtHd[i])
			{
				auto vtPos=mesh.GetVertexPosition(edVtHd[i]);
				vtx[n*3  ]=vtPos.xf();
				vtx[n*3+1]=vtPos.yf();
				vtx[n*3+2]=vtPos.zf();
				col[n*4  ]=1;
				col[n*4+1]=0;
				col[n*4+2]=0;
				col[n*4+3]=1;
				++n;
			}
		}

		glVertexPointer(3,GL_FLOAT,0,vtx);
		glColorPointer(4,GL_FLOAT,0,col);
		glPointSize(8);
		glDrawArrays(GL_POINTS,0,n);
		glPointSize(1);
	}
	{
		std::vector <float> vtx;
		std::vector <float> col;
		for(auto vtHd : highlightVtHd)
		{
			auto vtPos=mesh.GetVertexPosition(vtHd);
			vtx.push_back(vtPos.xf());
			vtx.push_back(vtPos.yf());
			vtx.push_back(vtPos.zf());
			col.push_back(0);
			col.push_back(1);
			col.push_back(1);
			col.push_back(1);
		}
		glVertexPointer(3,GL_FLOAT,0,vtx.data());
		glColorPointer(4,GL_FLOAT,0,col.data());
		glPointSize(8);
		glDrawArrays(GL_POINTS,0,highlightVtHd.size());
		glPointSize(1);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);


	FsSwapBuffers();

	needRedraw=false;
}
/* virtual */ bool FsLazyWindowApplication::UserWantToCloseProgram(void)
{
	return true; // Returning true will just close the program.
}
/* virtual */ bool FsLazyWindowApplication::MustTerminate(void) const
{
	return FsLazyWindowApplicationBase::MustTerminate();
}
/* virtual */ long long int FsLazyWindowApplication::GetMinimumSleepPerInterval(void) const
{
	return 10;
}
/* virtual */ void FsLazyWindowApplication::BeforeTerminate(void)
{
}
/* virtual */ bool FsLazyWindowApplication::NeedRedraw(void) const
{
	return needRedraw;
}


static FsLazyWindowApplication *appPtr=nullptr;

/* static */ FsLazyWindowApplicationBase *FsLazyWindowApplicationBase::GetApplication(void)
{
	if(nullptr==appPtr)
	{
		appPtr=new FsLazyWindowApplication;
	}
	return appPtr;
}
