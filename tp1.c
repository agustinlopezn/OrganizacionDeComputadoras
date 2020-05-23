#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include"merge_sort.h"
#define _POSIX_C_SOURCE 200809L //para incluir getline

 //extern void mergesort(int vector[], int largo);

void parseo_ordenando(FILE* a_entrada, FILE* a_salida){

    char* linea = NULL;
    size_t tam = 0;
    long int bytes_leidos = 0;

    while((bytes_leidos = getline(&linea, &tam, a_entrada)) != -1){    
          
        //CONTAMOS EL LARGO DEL VECTOR SIN USAR STRTOK PARA INICIALIZARLO
        int largo_vec = 0;
        bool flag_negativo = false;
        bool flag_numero = false;

        for(int i = 0; i < bytes_leidos-1; i++){

            if(isdigit(linea[i]) && !flag_numero) {
                if(flag_negativo) flag_negativo = false;
                flag_numero = true;
                largo_vec++;
            }
            
            else if(linea[i] == '-'){
                if(flag_negativo == true) fprintf(stderr, "Invalid input\n");
                else if(flag_negativo == false) flag_negativo = true;
                flag_numero = false;
            }
            
            else if(linea[i] == ' ') flag_numero = false;
            
            else if((linea[i] != '\0') && (linea[i] != '\n') && !flag_numero) {
                fprintf(stderr, "Invalid input\n");
            }    
        }

        int vector[largo_vec];


        //PASAMOS LOS NUMEROS AL VECTOR PARA LUEGO ORDENARLO//
        char* str = strtok(linea, " ");
        size_t k = 0;
        
        for(k = 0; str; k++){
            vector[k] = atoi(str);
            str = strtok(NULL, " ");
        }
       
        merge_sort(vector, largo_vec);

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
            fprintf(stderr, "Error: Not an specified use");
            break;
    }
    
    return 0;
}