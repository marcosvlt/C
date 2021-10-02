#include <iostream>

// Do while number is not 0

int main(int argc, char** argv) {
	
	
	
	
	int num, sum = 0;
	
	printf("Input a number 0 to exit\n");
	scanf("%d", &num);
	
	while(num != 0){
		sum = sum + num;
		
		printf("Input a number 0 to exit \n");
		scanf("%d", &num);
		
	}
	
	printf("The sum is %d\n", sum);
	
	system("pause");
		

	
	
}
