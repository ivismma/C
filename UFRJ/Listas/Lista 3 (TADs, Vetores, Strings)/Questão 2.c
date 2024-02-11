/*
Escreva um programa que inverta uma string qualquer de entrada (do teclado), e
imprima a string invertida. Por exemplo: para a string de entrada �Professor� (9 caracteres + caractere
nulo), dever� ser impresso �rosseforP� pela simples leitura sequencial, a partir do �ndice 0 da string j�
invertida at� o �ndice 9 da mesma.
*/

#include <stdio.h>
#include <string.h>

// Fun��o que inverte e imprime a string.
void inverteString(char s[], int tam){
	int i = 0, j = tam-1; // j = �ndice anterior ao '\0'.
	char aux[tam]; // Auxiliar que ir� guardar a string invertida.
	
	// tam � o tamanho de s[] excluindo o '\0'.
	while(i < tam) aux[i++] = s[j--];
	aux[i] = '\0'; // i j� foi incrementado na �ltima itera��o p/ o �ltimo �ndice.
	
	// Exerc�cio pede impress�o por for() de caracter.
	for(i = 0; i < tam; ++i) printf("%c", aux[i]);
}

int main(){
	char str[20+1];
	puts("Digite uma palavra de ate 20 caracteres:");
	gets(str);
	
	inverteString(str, strlen(str));
	return 0;
}
