/* Funzione che crea un sistema random di n_eq equazioni in n_var variabili in F2; prende in input il numero di equazioni e quello delle variabili, e restituisce un array bidimensionale dove ogni riga mi identifica un polinomi (stampa anche il sistema) */

char **random_system(int n_eq, int n_var){
	int i,j,k;		// contatori per i cicli for
	long int l,s;		// contatori per i cicli for
	char **sistema;		// puntatore alla "matrice" di output
	long int d;		// variabile per il numero massimo di monomi in un polinomio

	srand(time(NULL));

	d = ((n_var*n_var)+n_var+2)/2;	// genero il numero massimo di monomi per un polinomio

	sistema = malloc(n_eq * sizeof(char *));
	for (i=0; i<n_eq; i++){
		sistema[i] = malloc(d * sizeof(char));
	}

	// generazione del sistema random	

	for (j=0; j<n_eq; j++){
		for(s=0; s<d; s++){
			sistema[j][s] = rand()%2;
		}
	}
	// stampa a video del sistema
	printf("equazioni del sistema: \n");
	for (k=0; k<n_eq; k++){
		printf("pol");
		printf("%d",k);
		printf(":");
		for (l=0; l<d; l++){
			printf("%d", sistema[k][l]);
		}
		printf("\n");
	}
	return sistema;
}

