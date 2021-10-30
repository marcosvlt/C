/*
*  Created on: 20 de mai de 2021
*  Author: https://github.com/marcosvlt
*  Program to sum two matrices. 
*  Ask the User to fill in the data. 
*/

#include <stdlib.h>
#include <stdio.h>

void add_data(int* mat);
void show(int* mat);
void calc_sum(int* matA, int* matB, int* matC);


int main(int argc, char** argv) {

	int matA[2][2], * ptrMatA;
	int matB[2][2], * ptrMatB;
	int matC[2][2], * ptrMatC;
	int i, j, pos;
	pos = 0;


	// Points to the first address of the matrice

	ptrMatA = &matA[0][0];
	ptrMatB = &matB[0][0];
	ptrMatC = &matC[0][0];


	// add date to matrice

	printf("\n ENTER DATA FOR MATRICE 1");
	add_data(&matA[0][0]);
	printf("\n\n --------------------------- \n \n");
	printf("\n ENTER DATA FOR MATRICE 2");
	add_data(&matB[0][0]);

	// show the matrices
	printf("\n --- MATRICE A --- \n");
	show(&matA[0][0]);
	printf("\n --- MATRICE B --- \n");
	show(&matB[0][0]);

	printf("\n --- SUM OF THE MATRICES---- \n\n");
	calc_sum(&matA[0][0], &matB[0][0], &matC[0][0]);

	show(&matC);

	system("pause");
}


void add_data(int* mat) {
	int i, j, pos, numero;
	pos = 0;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++) {

			printf("\nEnter the line %d value , column %d: ", i, j);
			scanf_s("%d", &numero);

			if (numero < 0) {
				printf("Numbers lower than 0 is not permited");
				exit(-1);
			}
			else {

				*(mat + pos) = numero;

			}

			pos++;
		}

}

void show(int* mat) {
	int i, j, pos;
	pos = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", *(mat + pos));
			pos++;
		}
	}

}

void calc_sum(int* matA, int* matB, int* matC) {

	*matC = *matA + *matB;
	for (int var = 1; var < 4; ++var) {
		*(matC + var) = *(matA + var) + *(matB + var);
	}

}

