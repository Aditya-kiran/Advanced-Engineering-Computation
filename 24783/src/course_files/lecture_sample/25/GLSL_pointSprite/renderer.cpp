#include <stdio.h>
#include <ysgl.h>
#include "renderer.h"



/* static */ std::string RendererBase::ReadTextFile(const char fName[])
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

bool RendererBase::Compile(const char vtxShaderFn[],const char fragShaderFn[])
{
	auto vtxSrc=ReadTextFile(vtxShaderFn);
	auto fragSrc=ReadTextFile(fragShaderFn);
	return Compile(vtxSrc,fragSrc);
}

bool RendererBase::Compile(const std::string &vtxSrc,const std::string &fragSrc)
{
	vtxShaderIdent=glCreateShader(GL_VERTEX_SHADER);
	fragShaderIdent=glCreateShader(GL_FRAGMENT_SHADER);
	progIdent=glCreateProgram();

	const char *vtxShaderSource=vtxSrc.data();
	const char *fragShaderSource=fragSrc.data();

	glShaderSource(vtxShaderIdent,1,&vtxShaderSource,nullptr);
	glShaderSource(fragShaderIdent,1,&fragShaderSource,nullptr);

	if(true!=CompileShader(vtxShaderIdent))
	{
		printf("Error in compiling vertex shader.\n");
		return false;
	}
	if(true!=CompileShader(fragShaderIdent))
	{
		printf("Error in compiling fragment shader.\n");
		return false;
	}
	if(true!=LinkShader())
	{
		printf("Error in linking a GLSL program .\n");
		return false;
	}

	CacheLocation();
	return true;
}

bool RendererBase::CompileShader(int shaderIdent)
{
	int compileStat=99999,infoLength=0,errMsgLen=0;
	char errMsg[1024];

	glCompileShader(shaderIdent);
	glGetShaderiv(shaderIdent,GL_COMPILE_STATUS,&compileStat);
	glGetShaderiv(shaderIdent,GL_INFO_LOG_LENGTH,&infoLength);
	glGetShaderInfoLog(shaderIdent,1024-1,&errMsgLen,errMsg);
	printf("%s\n",errMsg);
	return (GL_TRUE==compileStat);
}

bool RendererBase::LinkShader(void)
{
	int linkStat,infoLength=0,errMsgLen=0;
	char errMsg[1024];

	glAttachShader(progIdent,vtxShaderIdent);
	glAttachShader(progIdent,fragShaderIdent);
	glLinkProgram(progIdent);
	glGetProgramiv(progIdent,GL_LINK_STATUS,&linkStat);
	glGetProgramInfoLog(progIdent,1023,&errMsgLen,errMsg);
	printf("%s\n",errMsg);
	return (GL_TRUE==linkStat);
}

////////////////////////////////////////////////////////////

/* virtual */ void PassThroughRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
}

////////////////////////////////////////////////////////////

/* virtual */ void ColorByWindowCoordRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
}

////////////////////////////////////////////////////////////

/* virtual */ void Sampler2dRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
	attribTexCoordPos=glGetAttribLocation(progIdent,"texCoord");
	uniformTexIdentPos=glGetUniformLocation(progIdent,"texIdent");
}

////////////////////////////////////////////////////////////

/* virtual */ void Plain3dRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
	attribColorPos=glGetAttribLocation(progIdent,"color");
	uniformProjectionPos=glGetUniformLocation(progIdent,"projection");
	uniformModelViewPos=glGetUniformLocation(progIdent,"modelView");
}

////////////////////////////////////////////////////////////

/* virtual */ void Rainbow3dRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
	uniformProjectionPos=glGetUniformLocation(progIdent,"projection");
	uniformModelViewPos=glGetUniformLocation(progIdent,"modelView");
}

////////////////////////////////////////////////////////////

/* virtual */ void Shaded3dRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
	attribColorPos=glGetAttribLocation(progIdent,"color");
	attribNormalPos=glGetAttribLocation(progIdent,"normal");

	uniformProjectionPos=glGetUniformLocation(progIdent,"projection");
	uniformModelViewPos=glGetUniformLocation(progIdent,"modelView");
	uniformLightDirPos=glGetUniformLocation(progIdent,"lightDir");
	uniformAmbientPos=glGetUniformLocation(progIdent,"ambient");
	uniformDiffusePos=glGetUniformLocation(progIdent,"diffuse");
	uniformSpecularPos=glGetUniformLocation(progIdent,"specular");
	uniformSpecularExponentPos=glGetUniformLocation(progIdent,"specularExponent");

	printf("%d %d %d\n",
		attribVtxPos,
		attribColorPos,
		attribNormalPos);

	printf("%d %d %d %d %d %d %d\n",
		uniformProjectionPos,
		uniformModelViewPos,
		uniformLightDirPos,
		uniformAmbientPos,
		uniformDiffusePos,
		uniformSpecularPos,
		uniformSpecularExponentPos);
}

////////////////////////////////////////////////////////////

/* virtual */ void PointSprite3dRenderer::CacheLocation(void)
{
	attribVtxPos=glGetAttribLocation(progIdent,"vertex");
	attribColorPos=glGetAttribLocation(progIdent,"color");
	attribPointSizePos=glGetAttribLocation(progIdent,"pointSize");
	uniformProjectionPos=glGetUniformLocation(progIdent,"projection");
	uniformModelViewPos=glGetUniformLocation(progIdent,"modelView");

	uniformSizeInPixelPos=glGetUniformLocation(progIdent,"sizeInPixel");
	uniformSizeIn3dPos=glGetUniformLocation(progIdent,"sizeIn3d");
	uniformWindowHeightPos=glGetUniformLocation(progIdent,"windowHeight");

printf("%d %d %d\n",attribVtxPos,attribColorPos,attribPointSizePos);
}

