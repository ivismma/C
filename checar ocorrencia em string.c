#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Receber uma string e uma sequ�ncia de caracteres, em seguida 
// verificar se est� contido na string.

bool palavraAparece(char *str1, char *str2);

int main(void){
	char str1[50];
	char str2[25];
	
	printf("Digite uma frase: "); // at� 49 caracteres
	fgets(str1,50,stdin);
	printf("Digite uma palavra ou sequencia de caracteres: "); // at� 24.
	scanf("%s", str2);
	
	if(palavraAparece(str1, str2))
		printf("\"%s\" aparece na frase.", str2);
	else
		printf("\"%s\" nao aparece na frase.", str2);

	return 0;
}

// Ambos ser�o transformados em minusculo para melhorar verifica��o

bool palavraAparece(char *str1, char *str2){
	int tam = strlen(str2),            // tam � o tamanho da sequ�ncia procurada.
	cont = 0, i = 0;
	while(str1[i] != '\0'){
		char c  = tolower(str1[i++]);  // Caracter atual.
		char c2 = tolower(str2[cont]); // Caracter atual da sequ�ncia procurada.
		if(c == c2){
			if(cont++ == tam-1) return true; // Sequ�ncia encontrada.
		}
		else cont = 0;
	}
	return false;  // N�o encontrou.
}
