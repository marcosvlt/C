/*
* Convert Celsius to Fahrenheit
* Author: https://github.com/marcosvlt
* F = C *(9.0/5.0)+32.0
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	float C, F, sum;

	printf("Enter the Celsius tempeture\n");
	scanf_s("%f", &C);

	sum = C * (9.0 / 5.0) + 32.0;

	printf("Fahrenheit = %.2f\n", sum);
	system("pause");

	return 0;
}
