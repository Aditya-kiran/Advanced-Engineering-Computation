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

#include <fslazywindow.h>
#include "ysclass.h"



class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	double angle=0.0;

	YsVec3 viewTarget;
	YsMatrix4x4 viewRot;
	double viewDistance;

public:
	class CubeVertexArray
	{
	public:
		std::vector <float> vtx;
		std::vector <float> col;
	};
	CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2);

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


FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;

	viewTarget=YsVec3::Origin();
	viewDistance=5.0;
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

	if(0!=FsGetKeyState(FSKEY_LEFT))
	{
		viewRot.RotateXZ(YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_RIGHT))
	{
		viewRot.RotateXZ(+YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_UP))
	{
		viewRot.RotateYZ(YsPi/60.0);
	}
	if(0!=FsGetKeyState(FSKEY_DOWN))
	{
		viewRot.RotateYZ(-YsPi/60.0);
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
	gluPerspective(45.0,aspect,0.1,20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	YsMatrix4x4 modelView;

	modelView.Translate(0,0,-viewDistance);
	modelView*=viewRot;
	modelView.Translate(-viewTarget);

	float modelViewF[16];
	modelView.GetOpenGlCompatibleMatrix(modelViewF);
	glMultMatrixf(modelViewF);

	auto vtxArray=MakeCubeVertexArray(-1,-1,-1,1,1,1);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
	glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
	glDrawArrays(GL_QUADS,0,24);

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
