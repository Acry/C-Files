#include <stdio.h>
#include <stdlib.h>

// use arrays via functions

void printFloatArray(float *, int);
void print2DFloatArray(int rows, int columns, float arr[][columns]);

int main()
{

	float temps[] = { 84.9, 83.7, 85.8, 88.2 };
	float temps2[][2] = { {14.3, 67.0}, {20.3, 92.0}, {0.0, 14.3},  {12.1, 29.5} };
	printf("Local temperatures:\n");
	for(int x=0; x<4 ;x++)
		printf("Station %d: %.1f\n",x,temps[x]);

	printf("\nFrom function:\n");
	printFloatArray(temps, 4);

	printf("\n2D array flat:\n");
	for(int x=0; x<4 ;x++)
		for(int y=0; y<2 ;y++)
			printf("Station %d: %.1f\n",x +1, temps2[x][y]);

	printf("\n2D array:\n");
	for(int x=0; x<4 ;x++){
		printf("Station %d: " , x + 1);
		for(int y=0; y<2 ;y++){
			if (y == 0)
				printf("lowest %.1f, ", temps2[x][y]);
			else
				printf("highest %.1f", temps2[x][y]);

		}
		printf("\n");
	}
	printf("\nFrom function:\n");
	print2DFloatArray(4, 2, temps2);

	return(EXIT_SUCCESS);
}

void printFloatArray(float *arr, int size){
		for(int x=0;x<size;x++)
		printf("Station %d: %.1f\n",x,arr[x]);
}

void print2DFloatArray(int rows, int columns, float arr[][columns]){
		printf("first %.1f\n",*(*(arr + 0) + 0));
		printf("second %.1f\n",arr[0][1]);

		for(int x=0; x<rows ;x++){
		printf("Station %d: " , x +1);
		for(int y=0; y<columns ;y++){
			if (y == 0)
				printf("lowest %.1f, ",arr[x][y]);
			else
				printf("highest %.1f",arr[x][y]);

		}
		printf("\n");
	}
}