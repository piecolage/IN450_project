/* Programma che risolve un sistema random di n equazioni (al più) di secondo grado in m incognite in F2; viene quindi prima creato il sistema random e poi risolto: prima viene risolto un sistema con una parte di equazioni e gli zeri di questo sistema più piccolo vengono poi passati ai restanti polinomi del sistema di partenza per vedere se sono zeri anche di questi altri polinomi. Il numero di equazioni deve essere >=2; un polinomio viene identificato dal vettore dai suoi coefficenti. Essendo polinomi di secondo grado in F2 i monomi di secondo grado sono del tipo xi*xj con i != j; l'ordimaneto dei monomi è : x0x1, x0x2,..., x0x(m-1), x1x2,..., x1x(m-1), x2x3,..., x2x(m-1),..., x(m-2)x(m-1), x0,...x(m-1), termine noto (per esempio in 3 variabili il vettore 1010011 identifica il polinomio x0x1+x1x2+x2+1). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include "basecanonica.c"
#include "valutapoly.c"
#include "b_func.c"
#include "linear.c"
#include "int2gray.c"
#include "costantpart.c"
#include "zeros.c"
#include "risolvi_sistema.c"
#include "check.c"
#include "candidati.c"
#include "crea_sistema.c"

int main(){
	int m,n;      		// variabili per numero di incognite e di equazioni
	long int d;		// variabile per il numero massimo di monomi di un polinomio in m incognite
	char **sistema;		// puntatore alla "matrice" che identifica il sistema
	int *zeri;		// puntatore ad un vettore per immagazzinare i possibili zeri
	int temp1;		// variabile ausiliaria per il log2 dl numero di equazioni 
	long int temp;		// variabile ausiliaria per una potenza di  
	int n1;			// variabile per il numero di eq. da analizzare nel sistema preliminare
	long int *candidati;	// puntatore al vettore per i candidati zeri dopo la risoluzione del 1° sistema
	
	printf("inserire il numero di incognite:");
	scanf("%d", &m);
	printf("inserire il numero di equazioni:");
	scanf("%d", &n);

	// controllo che il numero di equazioni sia maggiore uguale a 2

	if (n<2){
		printf("inserire un numero maggiore di equazioni.");
		exit(0);
	}

	// creazione sistema random di n equazioni in m incognite (e stampa a video)

	sistema = random_system(n,m);	
	
	//inizzializo il vettore zeri, lungo 2^m (numero max di zeri) 
	
	temp = (long int)pow(2,m);
	zeri = malloc(temp * sizeof(int));
	
	// calcolo il numero di equzioni da risolvere nel sistema preliminare

	temp1 = (int)(log(n) / log(2));
	n1 = (int)(2 * temp1 - (log(temp1) / log(2)) + log(log(n)));
	
	// risoluzione del sistema con le prime n1 equazioni 

	zeri = risolvi_sistema(sistema, n1, m);	
	
	// ricerca dei possibili zeri candidati

	candidati = possibili_candidati(zeri, n1, m);
	
	// controllo dei candidati zeri nei restanti polinomi del sistema, e stampa a video delle soluzioni

	check(sistema, n1, n, m, candidati);
	
	free(zeri);
	free(candidati);
	return 0;	
}


