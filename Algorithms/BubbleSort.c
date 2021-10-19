#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 10

void BubbleSort(int array[]);

int main() {

	int array[ARRAYSIZE] = { 0 };
	srand(time(NULL));

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		array[i] = rand() % 100;
	}

	printf_s("Array random \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);

	}

	BubbleSort(array);

	printf_s("Array ordered \n");

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}

	system("pause");
	return 0;

}

void BubbleSort(int array[]) 
{
	int aux;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		for (int j = 0; j < (ARRAYSIZE -1); j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}

		}

	}

}
