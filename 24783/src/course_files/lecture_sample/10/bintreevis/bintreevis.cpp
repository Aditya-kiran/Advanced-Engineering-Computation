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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <fslazywindow.h>
#include <ysglfontdata.h>

#include "bintree.h"

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	BinaryTree <int,int> tree;
	BinaryTree <int,int>::NodeHandle highlight;

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

	void DrawBinaryTree(BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1,int prevX,int prevY) const;
	void DrawLabel(BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1) const;

	BinaryTree<int,int>::NodeHandle Pick(int mx,int my) const;
	BinaryTree<int,int>::NodeHandle Pick(int mx,int my,BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1) const;
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
	opt.wid=1200;
	opt.hei=800;
}
/* virtual */ void FsLazyWindowApplication::Initialize(int argc,char *argv[])
{
	srand((int)time(nullptr));

	highlight=tree.Null();
	for(int i=0; i<50; ++i)
	{
		int r=rand()%100;
		printf("Adding: %d, %d\n",r,123*r);
		tree.Insert(r,123*r);
	}
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}

	if(FSKEY_SPACE==key)
	{
		for(auto hd=tree.FindFirst(); hd!=nullptr; )
		{
			auto nextHd=tree.FindNext(hd);
			if(0!=tree.GetKey(hd)%2)
			{
				tree.Delete(hd);
			}
			hd=nextHd;
		}
		printf("After deleting odd keys.\n");
		for(auto hd=tree.FindFirst(); hd!=nullptr; hd=tree.FindNext(hd))
		{
			printf("Sorted: %d\n",tree.GetKey(hd));
		}
	}

	if(FSKEY_DEL==key && highlight!=nullptr)
	{
		tree.Delete(highlight);
		highlight=tree.Null();
	}
	if(FSKEY_INS==key)
	{
		tree.Insert(rand()%100,0);
	}
	if(FSKEY_L==key && highlight!=nullptr)
	{
		if(true==tree.RotateLeft(highlight))
		{
			printf("Rotation successful.\n");
		}
		else
		{
			printf("Rotation failed.\n");
		}
	}


	int lb,mb,rb,mx,my;
	FsGetMouseEvent(lb,mb,rb,mx,my);
	auto hd=Pick(mx,my);
	highlight=hd;
	if(hd!=nullptr)
	{
		//printf("Cursor on: %d\n",tree.GetKey(hd));
	}
	else
	{
		//printf("Cursor not on node.\n");
	}

	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	int wid,hei;
	FsGetWindowSize(wid,hei);

	glViewport(0,0,wid,hei);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

	glBegin(GL_LINES);
	DrawBinaryTree(tree.RootNode(),0,wid,0,40,0,0);
	glEnd();
	DrawLabel(tree.RootNode(),0,wid,0,40);

	FsSwapBuffers();
	needRedraw=false;
}

void FsLazyWindowApplication::DrawBinaryTree(BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1,int prevX,int prevY) const
{
	if(hd!=nullptr)
	{
		int cx=(x0+x1)/2;
		int cy=(y0+y1)/2;

		if(hd!=tree.RootNode())
		{
			glVertex2i(prevX,prevY);
			glVertex2i(cx,cy);
		}

		if(hd==highlight)
		{
			glVertex2i(x0+1,y0+1);
			glVertex2i(x1  ,y0+1);

			glVertex2i(x1  ,y0+1);
			glVertex2i(x1  ,y1);

			glVertex2i(x1  ,y1);
			glVertex2i(x0+1,y1);

			glVertex2i(x0+1,y1);
			glVertex2i(x0+1,y0+1);
		}

		DrawBinaryTree(tree.Left(hd),x0,cx,y0+40,y1+40,cx,cy);
		DrawBinaryTree(tree.Right(hd),cx,x1,y0+40,y1+40,cx,cy);
	}
}

void FsLazyWindowApplication::DrawLabel(BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1) const
{
	if(hd!=nullptr)
	{
		int cx=(x0+x1)/2;
		int cy=(y0+y1)/2;

		char str[32];
		sprintf(str,"%d(%d)",tree.GetKey(hd),tree.GetHeight(hd));
		glRasterPos2i(cx,cy);
		YsGlDrawFontBitmap12x16(str);

		DrawLabel(tree.Left(hd),x0,cx,y0+40,y1+40);
		DrawLabel(tree.Right(hd),cx,x1,y0+40,y1+40);
	}
}

BinaryTree<int,int>::NodeHandle FsLazyWindowApplication::Pick(int mx,int my) const
{
	int wid,hei;
	FsGetWindowSize(wid,hei);
	return Pick(mx,my,tree.RootNode(),0,wid,0,40);
}
BinaryTree<int,int>::NodeHandle FsLazyWindowApplication::Pick(int mx,int my,BinaryTree<int,int>::NodeHandle hd,int x0,int x1,int y0,int y1) const
{
	if(hd!=nullptr)
	{
		if(x0<=mx && mx<x1 && y0<=my && my<y1)
		{
			return hd;
		}

		int cx=(x0+x1)/2;
		int cy=(y0+y1)/2;
		auto fromLeft=Pick(mx,my,tree.Left(hd),x0,cx,y0+40,y1+40);
		if(fromLeft!=nullptr)
		{
			return fromLeft;
		}

		auto fromRight=Pick(mx,my,tree.Right(hd),cx,x1,y0+40,y1+40);
		if(fromRight!=nullptr)
		{
			return fromRight;
		}
	}
	return tree.Null();
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
