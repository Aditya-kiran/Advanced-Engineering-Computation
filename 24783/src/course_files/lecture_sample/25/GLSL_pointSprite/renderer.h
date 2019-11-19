#ifndef RENDERER_H_IS_INCLUDED
#define RENDERER_H_IS_INCLUDED

#include <string>

class RendererBase
{
private:
	unsigned int vtxShaderIdent;
	unsigned int fragShaderIdent;
public:
	unsigned int progIdent;

public:
	static std::string ReadTextFile(const char fName[]);

	bool Compile(const char vtxShaderFn[],const char fragShaderFn[]);
	bool Compile(const std::string &vtxShaderSrc,const std::string &fragShaderSource);
private:
	bool CompileShader(int shaderIdent);
	bool LinkShader(void);

	virtual void CacheLocation(void)=0;
};

////////////////////////////////////////////////////////////

class PassThroughRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class ColorByWindowCoordRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class Sampler2dRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
	unsigned int attribTexCoordPos;
	unsigned int uniformTexIdentPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class Plain3dRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
	unsigned int attribColorPos;
	unsigned int uniformProjectionPos;
	unsigned int uniformModelViewPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class Rainbow3dRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
	unsigned int uniformProjectionPos;
	unsigned int uniformModelViewPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class Shaded3dRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
	unsigned int attribColorPos;
	unsigned int attribNormalPos;

	unsigned int uniformProjectionPos;
	unsigned int uniformModelViewPos;
	unsigned int uniformLightDirPos;
	unsigned int uniformAmbientPos;
	unsigned int uniformDiffusePos;
	unsigned int uniformSpecularPos;
	unsigned int uniformSpecularExponentPos;
private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

class PointSprite3dRenderer : public RendererBase
{
public:
	unsigned int attribVtxPos;
	unsigned int attribColorPos;
	unsigned int attribPointSizePos;

	unsigned int uniformProjectionPos;
	unsigned int uniformModelViewPos;

	unsigned int uniformSizeInPixelPos;
	unsigned int uniformSizeIn3dPos;
	unsigned int uniformWindowHeightPos;

private:
	virtual void CacheLocation(void);
};

////////////////////////////////////////////////////////////

#endif

