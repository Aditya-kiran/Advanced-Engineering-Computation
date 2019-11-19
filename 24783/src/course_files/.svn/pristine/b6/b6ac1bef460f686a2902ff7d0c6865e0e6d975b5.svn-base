#include "simplebitmap.h"
#include "yspng.h"
#include "yspngenc.h"



SimpleBitmap::SimpleBitmap(const SimpleBitmap &incoming)
{
	CopyFrom(incoming);
}

SimpleBitmap &SimpleBitmap::operator=(const SimpleBitmap &incoming)
{
	CopyFrom(incoming);
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

SimpleBitmap &SimpleBitmap::operator=(class YsRawPngDecoder &&pngDecoder)
{
	return MoveFrom(pngDecoder);
}

SimpleBitmap &SimpleBitmap::MoveFrom(class YsRawPngDecoder &png)
{
	this->SetDirect(png.wid,png.hei,png.rgba);
	png.wid=0;
	png.hei=0;
	png.rgba=nullptr;
	return *this;
}

bool SimpleBitmap::LoadPng(const char fn[])
{
	YsRawPngDecoder png;
	png.Decode(fn);
	if(0<png.wid && 0<png.hei)
	{
		MoveFrom(png);
		return true;
	}
	return false;
}

bool SimpleBitmap::LoadPng(FILE *fp)
{
	YsRawPngDecoder png;
	png.Decode(fp);
	if(0<png.wid && 0<png.hei)
	{
		this->SetDirect(png.wid,png.hei,png.rgba);
		png.wid=0;
		png.hei=0;
		png.rgba=nullptr;
		return true;
	}
	return false;
}

SimpleBitmap SimpleBitmap::CutOut(int x0,int y0,int wid,int hei) const
{
	SimpleBitmap dst;
	SimpleBitmapTemplate <unsigned char,4>::CutOut(dst,x0,y0,wid,hei,255);
	return dst;
}

bool SimpleBitmap::SavePng(FILE *fp) const
{
	YsRawPngEncoder enc;
	enc.EncodeToFile(fp,GetWidth(),GetHeight(),8,6,GetBitmapPointer());
	return true;
}

bool SimpleBitmap::operator==(const SimpleBitmap &from) const
{
	if(GetWidth()!=from.GetWidth() || GetHeight()!=from.GetHeight())
	{
		return false;
	}

	for(int i=0; i<GetTotalNumComponent(); ++i)
	{
		if(GetBitmapPointer()[i]!=from.GetBitmapPointer()[i])
		{
			return false;
		}
	}

	return true;
}

bool SimpleBitmap::operator!=(const SimpleBitmap &bitmapB) const
{
	auto same=(*this)==bitmapB;
	return !same;
}

