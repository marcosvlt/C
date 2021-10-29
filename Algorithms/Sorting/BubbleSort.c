#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, 
//compares adjacent elements and swaps them if they are in the wrong order. 
// The pass through the list is repeated until the list is sorted. 
//The algorithm, which is a comparison sort, is named for the way smaller or larger elements "bubble" to the top of the list.
//This simple algorithm performs poorly in real world use and is used primarily as an educational tool. 
// More efficient algorithms such as quicksort, timsort, or merge sort are used by the sorting libraries built into popular programming languages such as Python and Java.
// Source: https://en.wikipedia.org/wiki/Bubble_sort

#define ARRAYSIZE 10

void BubbleSortASC(int array[]);
void BubbleSortDESC(int array[]);

int main() {

	int array[ARRAYSIZE] = { 0 };
	srand(time(NULL));

	// Create a randon array
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		array[i] = rand() % 100;
	}

	printf_s("Array random \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);

	}

	BubbleSortASC(array);
 
	printf_s("Array ordered ascending \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}
	
	BubbleSortDESC(array);
	
	printf_s("Array ordered descending  \n");
	
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}

	system("pause");
	return 0;

}

void BubbleSortASC(int array[]) 
{
	int aux;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		for (int j = 0; j < (ARRAYSIZE -1); j++)
		{
			// If current position is greater than next position
			if (array[j] > array[j + 1])
			{
				// swap using temporaty variable to store de value.
				aux = array[j]; // aux receive current value
				array[j] = array[j + 1]; // current position receive next position
				array[j + 1] = aux; // next position receive the current position
			}

		}

	}
}

void BubbleSortDESC(int array[]) 
{
	int aux;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		for (int j = 0; j < (ARRAYSIZE -1); j++)
		{
			
			if (array[j] < array[j + 1])
			{
				
				aux = array[j]; 
				array[j] = array[j + 1]; 
				array[j + 1] = aux; 
			}

		}

	}

}
