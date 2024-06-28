#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Igualar um ponteiro *alocado* � sua tentativa de realloc() pode implicar em perd�-lo
// em caso de uma falha na realoca��o, perdendo o ponteiro original para os dados, pois 
// realloc() retorna NULL quando falha na realoca��o e ent�o seria atribu�do NULL a p
// (os dados permanecem l�, alocados, mas voc� perdeu o endere�o do bloco).

// Solu��o: Criar um ponteiro tempor�rio para armazenar o retorno de realloc(), e caso a
// realoca��o tenha �xito, atribuir ao ponteiro original =)

int main(void){
	
	int *p = (int*) malloc(100*sizeof(int));
	if(p == NULL){
		printf("Falha na 1a alocacao.\n");
		return 1;
	}
	
	{         // 1� realoca��o (1000 ints) - v�lido.
		int *novo = (int*) realloc(p, 1000*sizeof(int));
		
		if(novo == NULL) printf("Falha na 1a realocacao\n");
		else p = novo; // OK
	}
	
	{        // 2� realoca��o (10^40 Bytes) - prov�vel erro.
		int *novo = (int*) realloc(p, (size_t) pow(10,40)); 
		
		if(novo == NULL) printf("Falha na 2a realocacao\n");
		else p = novo; // OK
	}
	
	if(p != NULL)
		printf("O ponteiro original foi preservado: %p\n", p);

	return 0;
}
