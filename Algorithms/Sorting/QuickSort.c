#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quicksort is an in-place sorting algorithm.  
// Published in 1961 it is still a commonly used algorithm for sorting. 
// Quicksort is a divide-and-conquer algorithm. 
// It works by selecting a 'pivot' element from the array and PartitionASCing the other elements into two sub-arrays, 
// according to whether they are less than or greater than the pivot. 
// For this reason, it is sometimes called PartitionASC-exchange sort. The sub-arrays are then sorted recursively. 
// This can be done in-place, requiring small additional amounts of memory to perform the sorting. 

#define ARRAYSIZE 10

void QuickSortASC(int array[], int start, int end); 
void QuickSortDESC(int array[], int start, int end); 
int PartitionASC(int array[], int start, int end);
int PartitionDESC(int array[], int start, int end);
void Change(int array[], int i, int j);



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

	QuickSortASC(array, 0, ARRAYSIZE - 1);


	printf_s("Array ordered ascending \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}
	
	QuickSortDESC(array, 0, ARRAYSIZE - 1);


	printf_s("Array ordered descending \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}

	system("pause");
	return 0;

}

void QuickSortASC(int array[], int start, int end) 
{
	int pivot;
	if (start < end)
	{
		pivot = PartitionASC(array, start, end);
		QuickSortASC(array, start, pivot); // From start to the pivot point
		QuickSortASC(array, pivot + 1, end); // From pivor point to the end 
	}

}

void QuickSortDESC(int array[], int start, int end)
{
	
	int pivot;
	if (start < end)
	{
		pivot = PartitionDESC(array, start, end); // find the pivo
		QuickSortDESC(array, start, pivot); // From start to the pivot point
		QuickSortDESC(array, pivot + 1, end); // From pivot point to the end 
	}


}


int PartitionASC(int array[], int start, int end)
{
	int pivot, pivot_pos, i, j;

	pivot_pos = (start + end) / 2; 
	pivot = array[pivot_pos]; 

	// scan variables
	i = start - 1;
	j = end + 1;

	while (i < j)
	{
		do // test the right side
		{
			j--;

		} while (array[j] > pivot);

		do // test the left side
		{
			i++;

		} while (array[i] < pivot);

		if (i < j)
			Change(array, i, j);		
	}
	return j;
}

int PartitionDESC(int array[], int start, int end)
{
	int pivot, pivot_pos, i, j;

	pivot_pos = (start + end) / 2; 
	pivot = array[pivot_pos]; 

	// scan variables
	i = start - 1;
	j = end + 1;

	while (i < j)
	{
		do // test the right side
		{
			j--;

		} while (array[j] < pivot); // Invert

		do // test the left side
		{
			i++;

		} while (array[i] > pivot); // Invert

		if (i < j)
			Change(array, i, j);		
	}
	return j;
}

void Change(int array[], int i, int j)
{
	int aux;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;

}

