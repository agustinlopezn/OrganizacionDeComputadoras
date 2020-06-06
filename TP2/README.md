# 66.20 Organización de Computadoras, Trabajo práctico 2: Introduccion a caches

## Para trabajar en qemu
### Para mandar algun archivo
scp -P 5555 file.txt root@localhost:/tmp
### Para compilar
cc -Wall -g -o **benchmark-b0** /benchmarks-tp2/**benchmark-b0.S**
### Correr valgrind
/opt/valgrind/bin/valgrind --tool=cachegrind --I1=64,**1**,16 --D1=64,**1**,16 --LL=64,**1**,16 **./benchmark-b0**
### Ver linea por linea
/opt/valgrind/bin/cg_annotate cachegrind.out.**3470** /home/OrganizacionDeComputadoras/TP2/benchmarks-tp2/**benchmark-b0.S**
