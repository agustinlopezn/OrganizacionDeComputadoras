#include <stdio.h>
#include <unistd.h>

extern void merge_sort(int vector[], int largo);

int main(){

    int vector[] = {2, 4, 8};

    merge_sort(vector, 3);

    for(int i = 0; i < 3; i++){
        printf("%d", vector[i]);
    }

    printf("\n");

    return 0;
}