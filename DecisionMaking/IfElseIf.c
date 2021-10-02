#include <stdio.h>
#include <stdlib.h>

int main() {

	int num;

	printf("Insert a number\n");
	scanf("%d", &num);

	if (num <= 10) {
		printf("Number is lower than 10\n");
		system("pause");
	}

	else if (num > 10 && num < 20) {
		printf("Number is beetween 10 and 20\n");
		system("pause");
	}

	else {
		printf("Number above 20\n");
		system("pause");
	}
}
