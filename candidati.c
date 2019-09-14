/* Funzione che seleziona i possibili candidati zeri del sistema; prende in input il vettore zeri output della funzione risolvi_sistema, il numero di equazioni, n_eq, controllate nella funzione risolvi_sistema e il numero di variabili n_var. Restituscie un vettore in cui il primo valore è il numero dei candidati zeri, e i successivi sono gli interi i t.c. zeri[i]=n_eq, cioè gli i t.c. graycode(i) è uno zero comune a tutte le equazioni del sistema preliminare. */


long int *possibili_candidati(int *zeri, int n_eq, int n_var){
	int i,j;		  // contatori per i cicli for
	int nz;			  // numero di zeri comuni a tutti i polinomi
	long int *candidati;	  // vettore di output
	long int temp;		  // variabile ausiliaria per la potenza di 2 che uso spesso 
	
	nz = 0;
	temp = (long int)pow(2,n_var);

	// cerco i valori in zeri che sono uguali a n_eq

	for (i=0; i<temp; i++){
		if (zeri[i]==n_eq){
			nz++;
			if(nz-1==0){
	// è il primo zero che incontro, creo candidati di lunghezza due e inserisco i come 2°
				candidati = malloc((nz+1) * sizeof(long int));
				candidati[1] = i;
			}
	
			else{
	// non è il primo zero che trovo, allungo il vettore candidati di 1 inseriserendo i 
				candidati = realloc(candidati, (nz+1) * sizeof(long int));
				candidati[nz] = i;
			}
		}
	}
	
	// se nz=0 non ho zeri comuni

	if(nz==0){
		printf("il sistema non ha soluzioni.");
		exit(0);
	}
	
	// inserisco il numero di zeri nz (!=0), alla posizione zero di candidati

	else{
		candidati[0] = nz;
		return candidati;
	}
}
