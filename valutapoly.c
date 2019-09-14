/* funzione che valuta un polinomio nel punto x; prende in input il polinomio f, il vettore x, nel quale il polinomio deve essere valutato, e il numero di incognite n_var.
(ricordiamo che i polinomi sono di secondo grado in F2) */

int valutapoly(char *f, char *x, int n_var){
	
	long int d; 	// numero massimo di monomi di un polinomio in n_var incognite  
	int i,k,l,n,t;	// contatori per i cicli for
	int a;		// contatore che mi serve per capire se il vettore x è nullo o no
 	long int j;	// contatore che mi scorre sui monomi di secondo grado di f
	int s;		// contatore che mi scorre sui monomi di primo grado di f
	int valore;	// valore della valutazione di f(x) (output)
	

	d=((n_var*n_var)+n_var+2)/2;
	/* controllo se x è il vettore nullo sommando i valori al suo interno, se lo è f(x) è il 			termine noto */
	a=0; 
	for (i=0; i<n_var; i++){
		a=a+x[i];
	}

	// caso vettore nullo
	
	if (a==0){                      
		return f[d-1];
	}
	
	// caso vettore base canonica:
	//cerco l'xt=1 e quindi il risultato è solo xt*fj+termine noto mod2 

	else if (a==1){			 
		for (t=0; t<n_var; t++){      
			if (x[t]==1){
				return ((f[d-n_var-1+t]+f[d-1])%2);      //xt=1, lo ometto
			}
		}
	}
	
	// caso generico

	else{                           
		valore=0;
		j=0;

	// valutazione della parte di secondo grado

		for (l=0; l<n_var; l++){                  
			if (x[l]!=0){			
				for(k=l+1; k<n_var; k++){
					valore=valore+f[j]*(x[l]*x[k]);
					j++;
				}
			}	
			else{
				j=j+n_var-(l+1);    // se x[l]=0 salto tutti i monomi con x[l],
			}			    // che quindi sono 0, aggiornando j
		}

		// valutazione della parte di primo grado

		s=0;
		for (n=d-n_var-1; n<d-1; n++){
			valore=valore+(f[n]*x[s]);     // continuo ad aggiornare il risultato
			s++;                           // provvisorio
		}		
		valore=(valore+f[d-1])%2;    // sommo alla parte di primo e secondo grado (valore)
		return valore;               //il termine noto (f[d-1]) riducendo modulo 2
	}
}

