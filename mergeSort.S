/*
 * Versión simple del método de ordenamiento merge_sort.
 * Copyright: Margarita Manterola, Maximiliano Curia
 * Licencia: CC-BY-SA 2.5 (ar) ó CC-BY-SA 3.0
*void merge_sort(int vector[], int inicio, int fin)
*
*	int largo = fin - inicio;
*	if (largo < 2) {
*		return;
*	}
*
*	int medio = inicio + (largo / 2); // ATENCIÓN: requiere C99
*	merge_sort (vector, inicio, medio);
*	merge_sort (vector, medio, fin);
*	merge (vector, inicio, medio, fin);
*
*
*void merge (int vector[], int inicio, int medio, int fin)
*
*	int pos_1 = inicio;
*	int pos_2 = medio;
*	int aux[fin-inicio]; // ATENCIÓN: requiere C99
*	int pos_a = 0;
*
*	// Intercala ordenadamente
*	while ( (pos_1 < medio) && (pos_2 < fin) ) {
*		if ( vector[pos_1] <= vector[pos_2] ) {
*			aux[pos_a] = vector[pos_1];
*			pos_a++; pos_1++;
*		} else {
*			aux[pos_a] = vector[pos_2];
*			pos_a++; pos_2++;
*		}
*	}
*	// Copia lo que haya quedado al final del primer vector
*	while (pos_1 < medio) {
*		aux[pos_a] = vector[pos_1];
*		pos_a++; pos_1++;
*	}
*	// Copia lo que haya quedado al final del segundo vector
*	while (pos_2 < fin) {
*		aux[pos_a] = vector[pos_2];
*		pos_a++; pos_2++;
*	}
*
*	// Copia los valores del vector auxiliar al original
*	int a = 0; // ATENCIÓN: requiere C99
*	int i = inicio; // ATENCIÓN: requiere C99
*	while (i < fin) {
*		vector[i] = aux[a];
*		i++; a++;
*	}
*}
*/


#include <sys/regdef.h>
        .abicalls 
        .text 
        .align 2        #2^n para alinear palabras
        .globl merge_sort
        .ent merge_sort

merge_sort:
        .frame fp, 48, ra
        .set noreorder
        .cpload t9
        .set reorder
        subu sp, sp, 48
        .cprestore 32   # Hace un sw gp, 32(sp)
        sw ra, 40(sp)
        sw fp, 36(sp)
        move fp, sp

        #Recibo los parametros
        #
        sw a0, 48(sp)   # vector
        sw a1, 52(sp)   # largo

        lw t0, 52(sp)   # Cargo el largo (t0: largo)
        lw t1, 48(sp)   # Cargo la direccion de mem inicial del vector
        sll t0, t0, 2   # Largo * 4

loop:   
        beq zero, t0, end
        subu t0, t0, 4 #i--
        subu t1, t1, t0 # vector = vector + 1 (sub por ser pila creciente para abajo(?)
        lw t2, 0(t1) # t2: Vector[i]
        srl t2, t2, 1 # vector[i] / 2
        sw t2, 0(t1)
        b loop
end:     
        move sp, fp
	lw fp, 36(sp)
	lw ra,  40(sp)
	addu sp, sp, 48

        j ra
        .end merge_sort







