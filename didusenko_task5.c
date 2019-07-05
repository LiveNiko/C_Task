#include <stdio.h>
#include <conio.h>
#define N 3

int summa(int arr[][N]){
	int i, j, sum=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			sum += arr[i][j];
		}
	}
	return sum;
}
void printArray(int arr[][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%i ", arr[i][j]);
		}
		printf("\n");	
	}
	printf("\n");
}
void changeRows(int arr[][N]){
	int i, j, temp;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			temp = arr[0][j];
			arr[0][j] = arr[N-1][j];
			arr[N-1][j] = temp;
		}
	}
}
int main(){
	int array[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	printArray(array);
	changeRows(array);
	printArray(array);
	getch();
	return 0;
}
