/* funzione che dati in input la dimensione m e un intero i tra 0 e m-1 mi genera l'i-esimo 
       vettore della base canonica */

char *base(int m, int i){
	int j;                 // contatore per il ciclo
	char *vettore; 	       // puntatore al vettore della base canonica 
	
	// generazione dell'i-esimo vettore della base canonica

	vettore = malloc(m * sizeof(char));

	for (j=0; j<m; j++){
		if(j==i){
			vettore[j] = 1;
		}
		else{
			vettore[j] = 0;
		}
	}
	return vettore;
}

