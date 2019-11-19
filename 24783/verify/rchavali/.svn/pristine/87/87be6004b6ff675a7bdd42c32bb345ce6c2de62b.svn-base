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
#include "simplebitmap.h"
#include <iostream>
#include <vector>
#include "hash.cpp"

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;

protected:
	SimpleBitmap original_bitmap;
	HashTable<SimpleBitmap, int> myMap;
	std::vector<SimpleBitmap> revertedMyMap;
	std::vector<std::vector<SimpleBitmap> > totalMap;
	std::vector<std::vector<SimpleBitmap> > totalMap_without_Player;
	std::vector<std::vector<int> > myVector;
	int start_x = 0;
	int start_y = 0;
	int mode = 1;
	int hei;
	int wid;
	int count;

protected:
	unsigned char * getBitMap(SimpleBitmap a);
	SimpleBitmap compareResult(SimpleBitmap player, std::vector<SimpleBitmap> mapList);
	int compareHelper(SimpleBitmap player, SimpleBitmap background);

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

unsigned char * FsLazyWindowApplication::getBitMap(SimpleBitmap a) 
{
	auto rgba = a.GetBitmapPointer();

	unsigned char * res = new unsigned char[6400];

	for (int i = 0; i < 6400; i++) 
	{
		res[i] = rgba[i];
	}
	return res;
}

SimpleBitmap FsLazyWindowApplication::compareResult(SimpleBitmap player, std::vector<SimpleBitmap> mapList) 
{
	SimpleBitmap prt;
	int val = 100000;

	int index = -1;

	for (int i = 0; i < mapList.size(); i++) 
	{
		// printf("here");

		if (!mapList[i].isPlayer()) 
		{
			// printf("here");

			int tempValue = compareHelper(player, mapList[i]);
			if (tempValue < val) 
			{
				// printf("here");

				val = tempValue;
				index = i;
			}
		}
	}
	prt = mapList[index];
	return prt;
}

int FsLazyWindowApplication::compareHelper(SimpleBitmap player, SimpleBitmap background) 
{
	auto background_ptr = background.GetBitmapPointer();
	auto player_ptr = player.GetBitmapPointer();

	auto number_of_pixels = player.GetWidth()*player.GetHeight();

	int result = 0;
	for (int i = 0 ; i < number_of_pixels; i++) 
	{
		if (player_ptr[i*4 + 0] == 0 && player_ptr[i*4 + 1] == 0 && player_ptr[i*4 + 2] == 0) 
		{
			// printf("here");
			continue;
		}
		if (player_ptr[i*4 + 0] == 255 && player_ptr[i*4 + 1] == 0 && player_ptr[i*4 + 2] == 0) 
		{
			// printf("here");

			continue;
		}
		if (player_ptr[i*4 + 0] == 255 && player_ptr[i*4 + 1] == 255 && player_ptr[i*4 + 2] == 255) 
		{
			// printf("here");

			continue;
		}
		if (player_ptr[i*4 + 0] == background_ptr[i*4 + 0] && player_ptr[i*4 + 1] == background_ptr[i*4 + 1] && player_ptr[i*4 + 2] == background_ptr[i*4 + 2] && player_ptr[i*4 + 3] == background_ptr[i*4 + 3]) 
		{
			// printf("here");
			
		} 
		else 
		{
			// printf("here");

			result += 1;
		}
	}
	return result;
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{


	SimpleBitmap original_bitmap;
	printf("%s",argv[1]);
	
	FILE * input_file = fopen(argv[1], "r");
	original_bitmap.LoadPng(input_file);
	fclose(input_file);

	this->original_bitmap = original_bitmap;

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
	int x = original_bitmap.GetWidth() / 40;
	int y = original_bitmap.GetHeight() / 40;
	count = 0;
	
	SimpleBitmap cut_bitmap;

	for (int j = 0; j < y; j++) {
		std::vector<SimpleBitmap> tempVector;
		for (int i = 0; i < x; i++) 
		{
			cut_bitmap = original_bitmap.CutOut(i*40, j*40, 40, 40);
			tempVector.push_back(cut_bitmap);

			if (!myMap.IsIncluded(cut_bitmap)) 
			{
				// printf("here");
				myMap.Update(cut_bitmap, count);
				revertedMyMap.push_back(cut_bitmap);
				count++;
				// printf("%d",count);
			}

		}
		totalMap.push_back(tempVector);
	}


	for (int j = 0; j < y; j++) 
	{
		std::vector<int> tempVector;
		for (int i = 0; i < x; i++) 
		{
			// printf("here");

			cut_bitmap = original_bitmap.CutOut(i*40, j*40, 40, 40);
			tempVector.push_back(*myMap[cut_bitmap]);
		}
		myVector.push_back(tempVector);
	}

	for (int i = 0; i < myVector.size(); i++) 
	{
		for (int j = 0; j < myVector[i].size(); j++) 
		{
			// printf("here");

			printf("%c", ' ' + (char)myVector[i][j]);
		}
		printf("\n" );
	}

	for (int i = 0; i < totalMap.size(); i++) 
	{
		std::vector<SimpleBitmap> tempVector;

		for (int j = 0; j < totalMap[0].size(); j++) 
		{
			if (totalMap[i][j].isPlayer()) 
			{
				// printf("here");

				SimpleBitmap tempBitMap = compareResult(totalMap[i][j], revertedMyMap);
				tempVector.push_back(tempBitMap);
			} 
			else 
			{
				tempVector.push_back(totalMap[i][j]);
			}
		}
		totalMap_without_Player.push_back(tempVector);
	}
	

}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	FsPollDevice();
	
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}

    switch(key)
    {
	case FSKEY_UP:
		if (start_y > 0) 
		{
			start_y -= 1;
		}
		break;
	case FSKEY_DOWN:
		if (start_y < totalMap.size() - 21) 
		{
			start_y += 1;
		}
		break;
    case FSKEY_LEFT:
    	if (start_x > 0) 
    	{
    		start_x -= 1;
    	}
        break;
    case FSKEY_RIGHT:
    	if (start_x < totalMap[0].size() - 31) 
    	{
    		start_x += 1;
    	}
        break;
    case FSKEY_SPACE:
        if(mode == 1)
        {
			mode = 2;
        } else if (mode == 2) 
        {
        	mode = 3;
        }

        break;
    }


	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if (mode == 1) 
	{
		int tempcount = 0;
		for (int j = 0; j < 20; j++) 
		{
			if (tempcount >= revertedMyMap.size()) 
			{
					break;
			}
			for (int i = 0; i < 30; i++) 
			{
				if (tempcount >= revertedMyMap.size()) 
				{
					break;
				}
				SimpleBitmap bmp = revertedMyMap[tempcount];
				bmp.Invert();


				glRasterPos2d(i*40, j*40  + 40);
				glDrawPixels(bmp.GetWidth(),bmp.GetHeight(),GL_RGBA,GL_UNSIGNED_BYTE,bmp.GetBitmapPointer());
				
				tempcount += 1;
			}
		}
	}

	if (mode == 2) 
	{

		for (int j = start_y; j < start_y + 20; j++) 
		{
			for (int i = start_x; i < start_x + 30; i++) 
			{
				SimpleBitmap bmp = totalMap[j][i];
				bmp.Invert();


				glRasterPos2d((i - start_x)* 40, (j - start_y)* 40  + 40);
				glDrawPixels(bmp.GetWidth(),bmp.GetHeight(),GL_RGBA,GL_UNSIGNED_BYTE,bmp.GetBitmapPointer());
			}
		}
	}
	
	if (mode == 3)
	{

		for (int j = start_y; j < start_y + 20; j++) 
		{
			for (int i = start_x; i < start_x + 30; i++) 
			{
				SimpleBitmap bmp = totalMap_without_Player[j][i];
				bmp.Invert();


				glRasterPos2d((i - start_x)*40, (j - start_y)*40  + 40);
				glDrawPixels(bmp.GetWidth(),bmp.GetHeight(),GL_RGBA,GL_UNSIGNED_BYTE,bmp.GetBitmapPointer());
			}
		}
	}

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
