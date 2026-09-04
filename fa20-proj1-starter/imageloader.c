/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{   //把ppm文件变成一个images结构体
	//YOUR CODE HERE
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
	{
		return NULL;
	}
	char format[3];
	uint32_t cols;
	uint32_t rows;
	int max;
	fscanf(fp,"%2s",format);
	fscanf(fp,"%u %u",&cols,&rows);
	fscanf(fp,"%d",&max);
	if(strcmp(format,"P3") != 0 || max != 255)
	{
		fclose(fp);
		return NULL;
	}
	Image *img = malloc(sizeof(Image));
	if(img == NULL)
	{
		fclose(fp);
		return NULL;
	}
	img->cols = cols;
	img->rows = rows;

	uint32_t total = rows * cols;

	img->image = malloc(total * sizeof(Color *));
	if(img->image == NULL)
	{
		free(img);
		fclose(fp);
		return NULL;
	}
	for(uint32_t i =0; i<total;i++)
	{
		img->image[i] = malloc(sizeof(Color));
	}
	for(uint32_t i =0;i<total;i++)
	{
		int r,g,b;
		fscanf(fp,"%d %d %d",&r,&g,&b);
		img->image[i]->R = r;
		img->image[i]->G = g;
		img->image[i]->B = b;
	}
	fclose(fp);
	return img;
}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	// 把图片按照ppm的格式打印出来。
	//YOUR CODE HERE
	printf("P3\n");
	printf("%u %u\n",image->cols,image->rows);
	printf("255\n");
	for(uint32_t row =0;row < image->rows;row++)
	{
		for(uint32_t col =0;col < image->cols;col++)
		{ 
			uint32_t i = row *image->cols + col;
			Color *pixel = image->image[i];
			printf("%3hhu %3hhu %3hhu",pixel->R,pixel->G,pixel->B);
			if(col == image->cols - 1)
			{
				printf("\n");
			}else{
				printf("   ");
			}
		}
	}
}

//Frees an image
void freeImage(Image *image)
{
	//YOUR CODE HERE

	uint32_t total = image->rows * image->cols;
	for(uint32_t i =0;i< total;i++)
	{
		free(image->image[i]);
	}
	free(image->image);
	free(image);
}