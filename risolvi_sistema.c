/* funzione che trova gli zeri comuni delle prime n_eq equazioni del sistema; prende in input l'intero sistema, il numero di equazioni n_eq da valutare e il numero di variabili n_var.
Utilizza molte volte la funzione zeros, per questo come prima operazione genera il vettore zeri che poi sarà dato in input zeros che lo modifica aumentando di 1 l'indice i per ogni polinomio che ha graycod(i) come zero, per poi restituirlo così modificato. Si avrà quindi che graycode(i) è uno zero in comune a tutti i polinomi scansionati se zeri[i]=n_eq.  */

int *risolvi_sistema(char **sistema, int n_eq, int n_var){
	int i;			// contatore per il ciclo for
	long int j;		// contatore per il ciclo for
	int *zeri;		// puntatore al vettore di output
	long int temp;		// variabile per la dimensione del vettore zeri
	
	// generazione e inizializzazione del vettore zeri contenente tutti 0
	
	temp = (long int)pow(2,n_var);
	zeri = malloc(temp * sizeof(int));
	for (j=0; j<temp; j++){
		zeri[j] = 0;
	}

	// applicazione della funzione zeros ai primi n_eq polinomi del sistema
	for (i=0; i<n_eq; i++){
		zeros(sistema[i], n_var, zeri);
	}

	return zeri;
} 

 

