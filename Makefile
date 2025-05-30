all: main

main: main.o biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o
	gcc -o -Wall main.o biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o

main.o: main.c biblioH.h biblioLC.h entreeSortieH.h entreeSortieLC.h
	gcc -c -Wall main.c 

biblioLC.o: biblioLC.h biblioLC.c
	gcc -c -Wall biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc -c -Wall entreeSortieLC.c

biblioH.o: biblioH.c biblioH.h
	gcc -c -Wall biblioLC.c

entreeSortieH.o: entreeSortieH.c entreeSortieH.h
	gcc -c -Wall entreeSortieLC.c

