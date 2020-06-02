# 66.20 Organización de Computadoras, Trabajo práctico 2: Introduccion a caches

## Para trabajar en qemu
### Para mandar algun archivo
scp -P 5555 file.txt root@localhost:/tmp
### Para compilar
cc -Wall -g -o **benchmark-b0** /benchmarks-tp2/benchmark-b0.s
### Correr valgrind
/opt/valgrind/bin/valgrind --tool=cachegrind **benchmark-b0**
