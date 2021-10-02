//Created on: 20 de mai de 2021
// Author: https://github.com/marcosvlt
// Programa para somar duas matrizes. Pede para o Usuario preencer os dados. 


#include <stdlib.h>
#include <stdio.h>

void adicionaDado(int *mat);
void imprime(int *mat);
void calcSoma(int *matA, int *matB, int *matC);




int main(int argc, char **argv) {

	int matA[2][2], *ptrMatA;
	int matB[2][2], *ptrMatB;
	int matC[2][2], *ptrMatC;
	int i, j, pos;
	pos = 0;


	// Aponta para o primeiro endereço da Matriz
	ptrMatA = &matA[0][0];
	ptrMatB = &matB[0][0];
	ptrMatC = &matC[0][0];


	// ADICIONA DADOS NA MATRIZ

	printf("\n DIGITE OS DADOS PARA A MATRIZ 1");
	adicionaDado(&matA[0][0]);
	printf("\n\n --------------------------- \n \n");
	printf("\n DIGITE OS DADOS PARA A MATRIZ 2");
	adicionaDado(&matB[0][0]);



	// IMPRIME MATRIZ A
	printf("\n --- MATRIZ A --- \n");
	imprime(&matA[0][0]);
	printf("\n --- MATRIZ B --- \n");
	imprime(&matB[0][0]);

	printf("\n --- SOMA DAS MATRIZES---- \n\n");
	calcSoma(&matA[0][0],&matB[0][0],&matC[0][0]);

	imprime(&matC);
}


void adicionaDado(int *mat){
	int i, j, pos, numero;
	pos = 0;
	for( i=0; i<2; i++)
		for(j=0; j<2; j++){
			printf("\nDigite o valor da linha %d, coluna %d: ",i, j );
			scanf("%d", &numero);
				if (numero < 0) {
					printf("Numeros menores que 0 não são permitidos");
					exit(-1);
				} else {
					*(mat + pos) = numero;
					
				}

			pos++;
		}


}

void imprime(int *mat){
	int i, j, pos;
	pos = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", *(mat + pos));
			pos++;
		}
	}

}

void calcSoma(int *matA, int *matB, int *matC){

	*matC = *matA + *matB;
	for (int var = 1; var < 4; ++var) {
		*(matC + var ) = *(matA + var ) + *(matB + var );
	}

}


