// Author: https://github.com/marcosvlt

#include <stdio.h>
#include <stdlib.h>

// Celsius to Fahrenheit
// F = C *(9.0/5.0)+32.0

int main(int argc, char *argv[]) {
	
	
	float C, F, sum;
	
	printf("Enter the Celsius tempeture\n");
	scanf("%f", &C);
	
	
	sum = C * (9.0/5.0)+32.0;
	
		
	printf("Fahrenheit = %.2f\n", sum);
	system("pause");
	
	
	return 0;
}
