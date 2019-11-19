#include "simplebitmap.h"
#include <iostream>

int main(int argc,char *argv[])
{
	SimpleBitmap original_bitmap;
	SimpleBitmap cut_bitmap;

	if (argc < 2) 
	{
		printf("Usage: ps4_1 <pngFileName.png>");
		return 0;
	}
	printf("%s",argv[1]);

	FILE * input_file = fopen(argv[1], "r");

	bool isSuccess = original_bitmap.LoadPng(input_file);
	int x = original_bitmap.GetWidth() / 40;
	int y = original_bitmap.GetHeight() / 40;
	int count = 1;
	fclose(input_file);

	if (!isSuccess) 
	{
		printf("Error: Failed to read a .PNG file.");
		return 0;
	}
	
	// printf("here");

	// printf("here_1");
	for (int j = 0; j < y; j++) 
	{
		for (int i = 0; i < x; i++) 
		{
			if (count == 201) 
			{
				break;
			}
			// printf("Entered second loop");		
			std::string temp = std::to_string(count);
			temp += ".png";

			cut_bitmap = original_bitmap.CutOut(i*40, j*40, 40, 40);
			FILE * output_file = fopen(temp.c_str(), "wb");
			cut_bitmap.SavePng(output_file);
			fclose(output_file);

			// printf("here_2");
			count += 1;

		}
		if (count == 201) {
			break;
		}
	}
	return 0;
}
