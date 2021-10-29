#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // C99 and newer

#define ARRAYSIZE 10

void menu();
void clearBuffer();
bool LinearSearch(int array[], int search, int *pos);
bool LinearSearchDESC(int array[], int search, int* pos);


int main() {

	int array[ARRAYSIZE] = { 0 };
	int search, pos, num, menu_option;
	pos = 0;	
	bool find;
	

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

	do
	{	
		menu();
		scanf_s("%d", &menu_option);
		clearBuffer();	

		switch (menu_option)
		{
		case 1:
			
			printf("Searching ascending: \n");
			printf("Type a value to search: \n");
			scanf_s("%d", &search);

			find = LinearSearch(array, search, &pos);
			if (find)
			{
				printf_s("Value in position: %d\n", pos);
				printf_s("Total interaction to find %d\n", pos + 1);
			}
			else
			{
				printf_s("Value not found\n");
				
			}
			system("pause");

			break;
		case 2:

			printf("Searching descending: \n");
			printf("Type a value to search: \n");
			scanf_s("%d", &search);

			find = LinearSearchDESC(array, search, &pos); 
			if (find)
			{
				printf_s("Value in position: %d\n", pos);
				printf_s("Total interaction to find %d\n", ARRAYSIZE - pos);
			}
			else
			{
				printf_s("Value not found\n");

			}
			system("pause");
			
			break;
		case 3:
			break;

		default:
			printf("invalid input");
			break;
		}

	} while (menu_option != 3);
}

void menu() {

	printf("Main Menu: \n");
	printf("1. To search ascending: \n");
	printf("2. To search descending: \n");
	printf("3. Exit \n");
	printf("Please enter an option from the main menu: ");
}

bool LinearSearch(int array[], int search, int* pos)
{
	bool found = false;;
	int i = 0;
	
	while ((i <= ARRAYSIZE) && (found == false))
	{
		if (array[i] == search)
		{
			found = true;
			
		}
		else
		{
			i++; // if array positiion is not the searched value, 
				 // incrementeand to go the next position
		}
	}
	if (found == false)
	{
		return false;
	}
	else
	{
		*pos = i; // passa the position via pointer
		return true;
	}

}

bool LinearSearchDESC(int array[], int search, int* pos)
{
	bool found = false;;
	int i = ARRAYSIZE; // start at the end of the array

	while ((i >= 0) && (found == false))
	{
		if (array[i] == search)
		{
			found = true;

		}
		else
		{
			i--; // if array positiion is not the searched value, 
				 // decrement to go the next position
		}
	}
	if (found == false)
	{
		return false;
	}
	else
	{
		*pos = i; // pass the position through pointer
		return true;
	}

}

void clearBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} // clear keyboard buffer
}
