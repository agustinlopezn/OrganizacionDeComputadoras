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

    while ((bytes_leidos = getline(&linea, &tam, a_entrada)) != -1){  
        if (linea[0] == '\n'){
            fprintf(a_salida, "\n");
            fflush(a_salida); 
            continue; 
        }
          
        //CONTAMOS EL LARGO DEL VECTOR SIN USAR STRTOK PARA INICIALIZARLO
        int largo_vec = 0;
        bool flag_negativo = false;
        bool flag_numero = false;

        for (int i = 0; i < bytes_leidos-1; i++){

            if(isdigit(linea[i]) && !flag_numero) {
                if(flag_negativo) flag_negativo = false;
                flag_numero = true;
                largo_vec++;
            }
            
            else if (linea[i] == '-'){

                if (flag_negativo == true){
                    fprintf(stderr, "Invalid input\n");
                    fflush(stderr);
                }

                else if (flag_negativo == false) flag_negativo = true;
                
                flag_numero = false;
            }
            
            else if (linea[i] == ' ') flag_numero = false;
            
            else if ((linea[i] != '\0') && (linea[i] != '\n') && !flag_numero) {
                fprintf(stderr, "Error: Invalid input character\n");
                fflush(stderr);
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
 
    fprintf(stdout, "Usage:\n");
    fflush(stdout);
    fprintf(stdout, "  tp1 -h\n");
    fflush(stdout);
    fprintf(stdout, "  tp1 -V\n");
    fflush(stdout);
    fprintf(stdout, "  tp1 -i in_file -o out_file\n");
    fflush(stdout);
    fprintf(stdout, "Options:\n");
    fflush(stdout);
    fprintf(stdout, "  -V, --version\t Print version and quit.\n");
    fflush(stdout);
    fprintf(stdout, "  -h, --help\t Print this information and quit.\n");
    fflush(stdout);
    fprintf(stdout, "  -i, --input\t Specify input stream/file, - for stdin.\n");
    fflush(stdout);
    fprintf(stdout, "  -o, --output\t Specify output stream/file, - for stdout.\n");
    fflush(stdout);
    fprintf(stdout, "Examples:\n");
    fflush(stdout);
    fprintf(stdout, "  tp1 < in.txt > out.txt\n");
    fflush(stdout);
    fprintf(stdout, "  cat in.txt | tp1 -i - > out.txt\n");
    fflush(stdout);

}

int main(int argc, char *argv[]){
    
    FILE* a_entrada = stdin;
    FILE* a_salida = stdout;

    for(size_t i = 1; i < argc; i++){

		if (strcmp(argv[i], "-h") == 0){
			printear_mensaje_ayuda();
			break;
		}

		if (strcmp(argv[i], "-V") == 0){
			fprintf(stdout, "Version 0.1.1\n");
            fflush(stdout);
			break;
		}

		if (strcmp(argv[i], "-i") == 0){
			if(argv[i+1][0] != '-'){
				a_entrada = fopen(argv[i+1], "r");
					if(!a_entrada){
					fprintf(stderr, "Error: Cannot open/find the specified input file");
                    fflush(stderr);
					break;
				}
			}
		}

		if (strcmp(argv[i], "-o") == 0){
			if(argv[i+1][0] != '-'){
				a_salida = fopen(argv[i+1], "w");
				if(!a_salida){
					fprintf(stderr, "Error: Cannot open/find the specified output file");
                    fflush(stderr);
					break;
				}
			}
		}

        if(i == (argc-1)) parseo_ordenando(a_entrada, a_salida);

    }

    
    return 0;

}