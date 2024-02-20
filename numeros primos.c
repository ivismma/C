#include <stdio.h>
#include <stdbool.h>

// Exibe todos os n�meros primos at� o valor n.
void numerosPrimos(int n);

int main(void){
	int n;

	printf("Digite um valor maior ou igual a 2: ");
	scanf("%d", &n);
	if(n < 2){
		puts("Entrada invalida.");
		return 1;
	} 
	
	numerosPrimos(n);

	return 0;
}

void numerosPrimos(int n){            // ITERATIVO
	int numAtual = 2; // 1� n�mero primo.
	
	while(numAtual <= n){
		bool primo = true; // inicia cada n� presumindo que seja primo.
		for(int i = numAtual/2; i > 1; --i){
			if(numAtual%i == 0){ // Encontrou um divis�vel.
				primo = false;
				break;
			}
		}
		if(primo) printf("%d ", numAtual);
		++numAtual;
	}
	
	return;
}
