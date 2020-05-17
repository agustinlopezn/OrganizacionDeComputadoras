#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(){
    
    char* linea = NULL;
    //char* str = NULL;
    size_t tam = 0;

    while(getline(&linea, &tam, stdin) != EOF){    
        printf("%s", linea);

        // CONTAMOS EL LARGO DEL VECTOR//

        size_t k = 0;
        char* str = strtok(linea, " "); //strtok solo deja el primer elemento spliteado en str

        while( str != NULL ) {
            str = strtok(NULL, " ");  //La funcion strtok sigue spliteando "linea"
            k++; //
        }

        int* vector_a_ordenar = malloc(sizeof(int) * (k+1));

        //PASAMOS LOS NUMEROS AL VECTOR PARA LUEGO ORDENARLO//

        k = 1;
        str = strtok(linea, " ");
        vector_a_ordenar[0] = (int)*str;

        while( str != NULL ) {
            str = strtok(NULL, " ");
            printf("%d", (int)*str);
            vector_a_ordenar[k] = (int)*str;
            k++;
        }

        for(int i = 0; i < k; i++){
            printf("%d", vector_a_ordenar[i]);
        }

        //merge_sort(vector_a_ordenar, largo_vec);*/
    }

    return 0;

}
    