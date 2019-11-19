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

#include <fslazywindow.h>
#include "ysclass.h"

#include "ysshellext.h"
#include "glutil.h"



class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	double angle=0.0;

	YsVec3 mouse[2];
	YsVec3 highlightVtPos;
	std::vector <YsShellExt::VertexHandle> highlightVtHd;

	int mode;
	std::vector <float> dualVtx,dualCol;

	// High-dihedral-angle edges.
	std::vector <float> highDhaVtx,highDhaCol;

	// Path vertex arrays
	std::vector <float> pathVtx,pathCol;

	YsShellExt::VertexHandle edVtHd[2];

	YsVec3 viewTarget;
	YsMatrix4x4 viewRot;
	double viewDistance;
	double nearZ,farZ;

	YsMatrix4x4 projection,modelView;

public:
	class CubeVertexArray
	{
	public:
		std::vector <float> vtx;
		std::vector <float> col;
		std::vector <float> nom;
	};
	CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2);

	YsShellExt mesh;
	std::vector <float> vtx,nom,col;

	YsShellExt::PolygonHandle PickedPlHd(int mx,int my) const;
	YsShellExt::VertexHandle PickedVtHd(int mx,int my) const; 
	std::vector <YsShellExt::PolygonHandle> FindNNeigbor(YsShellExt::PolygonHandle plHd0,int nNei) const;
	std::vector <YsShellExt::VertexHandle> FindWithinRadius(YsShellExt::VertexHandle vtHd0,double dist) const;


	void RemakeVertexArray(void);
	void SetUpHeadLight(void);
	void ColorMap(YsShellExt &mesh);
	void MakeHighDihedralAngleEdgeVertexArray(double dhaThr);

	void FindMinMaxVertex(YsShellExt::VertexHandle vtHd[2]) const;
	std::vector <YsShellExt::VertexHandle> GreedyPath(const YsShellExt::VertexHandle vtHd[2]) const;
	void MakePathVertexArray(const std::vector <YsShellExt::VertexHandle> &path);

	void FloodFill(YsShellExt::PolygonHandle plHd0);

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


FsLazyWindowApplication::CubeVertexArray FsLazyWindowApplication::MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2)
{
	CubeVertexArray vtxArray;
	auto &vtx=vtxArray.vtx;
	auto &col=vtxArray.col;
	auto &nom=vtxArray.nom;

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	nom.push_back(0);nom.push_back(0);nom.push_back(-1);
	nom.push_back(0);nom.push_back(0);nom.push_back(-1);
	nom.push_back(0);nom.push_back(0);nom.push_back(-1);
	nom.push_back(0);nom.push_back(0);nom.push_back(-1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	nom.push_back(0);nom.push_back(0);nom.push_back(1);
	nom.push_back(0);nom.push_back(0);nom.push_back(1);
	nom.push_back(0);nom.push_back(0);nom.push_back(1);
	nom.push_back(0);nom.push_back(0);nom.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	nom.push_back(0);nom.push_back(-1);nom.push_back(0);
	nom.push_back(0);nom.push_back(-1);nom.push_back(0);
	nom.push_back(0);nom.push_back(-1);nom.push_back(0);
	nom.push_back(0);nom.push_back(-1);nom.push_back(0);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
                                                         
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	nom.push_back(0);nom.push_back(1);nom.push_back(0);
	nom.push_back(0);nom.push_back(1);nom.push_back(0);
	nom.push_back(0);nom.push_back(1);nom.push_back(0);
	nom.push_back(0);nom.push_back(1);nom.push_back(0);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	nom.push_back(-1);nom.push_back(0);nom.push_back(0);
	nom.push_back(-1);nom.push_back(0);nom.push_back(0);
	nom.push_back(-1);nom.push_back(0);nom.push_back(0);
	nom.push_back(-1);nom.push_back(0);nom.push_back(0);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
                                                         
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	nom.push_back(1);nom.push_back(0);nom.push_back(0);
	nom.push_back(1);nom.push_back(0);nom.push_back(0);
	nom.push_back(1);nom.push_back(0);nom.push_back(0);
	nom.push_back(1);nom.push_back(0);nom.push_back(0);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	return vtxArray;
}

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

std::vector <YsShellExt::PolygonHandle> FsLazyWindowApplication::FindNNeigbor(YsShellExt::PolygonHandle plHd0,int nNei) const
{
	std::vector <YsShellExt::PolygonHandle> todo;
	std::vector <int> todoN;
	std::unordered_set <unsigned int> visited;

	todo.push_back(plHd0);
	todoN.push_back(0);
	visited.insert(mesh.GetSearchKey(plHd0));
	for(int i=0; i<todo.size(); ++i)
	{
		auto plHd=todo[i];
		auto N=todoN[i];

		if(N<nNei)
		{
			auto plVtHd=mesh.GetPolygonVertex(plHd);
			for(auto edIdx=0; edIdx<plVtHd.size(); ++edIdx)
			{
				auto neiPlHd=mesh.GetNeighborPolygon(plHd,edIdx);
				if(visited.end()==visited.find(mesh.GetSearchKey(neiPlHd)))
				{
					todo.push_back(neiPlHd);
					todoN.push_back(N+1);
					visited.insert(mesh.GetSearchKey(neiPlHd));
				}
			}
		}
	}

	return todo;
}

std::vector <YsShellExt::VertexHandle> FsLazyWindowApplication::FindWithinRadius(YsShellExt::VertexHandle vtHd0,double dist) const
{
	std::vector <YsShellExt::VertexHandle> todo;
	std::unordered_set <unsigned int> visited;

	auto vtPos0=mesh.GetVertexPosition(vtHd0);

	todo.push_back(vtHd0);
	visited.insert(mesh.GetSearchKey(vtHd0));
	for(int i=0; i<todo.size(); ++i)
	{
		for(auto neiVtHd : mesh.GetConnectedVertex(todo[i]))
		{
			if(visited.end()==visited.find(mesh.GetSearchKey(neiVtHd)) &&
			   (mesh.GetVertexPosition(neiVtHd)-vtPos0).GetLength()<dist)
			{
				todo.push_back(neiVtHd);
				visited.insert(mesh.GetSearchKey(neiVtHd));
			}
		}
	}

	return todo;
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
}

void FsLazyWindowApplication::SetUpHeadLight(void)
{
	float lightParam[4]={0,1/(float)sqrt(2.0),1/(float)sqrt(2.0),0};

	glLightfv(GL_LIGHT0,GL_POSITION,lightParam);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void FsLazyWindowApplication::ColorMap(YsShellExt &mesh)
{
	YsColor table[16];
	for(int level=0; level<2; ++level)
	{
		for(int rgb=0; rgb<8; ++rgb)
		{
			int r= rgb%2;
			int g=(rgb/2)%2;
			int b=(rgb/4)%2;

			if(0==level)
			{
				r*=255;
				g*=255;
				b*=255;
			}
			else
			{
				r*=128;
				g*=128;
				b*=128;
			}
			table[level*8+rgb].SetIntRGB(r,g,b);
		}
	}

	for(auto plHd : mesh.AllPolygon())
	{
		mesh.SetPolygonColor(plHd,table[0]);
	}

	for(auto plHd : mesh.AllPolygon())
	{
		bool used[16];
		for(auto &u : used)
		{
			u=false;
		}

		int nNei=mesh.GetPolygonNumVertex(plHd);
		for(int neiIdx=0; neiIdx<nNei; ++neiIdx)
		{
			auto neiPlHd=mesh.GetNeighborPolygon(plHd,neiIdx);
			if(nullptr!=neiPlHd)
			{
				auto neiCol=mesh.GetColor(neiPlHd);
				for(auto i=0; i<16; ++i)
				{
					if(neiCol==table[i])
					{
						used[i]=true;
						break;
					}
				}
			}
		}

		for(int i=0; i<16; ++i)
		{
			if(true!=used[i])
			{
				mesh.SetPolygonColor(plHd,table[i]);
				break;
			}
		}
	}
}

void FsLazyWindowApplication::MakeHighDihedralAngleEdgeVertexArray(double dhaThr)
{
	for(auto plHd : mesh.AllPolygon())
	{
		auto nom=mesh.GetNormal(plHd);
		auto plVtHd=mesh.GetPolygonVertex(plHd);
		for(int edgIdx=0; edgIdx<mesh.GetPolygonNumVertex(plHd); ++edgIdx)
		{
			auto neiPlHd=mesh.GetNeighborPolygon(plHd,edgIdx);
			if(nullptr!=neiPlHd)
			{
				auto neiNom=mesh.GetNormal(neiPlHd);
				if(neiNom*nom<cos(dhaThr))
				{
					YsVec3 vtPos[2]=
					{
						mesh.GetVertexPosition(plVtHd[edgIdx]),
						mesh.GetVertexPosition(plVtHd[(edgIdx+1)%plVtHd.size()])
					};
					highDhaVtx.push_back(vtPos[0].xf());
					highDhaVtx.push_back(vtPos[0].yf());
					highDhaVtx.push_back(vtPos[0].zf());
					highDhaVtx.push_back(vtPos[1].xf());
					highDhaVtx.push_back(vtPos[1].yf());
					highDhaVtx.push_back(vtPos[1].zf());

					highDhaCol.push_back(0);
					highDhaCol.push_back(1);
					highDhaCol.push_back(0);
					highDhaCol.push_back(1);
					highDhaCol.push_back(0);
					highDhaCol.push_back(1);
					highDhaCol.push_back(0);
					highDhaCol.push_back(1);
				}
			}
		}
	}
}

void FsLazyWindowApplication::FindMinMaxVertex(YsShellExt::VertexHandle vtHd[2]) const
{
	vtHd[0]=nullptr;
	vtHd[1]=nullptr;

	for(auto hd : mesh.AllVertex())
	{
		auto vtPos=mesh.GetVertexPosition(hd);
		if(nullptr==vtHd[0] || vtPos.x()<mesh.GetVertexPosition(vtHd[0]).x())
		{
			vtHd[0]=hd;
		}
		if(nullptr==vtHd[1] || mesh.GetVertexPosition(vtHd[1]).x()<vtPos.x())
		{
			vtHd[1]=hd;
		}
	}
}
std::vector <YsShellExt::VertexHandle> FsLazyWindowApplication::GreedyPath(const YsShellExt::VertexHandle vtHd[2]) const
{
	std::vector <YsShellExt::VertexHandle> path;

	path.push_back(vtHd[0]);

	auto goalPos=mesh.GetVertexPosition(vtHd[1]);

	YsShellExt::VertexHandle curVtHd=vtHd[0];
	while(curVtHd!=vtHd[1])
	{
		YsShellExt::VertexHandle nextVtHd=nullptr;

		auto curDist=(goalPos-mesh.GetVertexPosition(curVtHd)).GetLength();
		for(auto neiVtHd : mesh.GetConnectedVertex(curVtHd))
		{
			auto dist=(goalPos-mesh.GetVertexPosition(neiVtHd)).GetLength();
			if(dist<curDist)
			{
				nextVtHd=neiVtHd;
				curDist=dist;
			}
		}

		if(nullptr!=nextVtHd)
		{
			path.push_back(nextVtHd);
			curVtHd=nextVtHd;
		}
		else
		{
			break;
		}
	}

	return path;
}
void FsLazyWindowApplication::MakePathVertexArray(const std::vector <YsShellExt::VertexHandle> &path)
{
	pathVtx.clear();
	pathCol.clear();

	for(auto vtHd : path)
	{
		auto vtPos=mesh.GetVertexPosition(vtHd);
		pathVtx.push_back(vtPos.xf());
		pathVtx.push_back(vtPos.yf());
		pathVtx.push_back(vtPos.zf());
		pathCol.push_back(0);
		pathCol.push_back(1);
		pathCol.push_back(0);
		pathCol.push_back(1);
	}
}

void FsLazyWindowApplication::FloodFill(YsShellExt::PolygonHandle plHd0)
{
	if(YsRed()==mesh.GetColor(plHd0))
	{
		return;
	}

	std::vector <YsShellExt::PolygonHandle> todo;
	todo.push_back(plHd0);
	mesh.SetPolygonColor(plHd0,YsRed());
	while(0<todo.size())  // true!=todo.empty()
	{
		auto plHd=todo.back();
		todo.pop_back();

		for(int i=0; i<mesh.GetPolygonNumVertex(plHd); ++i)
		{
			auto neiPlHd=mesh.GetNeighborPolygon(plHd,i);
			if(nullptr!=neiPlHd && YsRed()!=mesh.GetColor(neiPlHd))
			{
				todo.push_back(neiPlHd);
				mesh.SetPolygonColor(neiPlHd,YsRed());
			}
		}
	}
}

FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;

	mode=0;

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
		blue.SetIntRGB(0,0,255);
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
	else if(FSKEY_X==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			auto vtPos=mesh.GetVertexPosition(pickedVtHd);
			vtPos.AddX(1.0);
			mesh.SetVertexPosition(pickedVtHd,vtPos);
			RemakeVertexArray();
		}
	}
	else if(FSKEY_Y==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			for(auto plHd : mesh.FindPolygonFromVertex(pickedVtHd))
			{
				mesh.SetPolygonColor(plHd,YsRed());
			}
			RemakeVertexArray();
		}
	}
	else if(FSKEY_C==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			auto connVtHd=mesh.GetConnectedVertex(pickedVtHd);
			// highlightVtHd.insert(highlightVtHd.end(),connVtHd.begin(),connVtHd.end());
			highlightVtHd.clear();
			for(auto vtHd : connVtHd)
			{
				highlightVtHd.push_back(vtHd);
			}
		}
	}
	else if(FSKEY_N==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto plHd=PickedPlHd(mx,my);
		if(mesh.NullPolygon()!=plHd)
		{
			auto plVtHd=mesh.GetPolygonVertex(plHd);
			for(int edIdx=0; edIdx<plVtHd.size(); ++edIdx)
			{
				auto neiPlHd=mesh.GetNeighborPolygon(plHd,edIdx);
				if(mesh.NullPolygon()!=neiPlHd)
				{
					mesh.SetPolygonColor(neiPlHd,YsGreen());
				}
			}
			RemakeVertexArray();
		}
	}
	else if(FSKEY_D==key)
	{
		mode=1-mode;
		dualVtx.clear();
		dualCol.clear();
		for(auto plHd=mesh.FindNextPolygon(nullptr); mesh.NullPolygon()!=plHd; plHd=mesh.FindNextPolygon(plHd))
		{
			auto plVtHd=mesh.GetPolygonVertex(plHd);
			auto cen0=mesh.GetCenter(plHd);
			for(int edIdx=0; edIdx<plVtHd.size(); ++edIdx)
			{
				auto neiPlHd=mesh.GetNeighborPolygon(plHd,edIdx);
				if(mesh.NullPolygon()!=neiPlHd &&
				   mesh.GetSearchKey(plHd)<mesh.GetSearchKey(neiPlHd))
				{
					auto cen1=mesh.GetCenter(neiPlHd);

					dualVtx.push_back(cen0.xf());
					dualVtx.push_back(cen0.yf());
					dualVtx.push_back(cen0.zf());
					dualVtx.push_back(cen1.xf());
					dualVtx.push_back(cen1.yf());
					dualVtx.push_back(cen1.zf());

					dualCol.push_back(0);
					dualCol.push_back(0);
					dualCol.push_back(0);
					dualCol.push_back(1);
					dualCol.push_back(0);
					dualCol.push_back(0);
					dualCol.push_back(0);
					dualCol.push_back(1);
				}
			}
		}
	}
	else if(FSKEY_A==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto plHd=PickedPlHd(mx,my);
		if(mesh.NullPolygon()!=plHd)
		{
			for(auto plHd : FindNNeigbor(plHd,3))
			{
				mesh.SetPolygonColor(plHd,YsCyan());
			}
			RemakeVertexArray();
		}
	}
	else if(FSKEY_B==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			highlightVtHd=FindWithinRadius(pickedVtHd,2.0);
		}
	}
	else if(FSKEY_4==key)
	{
		ColorMap(mesh);
		RemakeVertexArray();
	}
	else if(FSKEY_H==key)
	{
		MakeHighDihedralAngleEdgeVertexArray(YsPi/3.0);
	}
	else if(FSKEY_G==key)
	{
		YsShellExt::VertexHandle vtHd[2];
		FindMinMaxVertex(vtHd);
		if(nullptr!=vtHd[0] && nullptr!=vtHd[1])
		{
			MakePathVertexArray(GreedyPath(vtHd));
		}
	}
	else if(FSKEY_F==key)
	{
		int lb,mb,rb,mx,my;
		FsGetMouseState(lb,mb,rb,mx,my);

		auto plHd=PickedPlHd(mx,my);
		if(nullptr!=plHd)
		{
			FloodFill(plHd);
			RemakeVertexArray();
		}
	}

	if(0!=FsGetKeyState(FSKEY_LEFT))
	{
		viewRot.RotateXZ(YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_RIGHT))
	{
		viewRot.RotateXZ(-YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_UP))
	{
		viewRot.RotateYZ(YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_DOWN))
	{
		viewRot.RotateYZ(-YsPi/60.0);
	}


	int winWid,winHei;
	FsGetWindowSize(winWid,winHei);

	int lb,mb,rb,mx,my;
	auto evt=FsGetMouseEvent(lb,mb,rb,mx,my);
	if(FSMOUSEEVENT_LBUTTONDOWN==evt)
	{
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

		auto pickedPlHd=PickedPlHd(mx,my);
		if(mesh.NullPolygon()!=pickedPlHd)
		{
			mesh.SetPolygonColor(pickedPlHd,YsRed());
			RemakeVertexArray();
		}

		/*
		auto pickedVtHd=PickedVtHd(mx,my);
		if(mesh.NullVertex()!=pickedVtHd)
		{
			highlightVtPos=mesh.GetVertexPosition(pickedVtHd);
		}

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

	if(0==mode)
	{
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
	}
	else
	{
		glDisable(GL_LIGHTING);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3,GL_FLOAT,0,dualVtx.data());
		glColorPointer(4,GL_FLOAT,0,dualCol.data());
		glDrawArrays(GL_LINES,0,dualVtx.size()/3);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}



	glDisable(GL_LIGHTING);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

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
		float vtx[3]={
			highlightVtPos.x(),highlightVtPos.y(),highlightVtPos.z(),
		};
		float col[4]={
			0,1,0,1,
		};
		glVertexPointer(3,GL_FLOAT,0,vtx);
		glColorPointer(4,GL_FLOAT,0,col);
		glPointSize(8);
		glDrawArrays(GL_POINTS,0,1);
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
	{
		glVertexPointer(3,GL_FLOAT,0,highDhaVtx.data());
		glColorPointer(4,GL_FLOAT,0,highDhaCol.data());
		glLineWidth(4);
		glDrawArrays(GL_LINES,0,highDhaVtx.size()/3);
		glPointSize(1);
	}
	{
		glVertexPointer(3,GL_FLOAT,0,pathVtx.data());
		glColorPointer(4,GL_FLOAT,0,pathCol.data());
		glLineWidth(4);
		glDrawArrays(GL_LINE_STRIP,0,pathVtx.size()/3);
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
