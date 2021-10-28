#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 10

void QuickSortASC(int array[], int p, int u);
int Partition(int array[], int start, int end);
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

	system("pause");
	return 0;

}

void QuickSortASC(int array[], int start, int end) 
{
	int pivot;
	if (start < end)
	{
		pivot = Partition(array, start, end);
		QuickSortASC(array, start, pivot);
		QuickSortASC(array, pivot + 1, end);
	}

}


int Partition(int array[], int start, int end)
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

void Change(int array[], int i, int j)
{
	int aux;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;

}
