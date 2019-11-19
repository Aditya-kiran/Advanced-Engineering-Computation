#include "simplebitmap.h"
#include "yspng.h"
#include "yspngenc.h"
#include <iostream>


SimpleBitmap::SimpleBitmap(const SimpleBitmap &incoming)
{
	CopyFrom(incoming);
}
SimpleBitmap &SimpleBitmap::operator=(const SimpleBitmap &from)
{
	CopyFrom(from);
	return *this;
}
SimpleBitmap::SimpleBitmap(SimpleBitmap &&incoming)
{
	MoveFrom(incoming);
}
SimpleBitmap &SimpleBitmap::operator=(SimpleBitmap &&incoming)
{
	MoveFrom(incoming);
	return *this;
}
bool SimpleBitmap::LoadPng(const char fn[])
{
	YsRawPngDecoder decoder;
	if(YSOK==decoder.Decode(fn))
	{
		MoveFrom(decoder);
		return true;
	}
	return false;
}
bool SimpleBitmap::LoadPng(FILE *fp)
{
	YsRawPngDecoder decoder;
	if(YSOK==decoder.Decode(fp))
	{
		MoveFrom(decoder);
		return true;
	}
	return false;
}
SimpleBitmap &SimpleBitmap::operator=(class YsRawPngDecoder &&pngDecoder)
{
	return MoveFrom(pngDecoder);
}
SimpleBitmap &SimpleBitmap::MoveFrom(class YsRawPngDecoder &decoder)
{
	// Ownership of decoder.rgba needs to be transferred to this bitmap.
	SetDirect(decoder.wid,decoder.hei,decoder.rgba);
	decoder.wid=0;
	decoder.hei=0;
	decoder.rgba=nullptr;  // <=This way, decoder's destructor will not delete it.
	return *this;
}
SimpleBitmap SimpleBitmap::CutOut(int x0,int y0,int wid,int hei) const
{
	SimpleBitmap cut;
	SimpleBitmapTemplate <unsigned char,4>::CutOut(cut,x0,y0,wid,hei,0);
	return cut;
}
void SimpleBitmap::Clear(unsigned char r,unsigned char g,unsigned char b,unsigned char a)
{
	auto rgba=GetEditableBitmapPointer();
	auto numPix=GetWidth()*GetHeight();
	for(int i=0; i<numPix; ++i)
	{
		rgba[i*4  ]=r;
		rgba[i*4+1]=g;
		rgba[i*4+2]=b;
		rgba[i*4+3]=a;
	}
}
bool SimpleBitmap::SavePng(FILE *fp) const
{
	YsRawPngEncoder encoder;
	if(YSOK==encoder.EncodeToFile(fp,GetWidth(),GetHeight(),8,6,GetBitmapPointer()))
	{
		return true;
	}
	return false;
}
SimpleBitmap SimpleBitmap::revert() 
{
	SimpleBitmap result;
	
	result.Create(GetWidth(), GetHeight());
	result.Clear(0, 0, 0, 0);

	auto thisPtr = GetBitmapPointer();
	auto numPix = GetWidth() * GetHeight();
	
	auto resultPtr = result.GetEditableBitmapPointer();
	for (int i = 0; i < numPix; i++) {
		resultPtr[4 * (numPix - 1 - i) + 0] = thisPtr[i * 4 + 0];
		resultPtr[4 * (numPix - 1 - i) + 1] = thisPtr[i * 4 + 1];
		resultPtr[4 * (numPix - 1 - i) + 2] = thisPtr[i * 4 + 2];
		resultPtr[4 * (numPix - 1 - i) + 3] = thisPtr[i * 4 + 3];
	}
	return result;
}

bool SimpleBitmap::isPlayer() 
{
	auto numPix = GetWidth() * GetHeight();
	auto thisPtr = GetBitmapPointer();
	for (int i = 0 ; i < numPix; i++) 
	{
		if (thisPtr[i*4 + 0] == 0 && thisPtr[i*4 + 1] == 0 && thisPtr[i*4 + 2] == 0) 
		{
			return true;
		}
		if (thisPtr[i*4 + 0] == 255 && thisPtr[i*4 + 1] == 0 && thisPtr[i*4 + 2] == 0) 
		{
			return true;
		}
		if (thisPtr[i*4 + 0] == 255 && thisPtr[i*4 + 1] == 255 && thisPtr[i*4 + 2] == 255) 
		{
			return true;
		}
	}
	return false;
}
int SimpleBitmap::HashKey() const 
{
	auto rgba=GetBitmapPointer();
	auto numPix=GetWidth()*GetHeight()*4;
	int result = 0;
	for (int i = 0; i < numPix; i++) {
		result += (i) * ((int)rgba[i]);
	}
	return result;
}
bool SimpleBitmap::operator==(const SimpleBitmap &bitmapB) const
{
	// Fill this function as a part of the assignment.

	auto otherPtr = bitmapB.GetBitmapPointer();
	auto thisPtr = GetBitmapPointer();

	auto thisNumPix = GetWidth()*GetHeight()*4;

	auto otherNumPix = bitmapB.GetWidth() * bitmapB.GetHeight() * 4;

	if (thisNumPix!=otherNumPix) {
		return false;
	}
	for (int i = 0; i < thisNumPix; i++) {
		if (thisPtr[i] != otherPtr[i]) {
			return false;
		}
	}
	return true;
}

bool SimpleBitmap::operator!=(const SimpleBitmap &bitmapB) const
{
	// Fill this function as a part of the assignment.

	auto otherPtr = bitmapB.GetBitmapPointer();
	auto thisPtr = GetBitmapPointer();

	auto thisNumPix = GetWidth()*GetHeight()*4;

	auto otherNumPix = bitmapB.GetWidth() * bitmapB.GetHeight() * 4;

	if (thisNumPix!=otherNumPix) {
		return true;
	}
	for (int i = 0; i < thisNumPix; i++) {
		if (thisPtr[i] != otherPtr[i]) {
			return true;
		}
	}
	return false;
}

