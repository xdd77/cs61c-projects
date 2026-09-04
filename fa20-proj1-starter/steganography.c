/************************************************************************
**
** NAME:        steganography.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**				Justin Yokota - Starter Code
**				YOUR NAME HERE
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This should not affect Image, and should allocate space for a new Color.
Color *evaluateOnePixel(Image *image, int row, int col)
{
	//YOUR CODE HERE
	int index = row * image->cols + col;
	Color *oldpixel = image->image[index];
	Color *newpixel = malloc(sizeof(Color));
	if(newpixel == NULL)
	{
		return NULL;
	}
	if(oldpixel->B & 1)
	{
		newpixel->R = 255;
		newpixel->G = 255;
		newpixel->B = 255;
	}else{
		newpixel->R = 0;
		newpixel->G = 0;
		newpixel->B = 0;
	}
	return newpixel;
}

//Given an image, creates a new image extracting the LSB of the B channel.
Image *steganography(Image *image)
{
	//YOUR CODE HERE
	Image *newimage = malloc(sizeof(Image));
	if(newimage == NULL)
	{
		return NULL;
	}
	newimage->cols = image->cols;
	newimage->rows =image->rows;
	uint32_t total = newimage->rows * newimage->cols;
	newimage->image = malloc(total * sizeof(Color *));
	if(newimage->image == NULL)
	{
		free(newimage);
		return NULL;
	}
	for(int row = 0; row < newimage->rows; row++)
	{
		for(int col = 0; col < newimage->cols; col++)
		{
			int index = row * newimage->cols + col;
			newimage->image[index] = evaluateOnePixel(image,row,col);


			if(newimage->image[index] == NULL)
			{
				for(int i = 0; i < index; i++)
				{
					free(newimage->image[i]);
				}
				free(newimage->image);
				free(newimage);
				return NULL;
			}
		}
	}
	return newimage;
}

/*
Loads a file of ppm P3 format from a file, and prints to stdout (e.g. with printf) a new image, 
where each pixel is black if the LSB of the B channel is 0, 
and white if the LSB of the B channel is 1.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a file of ppm P3 format (not necessarily with .ppm file extension).
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
	if(argc != 2)
	{
		return -1;
	}

	Image *image = readData(argv[1]);
	if(image == NULL)
	{
		return -1;
	}

	Image *newimage = steganography(image);
	if(newimage == NULL)
	{
		freeImage(image);
		return -1;
	}
	writeData(newimage);
	freeImage(image);
	freeImage(newimage);
	return 0;
}
