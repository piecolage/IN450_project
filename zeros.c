/* funzione che torva tutti gli zeri di un polinomi di grado 2 in n_var variabili in F2;
	(unroolled version for quadratic f)
gli input sono  il polinomio f, il numero di variabili n_var e un vettore (zeri) lungo 2^n_var, cioè i possibili zeri del polinomio in questione. La funzione modifica quest'ultimo vettore aumentando di 1 il valore in posizione i dove graycode(i) è uno zero del polinomio.
*/

int zeros(char *f, int n_var, int *zeri){
	
	int y;			// varibile per la valutazione del polinomio nel punto considerato
	char *nullo;		// puntatore al vettore nullo di dim. n_var
	int i,s,u,v;		// contatori per i cicli for
	char *z;		// puntatore ad un vettore ausiliario
	long int temp,d;	// variabile per delle potenze di 2 che uso spesso		
	int l,k;		// variabili per b1() e b2()

	// generazione vettore nullo di dimensione n_var
	nullo = malloc(n_var * sizeof(char));	 
	for (i=0; i<n_var; i++){
		nullo[i] = 0;
	}

	// inizializzazione vettore z di lunghezza n_var 
	z = malloc(n_var * sizeof(char));	 
	for (s=0; s<n_var; s++){
		z[s] = 0;
	}

	// valutazione della polinomio in 0

	y = valutapoly(f, nullo, n_var);
	free(nullo);
	if (y==0){
		zeri[0]++;	
	}
	
	z[0] = cost(f, n_var, 0);   
	y = (y + z[0])%2;

	// valutazione del polinomio nei restanti punti

	for (u=1; u<n_var; u++){
		if (y==0){
			zeri[(long int)pow(2,u)-1]++;
		}

		z[u] = (D(f,n_var,u,u-1) + cost(f,n_var,u))%2;
		y = (y + z[u])%2;
		temp = pow(2,u);

		for (v=0; v<temp-1; v++){
			if (y==0){
				zeri[temp + v]++;
			}

			k = b(1,temp + v + 1);
			l = b(2,temp + v + 1);
			z[k] = (z[k] + D(f,n_var,k,l))%2;
			y = (y + z[k])%2;
		}
	}

	free(z);
	if (y==0){
		zeri[(long int)pow(2,n_var)-1]++;
	}
	
	return 0;
}

