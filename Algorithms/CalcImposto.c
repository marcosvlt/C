// Created on: 16 de mai de 2021
// Author: https://github.com/marcosvlt
// Programa para calcular valor a ser deduzido do imposto de renda
// Criado como estudo para faculdade

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void calcImposto(float *salario);
void imprime(float salario, float aliquota, float deducao);

int main(int argc, char **argv) {

	struct ficha_de_funcionario {

		char  nome[30];
		float salario;


	}; struct ficha_de_funcionario *funcionarioPtr, funcionario;

	funcionarioPtr = &funcionario;

	setlocale(LC_ALL, "");


	printf("\n------ Cadastro de funcionario ------\n\n\n");
	printf("Digite o nome do funcionario: ");
	fflush(stdin);
	scanf("%[^\n]%*c", &funcionarioPtr->nome);

	printf("Digite o salario do funcionario: (EX: 1500,99): ");
	fflush(stdin);
	scanf("%f", &funcionarioPtr->salario);

	printf("\n------ CALCULO DE ALIQUOTA DE IMPOSTO DE RENDA ------\n\n\n");


	printf("\nNome funcionario: %s \n", &funcionarioPtr->nome);
	calcImposto(&funcionarioPtr->salario);



}

void calcImposto(float *salario){


	float resultado;

	if(*salario <= 1903.98){
		printf("Salario do funcionario: %.2f", *salario);
		printf("\nAliquota: ISENTA");
		printf("\nValor a ser deduzido: ISENTO %.2f");


	}
	else if (*salario >= 1903.99 && *salario <= 2826.65) {


		resultado = ( *salario * 0.075 ) ;
		imprime(*salario, 7.50, resultado);

	}
	else if (*salario >= 2826.66 && *salario <= 3751.05){
		resultado = ( *salario * 0.15 );
		imprime(*salario, 15.00, resultado);

	}
	else if (*salario >= 3751.06 && *salario <= 4664.68) {
		resultado = ( *salario * 0.2250 ) ;
		imprime(*salario, 22.50, resultado);


	}
	else if (*salario > 4664.68) {
		resultado = ( *salario * 0.2750 ) ;
		imprime(*salario, 27.50, resultado);


	}

}



void imprime(float salario, float aliquota, float deducao){

	printf("Salario do funcionario: %.2f", salario);
	printf("\nAliquota: %.2f \%", aliquota);
	printf("\nValor a ser deduzido: %.2f", deducao);

}


