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
#include <stdio.h>
#include <math.h>



const double YsPi=3.1415927;

void DrawCube(double x0,double y0,double z0,double x1,double y1,double z1)
{
	glBegin(GL_QUADS);

	glColor3ub(255,0,0);
	glVertex3d(x0,y0,z0);
	glVertex3d(x1,y0,z0);
	glVertex3d(x1,y1,z0);
	glVertex3d(x0,y1,z0);

	glVertex3d(x0,y0,z1);
	glVertex3d(x1,y0,z1);
	glVertex3d(x1,y1,z1);
	glVertex3d(x0,y1,z1);

	glColor3ub(0,255,0);
	glVertex3d(x0,y0,z0);
	glVertex3d(x1,y0,z0);
	glVertex3d(x1,y0,z1);
	glVertex3d(x0,y0,z1);
                      
	glVertex3d(x0,y1,z0);
	glVertex3d(x1,y1,z0);
	glVertex3d(x1,y1,z1);
	glVertex3d(x0,y1,z1);

	glColor3ub(0,0,255);
	glVertex3d(x0,y0,z0);
	glVertex3d(x0,y1,z0);
	glVertex3d(x0,y1,z1);
	glVertex3d(x0,y0,z1);
                      
	glVertex3d(x1,y0,z0);
	glVertex3d(x1,y1,z0);
	glVertex3d(x1,y1,z1);
	glVertex3d(x1,y0,z1);

	glEnd();
}

void DrawFloor(double x0,double z0,double x1,double z1,double y0,int r,int g,int b)
{
	glColor3ub(r,g,b);

	glBegin(GL_QUADS);

	glVertex3d(x0,y0,z0);
	glVertex3d(x1,y0,z0);
	glVertex3d(x1,y0,z1);
	glVertex3d(x0,y0,z1);

	glEnd();
}

void DrawMaze(int nx,int nz,const char wall[],double d)
{
	for(int z=0; z<nz; ++z)
	{
		for(int x=0; x<nx; ++x)
		{
			auto c=wall[z*nx+x];
			double x0=(double)x*d;
			double y0=0.0;
			double z0=(double)z*d;
			double x1=(double)x*d+d;
			double y1=d;
			double z1=(double)z*d+d;

			if('X'==c)
			{
				DrawCube(x0,y0,z0,x1,y1,z1);
			}
			else if('G'==c)
			{
				DrawFloor(x0,z0,x1,z1,y0,255,255,0);
			}
			else if('S'==c)
			{
				DrawFloor(x0,z0,x1,z1,y0,0,255,255);
			}
		}
	}
}

void ResetViewPoint(double &xx,double &zz,int nx,int nz,const char wall[],double d)
{
	for(int z=0; z<nz; ++z)
	{
		for(int x=0; x<nx; ++x)
		{
			auto c=wall[z*nx+x];
			if('S'==c)
			{
				xx=(double)x*d+d/2.0;
				zz=(double)z*d+d/2.0;
			}
		}
	}
}

int GetBlock(int nx,int nz,const char wall[],double d,double x,double z)
{
	const int bx=(int)(x/d);
	const int bz=(int)(z/d);
	if(0<=bx && bx<nx && 0<=bz && bz<nz)
	{
		return wall[bz*nx+bx];
	}
	return 0;
}

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	bool terminate=false;

	double x,y,z,h;
	double t=0.0;

	enum
	{
		NX=16,
		NZ=16
	};
	char wall[NX*NZ+1]=
	{
	//   0123456789ABCDEF
		"XXXXXXXXXXXXXXXX"  //0
		"X       X     GX"  //1
		"X XXXX XXXXX XXX"  //2
		"XXX X          X"  //3
		"X   XX XXXXXXX X"  //4
		"XXX  X XXXX XX X"  //5
		"X X XX       X X"  //6
		"X X  X XXXX XX X"  //7
		"X X XX XXXX XXXX"  //8
		"X X  X X     X X"  //9
		"X   XX X XXXXX X"  //a
		"XXX  X X       X"  //b
		"X X XX XXXXXXXXX"  //c
		"X X  X XX X XX X"  //d
		"XS             X"  //e
		"XXXXXXXXXXXXXXXX"  //f
	};

	const double speed=6.0;
	const double rotSpeed=YsPi;
	const double blockDim=3.0;


public:
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

FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{
}
/* virtual */ void FsLazyWindowApplication::GetOpenWindowOption(FsOpenWindowOption &opt) const
{
	opt.x0=0;
	opt.y0=0;
	opt.wid=800;
	opt.hei=600;
}
/* virtual */ void FsLazyWindowApplication::Initialize(int argc,char *argv[])
{
	x=0;
	y=1.5;
	z=10.0;
	h=0;
	ResetViewPoint(x,z,NX,NZ,wall,blockDim);
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}


	FsPollDevice();

	auto ms=FsPassedTime();
	auto dt=(double)ms/1000.0;
	t+=dt;

	if(FSKEY_ESC==key)
	{
		terminate=true;
	}

	if(0!=FsGetKeyState(FSKEY_SPACE))
	{
		if(y<8.0)
		{
			y+=0.1;
		}
	}
	else
	{
		if(y>1.5)
		{
			y-=0.1;
		}
		if(y<1.5)
		{
			y=1.5;
		}
	}


	const double vx=-sin(h);
	const double vz=-cos(h);

	const double prevX=x;
	const double prevZ=z;

	if(0!=FsGetKeyState(FSKEY_UP))
	{
		x+=speed*vx*dt;
		z+=speed*vz*dt;
	}
	if(0!=FsGetKeyState(FSKEY_DOWN))
	{
		x-=speed*vx*dt;
		z-=speed*vz*dt;
	}
	if(0!=FsGetKeyState(FSKEY_LEFT))
	{
		h+=dt*rotSpeed;
	}
	if(0!=FsGetKeyState(FSKEY_RIGHT))
	{
		h-=dt*rotSpeed;
	}

	if('X'==GetBlock(NX,NZ,wall,blockDim,x,z) ||
	   'X'==GetBlock(NX,NZ,wall,blockDim,x+blockDim/10.0,z) ||
	   'X'==GetBlock(NX,NZ,wall,blockDim,x-blockDim/10.0,z))
	{
		x=prevX;
	}
	if('X'==GetBlock(NX,NZ,wall,blockDim,x,z) ||
	   'X'==GetBlock(NX,NZ,wall,blockDim,x       ,z+blockDim/10.0) ||
	   'X'==GetBlock(NX,NZ,wall,blockDim,x       ,z-blockDim/10.0))
	{
		z=prevZ;
	}

	if('G'==GetBlock(NX,NZ,wall,blockDim,x,z))
	{
		printf("Goal!\n");
		terminate=true;
	}



	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	int wid,hei;
	FsGetWindowSize(wid,hei);

	glEnable(GL_DEPTH_TEST);

	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(double)wid/(double)hei,0.1,40.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotated(-h*180.0/YsPi,0,1,0);
	glTranslated(-x,-y,-z);

	DrawMaze(NX,NZ,wall,blockDim);

	FsSwapBuffers();


	needRedraw=false;
}
/* virtual */ bool FsLazyWindowApplication::UserWantToCloseProgram(void)
{
	return true; // Returning true will just close the program.
}
/* virtual */ bool FsLazyWindowApplication::MustTerminate(void) const
{
	return terminate;
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
