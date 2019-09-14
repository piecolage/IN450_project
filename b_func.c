/* implemtazione della funzione b_k(i) dell'articolo. Questa funzione restituisce l'indice del k-esimo meno significativo bit settato a 1, se il peso di hamming di i in rapprsentazione binaria è minore di k allora restituisce -1 (il bit meno significativo è a sinistra) */

int b(int k, int i){
	int j,s;      // contatori per i cicli for
	int l;        // contatore per il while, scorre da sinistra a destra bini
	int dim;      // lunghezza della scrittura binaria di i	
	char *bini;   // puntatora al vettore che contiene i in binario 
	int hw;	      // variabile per il peso di hamming (hamming weight) di i
	int n1;	      // contatore che mi indica quanti 1 ho già incontrato	
	
	if (i<0 || k<1){
		printf("errore negli input di bk(i)");
		exit(0);
	}
	else if (i==0){
		return -1;    // se i=0, il suo peso di hamming è < k
	}
 	else{
		dim = (int)(log(i)/log(2))+1;
		bini = malloc(dim * sizeof(char)); 

	// calcolo di i in binario con il bit meno significativo a sinistra
		for(s=0; s<dim; s++){
			bini[s] = i%2;
			i=i/2;
		}
	} 

	hw=0;	  // inizializzo il peso di hamming a 0

	// calcolo il peso di hamming di i

	for (j=0; j<dim; j++){
		hw = hw + bini[j];
	}

	// calcolo bk(i)
	if (hw < k){
		free(bini);
		return -1;
	}
	else{		
		n1=0;
		l=0;
		/* controllo su n1 perchè se sono in questo else, k<=hw, e quindi se mi         		        fermo al k-esimo 1 sicuramente non esco dal range */
		while (n1<k){
			if (bini[l]==1){
				n1++;
				if(n1==k){
					free(bini);
					return l;
				}
			}
			l++;
		}
	}
	
}
