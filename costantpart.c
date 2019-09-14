/* funzione che restituisce la parte costante della derivata rispetto all'i-esima variabile (c_i dell'articolo) del polinomio in questone (ricordiamo che i polinomi sono di secondo grado). Prende in input il polinomio f,il numero totale di incognite n_var e l'indice i*/

char cost(char *f, int n_var, int i){
	int j;		// contatore per il ciclo for
	char *nullo;	// puntatore al vettore nullo di lunghezza n_var
	char *ei;	// puntatore all'i-esimo vettore della base canonica
	char ci;	//valore di output

	// generazione vettore nullo di dimensione n_var

	nullo = malloc(n_var * sizeof(char));	 
	for (j=0; j<n_var; j++){
		nullo[j] = 0;
	}
	// generazione di ei

	ei = base(n_var,i);

	// generazione della costante
	
	ci = (valutapoly(f,ei,n_var) + valutapoly(f,nullo,n_var))%2;
	free(nullo);
	free(ei);
	return ci;
}
