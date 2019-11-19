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
#include "ysglfontdata.h"


class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	std::vector <std::string> text;


	unsigned int attribVertexPos;
	unsigned int vtxShaderIdent;
	unsigned int fragShaderIdent;
	unsigned int progIdent;

public:
	static std::string ReadText(const char fName[]);

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

/* static */ std::string FsLazyWindowApplication::ReadText(const char fName[])
{
	std::string s;
	char str[256];
	FILE *fp=fopen(fName,"r");
	if(nullptr!=fp)
	{
		while(nullptr!=fgets(str,255,fp))
		{
			for(int i=0; 0!=str[i]; ++i)
			{
				s.push_back(str[i]);
			}
		}
		fclose(fp);
	}
	else
	{
		fprintf(stderr,"Load error %s\n",fName);
	}
	return s;
}

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
	FsChangeToProgramDir();


	auto passVtx=ReadText("pass_vertex.glsl");
	auto passFrag=ReadText("pass_fragment.glsl");

	vtxShaderIdent=glCreateShader(GL_VERTEX_SHADER);
	fragShaderIdent=glCreateShader(GL_FRAGMENT_SHADER);
	progIdent=glCreateProgram();

	const char *vtxShaderSource=passVtx.data();
	const char *fragShaderSource=passFrag.data();

	glShaderSource(vtxShaderIdent,1,&vtxShaderSource,nullptr);
	glShaderSource(fragShaderIdent,1,&fragShaderSource,nullptr);

	int compileStat=99999,infoLength=0,errMsgLen=0;
	char errMsg[1024];
	glCompileShader(vtxShaderIdent);
	glGetShaderiv(vtxShaderIdent,GL_COMPILE_STATUS,&compileStat);
	glGetShaderiv(vtxShaderIdent,GL_INFO_LOG_LENGTH,&infoLength);
	glGetShaderInfoLog(vtxShaderIdent,1024-1,&errMsgLen,errMsg);
	printf("%s\n",errMsg);

	glCompileShader(fragShaderIdent);
	glGetShaderiv(fragShaderIdent,GL_COMPILE_STATUS,&compileStat);
	glGetShaderiv(fragShaderIdent,GL_INFO_LOG_LENGTH,&infoLength);
	glGetShaderInfoLog(fragShaderIdent,1024-1,&errMsgLen,errMsg);
	printf("%s\n",errMsg);


	int linkStat;
	glAttachShader(progIdent,vtxShaderIdent);
	glAttachShader(progIdent,fragShaderIdent);
	glLinkProgram(progIdent);
	glGetProgramiv(progIdent,GL_LINK_STATUS,&linkStat);
	glGetProgramInfoLog(progIdent,1023,&errMsgLen,errMsg);
	printf("[%d] %s\n",linkStat,errMsg);


	attribVertexPos=glGetAttribLocation(progIdent,"vertex");


	printf("%s\n",passVtx.c_str());
	printf("%s\n",passFrag.c_str());


	FILE *fp=fopen("sampletext.txt","r");
	if(nullptr!=fp)
	{
		char str[256];
		while(nullptr!=fgets(str,255,fp))
		{
			text.push_back(str);
		}
		fclose(fp);
	}
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}
	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glUseProgram(progIdent);

	const float vtx[12]=
	{
		 0, 0,0,
		 1, 0,0,
		 1, 1,0,
		 0, 1,0,
	};
	glEnableVertexAttribArray(attribVertexPos);
	glVertexAttribPointer(attribVertexPos,3,GL_FLOAT,GL_FALSE,0,vtx);
	glDrawArrays(GL_TRIANGLE_FAN,0,4);
	glDisableVertexAttribArray(attribVertexPos);

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
