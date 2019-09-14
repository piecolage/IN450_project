/* funzione che mi converte in codice gray un intero; in input prende l'intero e la lunghezza della codifica, restituendo il vettore con la codifica. L'intero viene prima convertito in binario con il bit meno significativo a sinistra, di conseguenza anche il codice gray risulta "invertito". */


char *int2gray(int n,int m){
	int d;            // numero di divisioni per 2 che devo fare per generare bin
	int i,j,l,k;	  // contatori per i cicli for
	char *bin;        // puntatore al vettore del numero in binario 
	char *gray;   	  // puntatore al vettore del numero in graycode 


	if (n<0){
		printf("Impossibile eseguire il calcolo, input negativo.");
	}
	else if (n==0 || n==1){
		gray = malloc (m * sizeof(char));
		gray[0] = n;
		for (k=1; k<m; k++){
			gray[k]=0;
		}
	}

	// generazione vettore nullo di dimensione m, inizializzo bin con tutti zeri

	else{
		bin = malloc(m * sizeof(char));	 
		for (j=0; j<m; j++){
			bin[j] = 0;
		}
		
		d=(log(n) / log(2)) + 1;
				
	// calcolo la sequenza binaria di n in m bit (bit meno significativo a sinistra)

		if (d<=m){
			for (i=0; i<d; i++){
				bin[i] = n%2;
				n = n/2;
			}
		}
		
		else{
			free(bin);
			printf("non è possibile rappresentare n con soli m bit");
		}
		
		// calcolo il codice gray di n

		gray = malloc (m * sizeof(char)); 
		gray[d] = bin[d];
		for (l=0; l<d; l++){
			gray[d-1-l] = (bin[d-1-l] + bin[d-l])%2;
		}
		free(bin);
	}

	return gray;
}
