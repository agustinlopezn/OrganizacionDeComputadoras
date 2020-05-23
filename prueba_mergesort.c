#include<stdio.h>
#include"mergesort.h"

int main(){

	int arreglo[8];

	arreglo[0] = 8;
	arreglo[1] = 7;
	arreglo[2] = 6;
	arreglo[3] = 5;
	arreglo[4] = 4;
	arreglo[5] = 3;
	arreglo[6] = 2;
	arreglo[7] = 1;

	printf("Arreglo original: ");
	for(int i = 0 ; i < 8 ; i++){
		
		printf("%d ",arreglo[i]);
	}
	printf("\n\n");

	mergesort(arreglo,8);

	printf("Arreglo ordenado: ");
	for(int i = 0 ; i < 8 ; i++){
		
		printf("%d ",arreglo[i]);
	}
	printf("\n\n");


	return 0;
}
