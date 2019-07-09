#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inLowerCase(char string[]);
void startWithSome(char string[][11]);
void changeFirstAndLastLetter(char string[]);
void printVowelsWords(char wodrs[][10]);
void deleteVowels(char string[]);
void toUpperCase(char string[]);
void deleteNumbersAndDigits(char string[]);
void changeSymbols(char string[]);
void reverseString(char word[]);
void addWord(char string[][10]);
void changeSomeToAny(char string[]);	
void defineFrequency(char string[]);
	
int main(){
	
	char string1[] = "asdASDzxcZXCqwertQWERT,.!-";
	char string2[][11] = {"something", "soup", "sometime", "somber", "somehow"}; 
	char string3[] = "Hello";
	char string4[][10] = {"animal", "load", "reason", "early", "dream"};
	char string5[] = "competition";
	char string6[] = "sorry for interrupting";
	char string7[] = "I,- will= do/* my4 be~st!";
	char string8[] = "Query";
	char string9[] = "STOP";
	char string10[][10] = {"pen", "cup", "brains"};
	char string11[] = "something someone cool awesome";
	char string12[] = "communication";
	
	// Using password to enter the programm
	while(1){
		char password[] = "green";
		char input[10];
		printf("\nPlease enter the password and press \"Enter\" button\n");
		gets(input);
		int confirmation = strcmp(password, input);
		if(confirmation == 0) break;
		else printf("Wrong password. Try again\n");
	}
		
	printf("\n\n DMYTRO DIDUSENKO - STRINGS. TASK#9\n\n");
	
	int choice;
	
	while(1){
		printf(" 1  - Print latin letters only in lower case in given string\n");
		printf(" 2  - Print string starting with \"some\" in given strings array\n");
		printf(" 3  - Replace the first and last letters with the number 5 in given string\n");
		printf(" 4  - Print lines beginning with a vowel in given string\n");
		printf(" 5  - Remove all vowels in given string\n");
		printf(" 6  - Change lower case to upper case in given string\n");
		printf(" 7  - Delete all symbols and digits in given string\n");
		printf(" 8  - Return a string all ASCII characters whose character code \n      differs from the given one by 5 in given string\n");
		printf(" 9  - Reverse given string\n");
		printf(" 10 - Add word \"use\" before each word in diven string array\n");
		printf(" 11 - Change \"some\" to \"any\" in given string\n");
		printf(" 12 - Determine the frequency of repeatability of letters in given string\n");
		
		printf("\n Please, make your choice: ");	
		
		scanf("%i", &choice);
		printf("\n");
	
		switch(choice){
			case 1: inLowerCase(string1); break;
			case 2: startWithSome(string2); break;
			case 3: changeFirstAndLastLetter(string3); break;
			case 4: printVowelsWords(string4); break;
			case 5: deleteVowels(string5); break;
			case 6: toUpperCase(string6); break;
			case 7: deleteNumbersAndDigits(string7); break;
			case 8: changeSymbols(string8); break;
			case 9: reverseString(string9); break;
			case 10: addWord(string10); break;
			case 11: changeSomeToAny(string11); break;
			case 12: defineFrequency(string12); break;
			default: printf("\nWrong input. Try again\n");
		}
	
		printf("\n Press any key to continue or \"Esc\" button to exit \n\n");
	
		int exitCode = getch();
		if(exitCode == 27) break;	
	}
	return 0;
}
// Task 1. Given a string. Print only Latin letters in lower case.
void inLowerCase(char string[]){
	int i;
	int size = strlen(string);
	for(i=0; i<size; i++){
		if(string[i] >= 'a' && string[i] <= 'z'){
			printf("%c", string[i]);
		}
	}
	printf("\n");
}

// Task 2. Given array of strings. Print lines beginning with “some”
void startWithSome(char string[][11]){
	char word[5] = "some";
	int i;
	for(i=0; i<5; i++){
		if(strncmp(string[i], word, 4) == 0){
			puts(string[i]);
		}
	}
	printf("\n");
}

// Task 3. Given a string. Replace the first and last letters with 5
void changeFirstAndLastLetter(char string[]){
	int i;
	int size = strlen(string);
	string[0] = '5';
	string[size-1] = '5';
	puts(string);
	printf("\n");
}

// Task 4. Given rray of strings. Print lines beginning with a vowel
void printVowelsWords(char words[][10]){
	char vowels[7] = "aeiouy";
	int i, j;
	for(i=0; i<5; i++){
		for(j=0; j<7-1; j++){
			if(words[i][0] == vowels[j]){
				puts(words[i]);
			}
		}
	}
	printf("\n");
}

// Task 5. Given a string. Remove all vowels
void deleteVowels(char string[]){
	int i, j, k=0, counter=0;
	char letters[] = "bcdfghjklmnpqrstvwxz";
	for(i=0; i<20; i++){
		for(j=0; j<strlen(letters); j++){
			if(letters[i] == letters[j]) counter++;
		}
	}
	char* resArr = (char*)calloc(counter, sizeof(char));
	for(i=0; i<strlen(string); i++){
		for(j=0; j<strlen(letters)-1; j++){
			if(string[i] == letters[j]){
				resArr[k] = string[i];
				k++;
			}
		}
	}
	puts(resArr);
	free(resArr);
	printf("\n");
}

// Task 6. Given a lowercase string. Translate to upper case
void toUpperCase(char string[]){
	int i;
	for(i=0; i<strlen(string); i++){
		if(string[i] >= 'a' && string[i] <= 'z'){
			string[i] -= ('a' - 'A');
		}
	}
	puts(string);
	printf("\n");
}

// Task 7. Given a string. Remove all signs and numbers
void deleteNumbersAndDigits(char string[]){
	int i, j;
	for(i=0; i<strlen(string); i++){
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || string[i] == ' ') {
			printf("%c", string[i]); 
		}
	}
	printf("\n");
}

// Task 8. Given a string. Return a string all ASCII characters 
// whose character code differs from the given one by 5
void changeSymbols(char string[]){
	int i;
	for(i=0; i<strlen(string); i++){
		string[i] += 5;
	}
	puts(string);
	printf("\n");
}

// Task 9. Given a string. Write revers function for reversal
void reverseString(char word[]){
	char temp;
	int i, size = strlen(word);
	for(i=0; i<size/2; i++){
		temp = word[i];
		word[i] = word[size - 1 - i];
		word[size - 1 - i] = temp;
	}
	puts(word);
	printf("\n");
}

// Task 10. Given an array of strings. Add before each word "use"
void addWord(char string[][10]){
	char word[] = "use "; 
	int i;
	for(i=0; i<3; i++){
		char* resArray = (char*)malloc(20);
		strcpy(resArray, word);
		strcpy(resArray+4, string[i]);
		puts(resArray);
		free(resArray);
	}
	printf("\n");
}

// Task 11 Given a string. Replace the string "some" with "any"
void changeSomeToAny(char string[]){
	char word2Find[] = "some", word2Change[] = "any";
	char* p_addres;
	while(1){
		p_addres = strstr(string, word2Find);
		if(p_addres == NULL) break;
		else{
			strcpy(p_addres, word2Change);
			strcpy(p_addres+3, p_addres+4);
		}
	}
	puts(string);
	printf("\n");
}

// Task 12. Given a string. Determine the frequency of repeatability of letters in the string
void defineFrequency(char string[]){
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	int i, j, quantity[26] = {};
	for(i=0; i<strlen(letters); i++){
		for(j=0; j<strlen(string); j++){
			if(letters[i] == string[j]){
				quantity[i]++;
			}
		}
	}
	for(i=0; i<strlen(letters); i++){
		if(quantity[i] != 0){
			printf("letter \"%c\" - %i times\n", letters[i], quantity[i]);	
		}
	}
	printf("\n");
}	
