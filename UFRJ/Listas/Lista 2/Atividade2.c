/*Escreva um programa em C que imprima uma figura como a mostrada abaixo. O
n�mero de linhas da figura deve ser informado pelo usu�rio, mas n�o pode ser maior que 10. N�o
crie uma fun��o espec�fica para isso (ou seja, simplesmente escreva toda a l�gica na main()).

// A imagem � como se fosse uma pir�mide de asteriscos.

Descri��o: Algoritmo que recebe um valor n e cria uma pir�mide de asteriscos com n linhas.
Entrada: Valor n (Quantidade de linhas da pir�mide).
Sa�da: A pir�mide em formato de asteriscos.
Defesa: Valor n deve ser um n�mero do intervalo [1,10].
*/

// Utilizar tudo na main.

#include <stdio.h>

int main(){
	int n,q,j=0, k=0;
	
	do{ // DEFESA
		printf("Digite um valor n entre 1 e 10: ");
		scanf("%d", &n);
	} while(n < 1 || n > 10);
	
	printf("\n");
	q = n; // q recebe a quantidade de linhas.
	
	for(int i=0; i < n; i++, j = 0, k = 0, q -= 1){
		while(j < q){ // Quantidade de espa�os inseridos at� a coloca��o dos asteriscos.
			printf(" ");
			++j;
		}
		while (k < 1+2*i){ // Quantidade de asteriscos que ser�o colocados na itera��o atual.
			printf("*");
			++k;
		}
		printf("\n"); // Pula uma linha para pr�xima itera��o de asteriscos.
		 // A cada passo, (i++, j=0, k = 0, q-=1), Nesse �ltimo, subtrai 1 do q.
	}

	return 0;
}
