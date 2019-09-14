/* Funzione che controlla se gli zeri comuni del sistema preliminare sono zeri anche dei restanti polinomi del sistema; prende in input il sistema, il numero della prima e dell'ultima equaazione da controllare, il numero di variabili e il vettore di output di candidati. Stampa a video gli zeri del sistema. */


int check(char **sistema, int n_eq_min, int n_eq_max, int n_var, long int *z_comuni){

	int i,j,k,s;     	// contatori per i cicli for
	int n_nuovi_zeri;	// variabile per il numero degli zeri del sistema generale
	int risultato;		// variabile per il risultato della valutazione dei polinomi
	char *zero_sistema;	// puntatore al vettore di uno zero del sistema

	
	n_nuovi_zeri = z_comuni[0];

	// valuto ogni polinomio nei possibili zeri trovati precedentemente, quando un possibile 
	// zero non soddisfa un polinomio lo setto a -1 così da non controllarlo più, decrementando
	// di uno n_nuovi_zeri

	for (i=n_eq_min; i<n_eq_max; i++){
		for (j=1; j<(z_comuni[0]+1); j++){
			if (z_comuni[j] != -1){
				risultato = valutapoly(sistema[i], int2gray(z_comuni[j], n_var), 
							n_var);
				if (risultato !=0){
					z_comuni[j] = -1;
					n_nuovi_zeri--;
				}
			}

	// se n_nuovi_zeri=0, un polinomio non si annulla nei possibili zeri

			if (n_nuovi_zeri == 0){
				printf("il sistema non ha soluzioni.");
				exit(0);
			}
		}
	}

	// se c'è almeno uno zero comune lo trasformo in codice gray e lo stamo a video

	for (k=1; k<(z_comuni[0]+1); k++){
		if(z_comuni[k]!=-1){
			zero_sistema = malloc(n_var * sizeof(char));		
			zero_sistema = int2gray(z_comuni[k],n_var);
			printf("una soluzione del sistema è: ");

			for (s=0; s<n_var; s++){
				printf("%d", zero_sistema[s]);
			}

			printf("\n");
			free(zero_sistema);
		}
	}
	
	return 0;
}


