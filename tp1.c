#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

 extern void merge_sort(int vector[], int largo);

void parseo_ordenando(FILE* a_entrada, FILE* a_salida){

    char* linea = NULL;
    size_t tam = 0;

    while(getline(&linea, &tam, a_entrada) != EOF){    
        
        //FALTA CONTAR EL LARGO DEL VECTOR SIN USAR STRTOK
        size_t largo_vec = strlen(linea);
        int vector[largo_vec];

        //PASAMOS LOS NUMEROS AL VECTOR PARA LUEGO ORDENARLO//
        char* str = strtok(linea, " ");
        size_t k = 0;
        
        for(k = 0; str; k++){
            vector[k] = atoi(str);
            str = strtok(NULL, " ");
        }

        //merge_sort(vector, largo_vec);

        for(int i = 0; i < k; i++){
            fprintf(a_salida, "%d ", vector[i]);
            fflush(a_salida); 
        }
        fprintf(a_salida, "\n");
        fflush(a_salida);
    }
}


void printear_mensaje_ayuda(){
 
    printf("Usage:\n");
    printf("  tp1 -h\n");
    printf("  tp1 -V\n");
    printf("  tp1 -i in_file -o out_file\n");
    printf("Options:\n");
    printf("  -V, --version\t Print version and quit.\n");
    printf("  -h, --help\t Print this information and quit.\n");
    printf("  -i, --input\t Specify input stream/file, - for stdin.\n");
    printf("  -o, --output\t Specify output stream/file, - for stdout.\n");
    printf("Examples:\n");
    printf("  tp1 < in.txt > out.txt\n");
    printf("  cat in.txt | tp1 -i - > out.txt\n");

}



int main(int argc, char *argv[]){
    
    FILE* a_entrada = stdin;
    FILE* a_salida = stdout;
    
    switch (argv[1][1]){
        case 'h':
            printear_mensaje_ayuda();
            break;
        case 'V':
            printf("Version 0.0.1\n");
            break;
        case 'i': 
            if(argv[2][0] != '-') a_entrada = fopen(argv[2], "r");
            if (argv[4][0] != '-') a_salida = fopen(argv[4], "w");
            parseo_ordenando(a_entrada, a_salida);
            break;    
        default:
            printf("Error: Not an specified use");
            break;
    }
    return 0;
}
    