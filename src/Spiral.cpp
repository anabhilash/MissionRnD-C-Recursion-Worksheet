/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiral_wrapper(int **input_array, int *result, int rows, int columns, int x, int y, int x1, int y1, int index)
{
	int temp;
	if (index > rows*columns - 1)
	{
		return result;
	}
	else
	{
		for (temp = x1; temp <= y1; temp = temp + 1)
		{
			result[index] = input_array[x][temp];
			index++;
		}
		x++;
		for (temp = x; temp <= y; temp = temp + 1)
		{
			result[index] = input_array[temp][y1];
			index++;
		}
		y1--;
		if (x < y)
		{
			for (temp = y1; temp >= x1; temp -= 1)
			{
				result[index] = input_array[y][temp];
				index++;
			}
			y--;
		}
		if (x1 < y1)
		{
			for (temp = y; temp >= x; temp -= 1)
			{
				result[index] = input_array[temp][x1];
				index++;
			}
			x1++;
		}
		if (index == rows*columns - 1)
		{
			if (x == x1 && y == y1)
				result[index] = input_array[x][y1];
			return result;
		}
	}
	return spiral_wrapper(input_array, result, rows, columns, x, y, x1, y1, index);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)
		return NULL;
	if (rows <= 0 || columns <= 0)
		return NULL;
	int *result = (int *)malloc(sizeof(int)*(rows*columns));
	int index = 0, x = 0, y = rows - 1, x1 = 0, y1 = columns - 1;
	result = spiral_wrapper(input_array, result, rows, columns, x, y, x1, y1, index);
	return result;
}
