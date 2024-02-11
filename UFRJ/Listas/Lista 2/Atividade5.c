/*Quest�o 5) Fa�a um programa que leia um n�mero natural n e dois n�meros naturais a e b
diferentes de 0 e apresente na tela em ordem crescente os n primeiros naturais que s�o m�ltiplos
de a ou de b.
Exemplo: Para n = 6, a = 2 e b = 3 dever� ser apresentada a sequ�ncia: 0 2 3 4 6 8.

O programa dever� conter as 3 seguintes fun��es:

int ehMultiplo(int r, int s); //verifica se r � m�ltiplo de s (retorna 1 se sim; 0 caso contr�rio)

void multiplos(int q, int x, int y); //imprime os q primeiros m�ltiplos de x ou de y.

int main(); //l� as entradas do usu�rio e chama a fun��o �multiplos�.*/

#include <stdio.h>

int ehMultiplo(int r, int s);
void multiplos(int q, int x, int y);


int main(){
	int n,a,b;
	do{ // DEFESA
		printf("Digite um n�mero natural n diferente de zero: ");
		scanf("%d", &n);
	} while(n == 0);
	
	do{ // DEFESA
		printf("Digite um n�mero natural a diferente de zero: ");
		scanf("%d", &a);
	} while(a == 0);
	
	do{ // DEFESA
		printf("Digite um n�mero natural b diferente de zero: ");
		scanf("%d", &b);
	} while(b == 0);
	
	multiplos(n,a,b);
	
	return 0;
}

int ehMultiplo(int r, int s){
	if( !(s%r) ){ 
		return 1; // � M�ltiplo
	} return 0; //N�o � m�ltiplo
}

void multiplos(int q, int x, int y){
	int z = 0;
	while(q){ // q � a quantidade de n�meros a ser exibido, enquanto ele for verdadeiro, continua procurando os m�ltiplos.
		if(ehMultiplo(x,z)){
			printf("%d ", z);
			--q; // 
			++z; // z � o n�mero a ser testado.
			continue;
		}
		if(ehMultiplo(y,z)){
			printf("%d ", z);
			--q;
			++z;
			continue;
		} ++z;
	}
}
