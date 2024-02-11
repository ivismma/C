// Lista 3
/*
Quest�o 1) Um pal�ndromo � essencialmente uma palavra ou n�mero que, ao se ler �de tr�s para
frente�, permanece inalterada. Por exemplo: �radar�, �reviver�, 1331, 90209, etc. Escreva um programa
em C que leia uma string do teclado e determine se a mesma trata-se de um pal�ndromo.
*/

#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <string.h>

int checaPalindromo(char s[], int tam){
	int i = 0, j = tam-1; // quando j = tam-1, isso significa o �ltimo caracter antes do '\0'.
	
	while(i < j) // enquanto i e j n�o se encontrarem, i percorre pela esquerda e j pela direita. i --> <-- j
		if(s[i++] != s[j--]) // Se s[i] N�O for igual a s[j] em uma das itera��es, ent�o n�o � pal�ndromo, retorna FALSE.
			return FALSE;
	return TRUE; // Caso n�o tenha encontrado nenhuma diferen�a, significa que � um pal�ndromo.
}

int main(){
	char str[25+1];
	puts("Teste de pal�ndromos - Digite uma palavra: ");
	gets(str);
	if(checaPalindromo(str, strlen(str)) )
		printf("%s eh um palindromo!", str);
	else
		printf("%s N�O eh um palindromo!", str);
	return 0;
}
