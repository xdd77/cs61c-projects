/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

//Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
//Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
//and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	//YOUR CODE HERE
	

	Color *newpixel = malloc(sizeof(Color));
	if(newpixel == NULL)
	{
		return NULL;
	}
	newpixel->R = 0;
	newpixel->G = 0;
	newpixel->B = 0;
	


	int currentIndex = row * image->cols + col;
	Color *current = image->image[currentIndex];
	//计算周围的活细胞数
	for(int bit = 0; bit < 8; bit++)
	{
		int rCount = 0;
        int gCount = 0;
        int bCount = 0;
		for(int dr = -1;dr <= 1;dr++)
		{
			for(int dc = -1;dc<=1;dc++)
			{
				if(dr ==0 && dc ==0)
				{
					continue;
				}
				int nr = (row + dr + image->rows) % image ->rows;
				int nc = (col + dc + image->cols) % image ->cols;
				Color *neighbor = 
				image->image[nr*image->cols + nc];

				rCount += (neighbor->R >> bit) & 1;
				gCount += (neighbor->G >> bit) & 1;
				bCount += (neighbor->B >> bit) & 1;
			}
		}

		// int currentAlive = (current->R >> bit) & 1;
		int rAlive = (current->R >> bit) & 1;
        int gAlive = (current->G >> bit) & 1;
        int bAlive = (current->B >> bit) & 1;
		// int ruleIndex = (currentAlive * 9) + neighborCount;
		// //rule的位数表示当前的那中情况下一代是什么
		// int nextAlive = (rule >> ruleIndex) & 1;
		int rNext = (rule >> (rAlive * 9 + rCount)) & 1;
        int gNext = (rule >> (gAlive * 9 + gCount)) & 1;
        int bNext = (rule >> (bAlive * 9 + bCount)) & 1;

		if (rNext) {
            newpixel->R |= (1 << bit);
        }

        if (gNext) {
            newpixel->G |= (1 << bit);
        }

        if (bNext) {
            newpixel->B |= (1 << bit);
        }
		
	}
	return newpixel;
}
//The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
//You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule)
{
	//YOUR CODE HERE
	Image *newimage = malloc(sizeof(Image));
	if(newimage == NULL)
	{
		return NULL;
	}
	newimage->cols = image->cols;
	newimage->rows = image->rows;
	uint32_t total = newimage->rows * newimage->cols;
	newimage->image = malloc(total * sizeof(Color *));
	if(newimage->image == NULL)
	{
		free(newimage);
		return NULL;
	}
	for(int row = 0;row < image->rows;row ++)
	{
		for(int col =0;col < image->cols;col++)
		{
			int index = row * image->cols + col;
			newimage->image[index] = 
						evaluateOneCell(image,row,col,rule);
			if(newimage->image[index] == NULL)
			{
				for(int i =0;i<index;i++)
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
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv)
{
	//YOUR CODE HERE
	if(argc != 3)
	{
		return -1;
	}
	Image *image = readData(argv[1]);
	if(image == NULL)
	{
		return -1;
	}
	uint32_t rule = strtoul(argv[2],NULL,0);
	Image *newimage = life(image,rule);
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
