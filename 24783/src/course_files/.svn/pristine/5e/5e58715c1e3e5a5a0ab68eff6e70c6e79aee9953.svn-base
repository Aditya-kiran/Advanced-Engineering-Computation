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

#include <vector>
#include <string>

#include <ysgl.h>

#include <fslazywindow.h>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#include <ysshellext.h>

#include "ysglfontdata.h"
#include "glutil.h"


#include "renderer.h"

#include "checker.h"

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	std::vector <std::string> text;

	unsigned int textureIdent;

	PassThroughRenderer passThrough;
	ColorByWindowCoordRenderer colorByWindowCoord;
	Sampler2dRenderer sampler2d;
	Plain3dRenderer plain3d;
	Rainbow3dRenderer rainbow3d;
	Shaded3dRenderer shaded3d;
	PointSprite3dRenderer pointSprite3d;


	YsShellExt mesh;
	std::vector <float> vtx,nom,col;


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
	};
	CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2);

	void RemakeVertexArray(void);

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

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
	col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
                                                         
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
	col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);

	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
                                                         
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
	vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
	vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
	col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);

	return vtxArray;
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

FsLazyWindowApplication::FsLazyWindowApplication()
{
	viewTarget=YsVec3::Origin();
	viewDistance=5.0;
	nearZ=0.1;
	farZ=100.0;

	needRedraw=false;
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
	FsChangeToProgramDir();

	if(true!=passThrough.Compile("pass_vertex.glsl","pass_fragment.glsl") ||
	   true!=colorByWindowCoord.Compile("color_by_windowcoord_vertex.glsl","color_by_windowcoord_fragment.glsl") ||
	   true!=sampler2d.Compile("sampler2d_vertex.glsl","sampler2d_fragment.glsl") ||
	   true!=plain3d.Compile("plain3d_vertex.glsl","plain3d_fragment.glsl") ||
	   true!=rainbow3d.Compile("rainbow3d_vertex.glsl","rainbow3d_fragment.glsl") ||
	   true!=shaded3d.Compile("phong3d_vertex.glsl","phong3d_fragment.glsl") ||
	   // true!=shaded3d.Compile("gouraud3d_vertex.glsl","gouraud3d_fragment.glsl") ||
	   true!=pointSprite3d.Compile("pointSprite_vertex.glsl","pointSprite_fragment.glsl")
	 )
	{
		fprintf(stderr,"Failed to compile a shader.\n");
		exit(1);
	}

	glGenTextures(1,&textureIdent);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,textureIdent);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,
								checker_pattern_wid,checker_pattern_hei,
								0,GL_RGBA,GL_UNSIGNED_BYTE,checker_pattern);


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

	if(0!=FsGetKeyState(FSKEY_LEFT))
	{
		YsMatrix4x4 tfm;
		tfm.RotateXZ(YsPi/60.0);
		viewRot=tfm*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_RIGHT))
	{
		YsMatrix4x4 tfm;
		tfm.RotateXZ(-YsPi/60.0);
		viewRot=tfm*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_UP))
	{
		YsMatrix4x4 tfm;
		tfm.RotateYZ(YsPi/60.0);
		viewRot=tfm*viewRot;
	}
	if(0!=FsGetKeyState(FSKEY_DOWN))
	{
		YsMatrix4x4 tfm;
		tfm.RotateYZ(-YsPi/60.0);
		viewRot=tfm*viewRot;
	}

	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_POINT_SPRITE);

	glUseProgram(plain3d.progIdent);


	int wid,hei;
	FsGetWindowSize(wid,hei);
	float aspect=(float)wid/(float)hei;

	projection=MakePerspective(45.0,aspect,nearZ,farZ);

	float projectionF[16];
	projection.GetOpenGlCompatibleMatrix(projectionF);
	glUniformMatrix4fv(plain3d.uniformProjectionPos,1,GL_FALSE,projectionF);


	auto cubeVtx=MakeCubeVertexArray(-1.0,-1.0,-1.0,1.0,1.0,1.0);

	modelView.LoadIdentity();
	modelView.Translate(0,0,-viewDistance);
	modelView*=viewRot;
	modelView.Translate(-viewTarget);

	float modelViewF[16];
	modelView.GetOpenGlCompatibleMatrix(modelViewF);
	glUniformMatrix4fv(plain3d.uniformModelViewPos,1,GL_FALSE,modelViewF);


	glEnableVertexAttribArray(plain3d.attribVtxPos);
	glEnableVertexAttribArray(plain3d.attribColorPos);

	glVertexAttribPointer(plain3d.attribVtxPos,3,GL_FLOAT,GL_FALSE,0,cubeVtx.vtx.data());
	glVertexAttribPointer(plain3d.attribColorPos,4,GL_FLOAT,GL_FALSE,0,cubeVtx.col.data());
	glDrawArrays(GL_QUADS,0,cubeVtx.vtx.size()/3);

	glDisableVertexAttribArray(plain3d.attribVtxPos);
	glDisableVertexAttribArray(plain3d.attribColorPos);


	{
		glUseProgram(pointSprite3d.progIdent);

		glUniformMatrix4fv(pointSprite3d.uniformProjectionPos,1,GL_FALSE,projectionF);
		glUniformMatrix4fv(pointSprite3d.uniformModelViewPos,1,GL_FALSE,modelViewF);
		glUniform1f(pointSprite3d.uniformSizeInPixelPos,0);
		glUniform1f(pointSprite3d.uniformSizeIn3dPos,1);
		glUniform1f(pointSprite3d.uniformWindowHeightPos,(float)hei);

		glEnableVertexAttribArray(pointSprite3d.attribVtxPos);
		glEnableVertexAttribArray(pointSprite3d.attribColorPos);
		glEnableVertexAttribArray(pointSprite3d.attribPointSizePos);

		const float pointVtx[24]=
		{
			-2.0,-2.0,-2.0,
			 2.0,-2.0,-2.0,
			-2.0, 2.0,-2.0,
			 2.0, 2.0,-2.0,
			-2.0,-2.0, 2.0,
			 2.0,-2.0, 2.0,
			-2.0, 2.0, 2.0,
			 2.0, 2.0, 2.0,
		};
		const float pointCol[32]=
		{
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
			0,0,1,1,
		};
		const float pointSize[8]=
		{
			1.0f,
			1.0f,
			1.0f,
			1.0f,
			1.0f,
			1.0f,
			1.0f,
			1.0f,
		};

		glVertexAttribPointer(pointSprite3d.attribVtxPos,3,GL_FLOAT,GL_FALSE,0,pointVtx);
		glVertexAttribPointer(pointSprite3d.attribColorPos,4,GL_FLOAT,GL_FALSE,0,pointCol);
		glVertexAttribPointer(pointSprite3d.attribPointSizePos,1,GL_FLOAT,GL_FALSE,0,pointSize);
		glDrawArrays(GL_POINTS,0,8);
		glDisableVertexAttribArray(pointSprite3d.attribVtxPos);
		glDisableVertexAttribArray(pointSprite3d.attribColorPos);
		glDisableVertexAttribArray(pointSprite3d.attribPointSizePos);
	}


	glUseProgram(0);

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
