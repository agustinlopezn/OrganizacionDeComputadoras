# 66.20 Organización de Computadoras, Trabajo práctico 1: Programación MIPS

## Para trabajar en qemu
### Para mandar algun archivo
scp -P 5555 file.txt root@localhost:/tmp
### Para compilar
gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o tp1 tp1.c *.S
### Correr
./tp1 -i input.txt -o output.txt **ambas archivos particulares**<br/>
./tp1 -i - -o output.txt **entrada estandar**<br/>
./tp1 -i input -o - **salida estandar**<br/>
./tp1 -i - -o - **ambas estandar**<br/>
#### Para compilar localmente
gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o tp1 tp1.c



### 1.Objetivos
Familiarizarse con el conjunto de instrucciones MIPS y el concepto de ABI, extendiendo un
programa que resuelva el problema descripto a continuación.

### 2.Alcance
Este trabajo práctico es de elaboración grupal, evaluación individual, y de carácter obligatorio
para todos alumnos del curso.

### 3.Requisitos
El trabajo deberá ser entregado personalmente, en la fecha estipulada, con una carátula que
contenga los datos completos de todos los integrantes, un informe impreso de acuerdo con lo que
mencionaremos en la sección 6, y con una copia digital de los archivos fuente necesarios para
compilar el trabajo.

### 4.Descripción
El programa a desarrollar deberá procesar un stream de vectores de números enteros. A
medida que el programa avance en la lectura de éstos, deberá ordenar cada vector en forma
creciente, e imprimir inmediatamente el resultado por el stream de salida.
Los vectores ingresarán como texto por entrada estándar (stdin), donde cáda lı́nea describe
completamente el contenido del mismo, según el siguiente formato:

v 1 v 2 ... v N

El fin de lı́nea es el caracter \n (newline). Debido a que cada lı́nea contiene exactamente
un único vector, el fin del mismo coincidirá siempre con el final de la lı́nea que lo contiene. A
su vez, cada entero del vector estará separado de otros elementos por uno o más caracteres de
espacio en blanco.Por ejemplo, dado el siguiente flujo de entrada:

$ cat input.txt<br/>
3 2 1<br/>
6 5 1 2 9 3 8 7 4<br/>
6 0 0 1 3<br/>
-1<br/>
9<br/>
Al ejecutar el programa la salida serı́a:<br/>
$ tp1 -i input.txt -o -<br/>
1 2 3<br/>
1 2 3 4 5 6 7 8 9<br/>
0 0 1 3 6<br/>
-1<br/>
Ante un error, el progama deberá detenerse informando la situación inmediatamente (por
stderr).
### 4.1. Ejemplos

Primero, usamos la opción -h para ver el mensaje de ayuda:

$ tp1 -h<br/>
Usage:<br/>
tp1 -h<br/>
tp1 -V<br/>
tp1 -i in_file -o out_file<br/>
Options:<br/>
-V, --version	Print version and quit.<br/>
-h, --help	Print this information and quit.<br/>
-i, --input	Specify input stream/file, "-" for stdin.<br/>
-o, --output	Specify output stream/file, "-" for stdout.<br/>
Examples:<br/>
tp1 < in.txt > out.txt<br/>
cat in.txt | tp1 -i - > out.txt<br/>
A continuación, ejecutamos algunas pruebas:<br/>
$ cat example.txt<br/>
1<br/>
-1<br/>
+1<br/>
$ cat example.txt | ./tp1<br/>
1<br/>
-1 1<br/>
2<br/>

### 5.Implementación

El programa a desarrollar constará de una mezcla entre código MIPS32 y C, siendo la parte
escrita en assembly la encargada de ordenar un vector de enteros pasado por parámetro. El
formato de dicha función será:

`void merge_sort(int *vec, size_t len);`

Asimismo deberá usarse el algoritmo merge sort [1] y el modo 1 del sistema operativo para
manejo de acceso no alineado a memoria [3].

### 6.Informe

El informe deberá incluir:
* Documentación relevante al diseño e implementación del programa;
* Comando(s) para compilar el programa;
* Las corridas de prueba, con los comentarios pertinentes;
* El código fuente, en lenguaje C y MIPS;
* El código MIPS32 generado por el compilador 1 ;
* Este enunciado.

### 7.Entrega de TPs

La entrega de este trabajo deberá realizarse usando el campus virtual de la materia [4].
Asimismo, en todos los casos, estas presentaciones deberán ser realizadas durante los dı́as martes.
El feedback estará disponible de un martes hacia el otro, como ocurre durante la modalidad
presencial de cursada.
Por otro lado, la última fecha de entrega y presentación para esta trabajo será el martes
26/5.


Referencias<br/>
[1] Merge sort, https://en.wikipedia.org/wiki/Merge_sort.<br/>
[2] Bubble sort, https://en.wikipedia.org/wiki/Bubble_sort.<br/>
[3] Controlling the kernel unalignment handling via debugfs,
https://www.linux-mips.org/wiki/Alignment.<br/>
[4] Aula Virtual - Organización de Computadoras 86.37/66.20 - Curso 1 - Turno Martes.
https://campus.fi.uba.ar/course/view.php?id=649<br/>
https://drive.google.com/drive/folders/1RZNflRb6sG8nqsUAVxS2Ch1pNnEJCxxi
1<br/>
Por motivos prácticos, en la copia impresa sólo es necesario incluir la primera página del código assembly<br/>
MIPS32 generado por el compilador.
