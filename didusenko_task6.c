#include <stdio.h>
#include <malloc.h>
#include <math.h>

void decimalToBinary();
void binaryToDecimal();

int main(){
	printf("DMYTRO DIDUSENKO - Converting Decimal Numbers to Binary and vice versa\n\n");
	
	int choice;
	while(1){
		printf("\nChoose the operation which you want to perform:\n");
		printf("1 - Converting Decimal numbers to Binary\n");
		printf("2 - Converting Binary to Decimal\n");
		printf("Please, make your choice: ");
		scanf("%i", &choice);
	
		switch(choice){
			case 1: decimalToBinary(); break;
			case 2: binaryToDecimal(); break;
		}
		
		printf("Press any key to continue or \"Esc\" button to exit \n");
		int exitCode = getch();
		if(exitCode == 27) break;
		}
	return 0;
}

void decimalToBinary(){
	int decimal, i; 
	char* dunamArray = NULL;
	printf("Input your decimal number and press \"Enter\" button \n");
	scanf("%i", &decimal);
	
	int arrayScale = (log10(decimal) / log10(2)) + 1;
	dunamArray = (char*)calloc(arrayScale, sizeof(char));
	for(i=arrayScale-1; i>=0; i--){
		dunamArray[i] = decimal%2;
		decimal /= 2;
	}
	printf("Your binary number - ");
	for(i=0; i<=arrayScale-1; i++){
		printf("%i", dunamArray[i]);
	}
	printf("\n\n");
}

void binaryToDecimal(){
	int decimal=0, i, j=0, binary;
	char* dunamBinaryArray = NULL;
	printf("Input your binary number and press \"Enter\" button \n");
	scanf("%i", &binary);
	int temp = binary, counter=0;
	while(temp>0){
		temp /= 10;
		counter++;
	}
	dunamBinaryArray = (char*)calloc(counter, sizeof(char));
	for(i=counter-1; i>=0; i--){
		dunamBinaryArray[i] = binary%10;
		binary /= 10;
	}
	printf("\n");			
	for(i=counter-1; i>=0; i--){
		decimal += dunamBinaryArray[i]*pow(2, j);
		j++;
	}
	free(dunamBinaryArray);
	printf("Your decimal number - %i\n\n", decimal);
}








