#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <windows.h>

//Написать функцию которая сохраняет цифры числа в массив
void putDigitsIntoArray();

//Написать функцию которая создаёт массив рандомного размера (от 0 до 9)
void createRandomSizeArray();

//Написать функцию которая раскладывает слово в массив букв
void putLetterInArray();

//Написать функцию которая разделяет вещественное число на целую и дробную часть. Результат сохранить в массив
void floatPointedNumbersIntoArray();

//Дан массив из 10 чисел. Выбрать только чётные и сохранить в новый массив
void chooseEvenNumbers();

//Дан массив 10 букв. Выбрать гласные и сохранить в новый массив
void chooseVowels();

void printIntArray(int* array, int size);
void printCharArray(char* array, int size);

int main(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	printf("DMYTRO DIDUSENKO - ARRAYS, POINTERS, STRINGS. TASK#7\n\n");
	
	srand(time(0));
	
	int choice;
	while(1){
		printf("1 - Функция, которая сохраняет цифры числа в массив;\n");
		printf("2 - Функция, которая создаёт массив рандомного размера (от 0 до 9);\n");
		printf("3 - Функция, которая раскладывает слово в массив букв;\n");
		printf("4 - Функция, которая разделяет вещественное число на целую и дробную часть. \n    Результат сохраняет в массив;\n");
		printf("5 - Функция, которая выбирает только чётные числа из массива из 10 чисел \n    и сохраняет их в новый массив;\n");
		printf("6 - Функция, которая выбирает гласные буквы из массива из 20 букв \n    и сохраняет их в новый массив.\n");
		printf("\nPlease, make your choice: ");	
		
		scanf("%i", &choice);
		printf("\n");
	
		switch(choice){
			case 1: putDigitsIntoArray(); break;
			case 2: createRandomSizeArray(); break;
			case 3: putLetterInArray(); break;
			case 4: floatPointedNumbersIntoArray(); break;
			case 5: chooseEvenNumbers(); break;
			case 6: chooseVowels(); break;
			default: printf("\nWrong input. Try again\n");
	}
	
	printf("\nPress any key to continue or \"Esc\" button to exit \n\n");
	
	int exitCode = getch();
	if(exitCode == 27) break;
	}
	return 0;
}

void putDigitsIntoArray(){
	int N, i, counter=0;
	printf("Input your integer number and press \"Enter\" button \n");
	scanf("%i", &N);
	int temp = N;
	while(temp>0){
		temp /= 10;
		counter++;
	}
	int* arr = (int*)calloc(counter, sizeof(int));
	for(i=counter-1; i>=0; i--){
		arr[i] = N % 10;
		N /= 10;
	}
	printf("Digits in array: ");
	printIntArray(arr, counter);
	free(arr);
}

void createRandomSizeArray(){
	int N, i;
	N = rand()%10;
	int* arr = (int*)calloc(N, sizeof(int));
	for(i=0; i<N; i++){
		arr[i] = rand()%10;
	}
	printf("Array of random size %i: ", N);
	printIntArray(arr, N);
	free(arr);
}

void putLetterInArray(){
	int i;
	char word[20];
	printf("Input your word and press \"Enter\" button \n");
	scanf("%s", word);
	int N = strlen(word);
	char* arr = (char*)calloc(N, sizeof(char));
	for(i=0; i<N; i++){
		arr[i] = word[i];
	}
	printf("Created char array: ");
	printCharArray(arr, N);
	free(arr);
}

void floatPointedNumbersIntoArray(){
	int i, j, numAmountFul=0, sizeIntArr;
	char str[10];
	printf("Input float pointed number and press \"Enter\" button \n");
	scanf("%s", str); 
	int numSize = strlen(str);
	for(i=0; i<numSize; i++){
		if(str[i] != '.'){
			numAmountFul++;
			sizeIntArr = 1;
		} 
		else{
			sizeIntArr = 2;
			break;	
		} 
	}
	int* intArr = (int*)calloc(sizeIntArr, sizeof(int));
	j = numAmountFul - 1;
	for(i=0; i<numAmountFul; i++){
		intArr[0] += (str[i]-48) * pow(10, j);
		j--;
	}
	j = (numSize - 1) - numAmountFul - 1;
	for(i=numAmountFul+1; i<numSize; i++){
		intArr[1] += (str[i]-48) * pow(10, j);
		j--;
	}
	printf("Array of devided integers: ");
	printIntArray(intArr, sizeIntArr);
	free(intArr);
}

void chooseEvenNumbers(){
	int i, j=0, arr[10], counter=0;
	for(i=0; i<10; i++){
		arr[i] = rand()%21;
	}
	printf("Initial array of random numbers: ");
	printIntArray(arr, 10);
	for(i=0; i<10; i++){
		if(arr[i] % 2 == 0) counter++;
	}
	int* evenArr = (int*)calloc(counter, sizeof(int));
	for(i=0; i<10; i++){
		if(arr[i] % 2 == 0){
			 evenArr[j] = arr[i];
			 j++;
		}	
	}
	printf("Array of chosen even numbers: ");
	printIntArray(evenArr, counter);
	free(evenArr);
}

void chooseVowels(){
	int i, j, k=0, counter=0;
	char letters[20], vowels[7] = "aeiouy";
	for(i=0; i<20; i++){
		letters[i] = 'a' + rand()%26;
	}
	printf("Initial random array of letters: ");
	printCharArray(letters, 20);
	for(i=0; i<20; i++){
		for(j=0; j<7-1; j++){
			if(letters[i] == vowels[j]) counter++;
		}
	}
	char* vowelsArr = (char*)calloc(counter, sizeof(char));
	for(i=0; i<20; i++){
		for(j=0; j<7-1; j++){
			if(letters[i] == vowels[j]){
				vowelsArr[k] = letters[i];
				k++;
			}
		}
	}
	printf("Array of vowels letters: ");
	printCharArray(vowelsArr, counter);
	free(vowelsArr);
}

void printIntArray(int* array, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%i ", array[i]);		
	}
	printf("\n");
}

void printCharArray(char* array, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%c ", array[i]);		
	}
	printf("\n");
}
