#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// In computer science, binary search, also known as half-interval search, logarithmic search,or binary chop, 
// is a search algorithm that finds the position of a target value within a sorted array. 
// Binary search compares the target value to the middle element of the array. 
// If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, 
// again taking the middle element to compare to the target value, and repeating this until the target value is found. 
// If the search ends with the remaining half being empty, the target is not in the array.
// Source: https://en.wikipedia.org/wiki/Binary_search_algorithm

#define ARRAYSIZE 10000

void menu();
void clearBuffer();
bool BinarySearch(int search, int* array);
int counter = 0; // // numbers of iterations
int pivot_pos, pivot_value; // position of the pivo
//
// Bellow is for quicksort related only
//
void QuickSortASC(int array[], int start, int end);
int PartitionASC(int array[], int start, int end);
void Change(int array[], int i, int j);

int main() {
	// Bellow is to create a randon array and sort with quicksort
	
	// Create and sort the array.
	int array[ARRAYSIZE] = { 0 };
	int menu_option;
  
	// Related to the BinarySearch
	int search;	
	bool result;
	srand(time(NULL));

	// Create a randon array
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		array[i] = rand() % 100;
	}
	// Sort the array
	
	// Start measuring time
	clock_t start = clock();
	QuickSortASC(array, 0, ARRAYSIZE - 1);
	// Stop measuring time and calculate the elapsed time
	clock_t end = clock();
	float elapsed = ((float)end - (float)start) / CLOCKS_PER_SEC;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		printf_s("%d \n", array[i]);
	}
	printf_s("Array ordered ascending \n");
	printf("Time measured to order the array, not print: %.4f seconds.\n", elapsed);
		
	// end of quicksort part
	// menu
	do
	{
		menu();
		scanf_s("%d", &menu_option);
		clearBuffer();

		switch (menu_option)
		{
		case 1:
			printf("\n");

			printf("Type a number to search:");
			scanf_s("%d", &search);
		   
			// Start measuring time
			clock_t start = clock();
			result = BinarySearch(search, &array);
			// Stop measuring time and calculate the elapsed time
			clock_t end = clock();
			float elapsed = ((float)end - (float)start) / CLOCKS_PER_SEC;			

			if (result)
			{
				printf_s("FOUND!!\n");
				printf_s("Total interactions: %d \n", counter);
				printf_s("Position: %d \n", pivot_pos);
				printf("Time measured: %.4f seconds.\n", elapsed);		
				counter = 0; // reset the counter
			}
			else
			{
				printf_s("NOT FOUND!!\n");
				counter = 0; // reset the counter
			}
        
			printf("\n");
			system("pause");
			break;
		case 2:
			break;
		default:
			printf("invalid input");
			break;
		}

	} while (menu_option != 2);
	// end of menu
		
	system("pause");
	return 0;

}

bool BinarySearch(int search, int *array)
{
	
	int start = 0;	
	bool found = false;
	int end = ARRAYSIZE;

	pivot_value = array[(ARRAYSIZE / 2)];	

	while ((start <= end) && (found == false))
	{
		
		pivot_pos = (start + end) / 2;
		if (array[pivot_pos] == search)
		{
			found = true;
		}
		else if (search > array[pivot_pos])
		{
			start = pivot_pos + 1;			
		}
		else if (search < array[pivot_pos])
		{
			end = pivot_pos - 1;			
		}	
		counter++;

	}
	
	// if exit loop without find
	if (found == false)
	{
		return false;
	}
	
	return true;
}

void menu() {

	printf("Main Menu: \n");
	printf("1. Search: \n");
	printf("2. Exit \n");
	printf("Please enter an option from the main menu: ");
}

void clearBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} // clear keyboard buffer
}

//
// Bellow is for quicksort related only
//

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

void Change(int array[], int i, int j)
{
	int aux;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;

}
