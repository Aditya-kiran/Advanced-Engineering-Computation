#include <stdio.h>

#include "simplebitmap.h"



int main(int argc,char *argv[])
{
	if(2<=argc)
	{
		SimpleBitmap bmp;
		bmp.LoadPng(argv[1]);
		printf("%d %d\n",bmp.GetWidth(),bmp.GetHeight());
	}
	else
	{
		printf("Usage: simplebitmaptest filename.png\n");
	}
	return 0;
}

