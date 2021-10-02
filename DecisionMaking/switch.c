#include <stdio.h>


int main(){
	
	int num;
	
	
	printf("Input a number between 1 to 3\n");
	scanf("%d", &num);
	
	
	switch(num){
		case 1:
		printf("One\n");
		system("pause");
		break;
		
		case 2:
		printf("Two\n");
		system("pause");
		break;
		
		case 3:
		printf("Three\n");
		system("pause");
		break;
		
		default:
		printf("Number is invalid\n");
		system("pause");
		
	}
	
	
}
