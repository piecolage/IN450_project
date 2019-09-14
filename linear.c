/* funzione che genera la componente j-esima di Di dell'articolo, prende in input il polinomio f, il numero di variabili n_var e l'indice i della variabile rispetto alla quale derivare e l'indice j*/

int D(char *f, int n_var, int i, int j){
	int k,l;	// contatori per i cicli for
	char *ei;     	// puntatore all'i-esimo vettore della base canonica
	char *ej;	// puntatore all'j-esimo vettore della base canonica
	char *eij; 	// puntatore al vettore ei+ej
	char *nullo;	// puntatore al vettore nullo
	int dij;	// valore di output

	// generazione vettore nullo di dimensione n_var

	nullo = malloc(n_var * sizeof(char));	 
	for (l=0; l<n_var; l++){
		nullo[l] = 0;
	}
		
	// generazione di Di[j]

	if(j==i){		
		return 0;               //Di[i]=0
		}
	else{
		ei = base(n_var,i);		// genro l'i-esimo vettore della base canonica
		ej = base(n_var,j);		// genro l'i-esimo vettore della base canonica
		
		// genero eij sommando ei con ej

		eij = malloc(n_var * sizeof(char));
		for (k=0; k<n_var; k++){
			eij[k] = (ei[k] + ej[k])%2;
		}

		// calcolo Di[j]
		
		dij = (valutapoly(f, eij, n_var) + valutapoly(f, ei, n_var) +
				valutapoly(f, ej, n_var) + valutapoly(f, nullo, n_var))%2;
		free(nullo);
		free(eij);
		free(ei);
		free(ej);
		return dij; 
	}
}



