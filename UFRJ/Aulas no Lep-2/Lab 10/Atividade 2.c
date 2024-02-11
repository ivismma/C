/*
Atividade 2: Os alunos de uma turma fizeram duas provas. Escreva um programa que leia do teclado
uma �nica string contendo o nome completo e as duas notas de um aluno, separados por espa�o,
calcule a m�dia aritm�tica dessas duas notas e imprima em seguida o nome do aluno e a m�dia
obtida. Use a fun��o �sscanf�, vista em nossa �ltima aula.
Permita que o programa aceite novas entradas at� que uma entrada inv�lida seja fornecida.
*/

/* Maneira de fazer antes de eu ver que o exerc�cio pedia o uso de sscanf.

// Essa fun��o cria a string nome que cont�m o nome completo e
// retorna o �ndice seguinte onde termina o nome do aluno.

int obtemNome(char dadosAluno[], char nome[]){
	int i = 0;
	
	while(dadosAluno[i] >= 'A' && dadosAluno[i] <= 'z')
	nome[i++] = dadosAluno[i];
	
	nome[i] = '\0';
	return i;
}
*/

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaInput(char v[], int n){
	int letras = 0, numeros = 0;
	for(int i = 0; i < n; ++i){
		// Verifica se possui uma letra, ou espa�o
		if( ((v[i] >= 'A' && v[i] <= 'Z') || (v[i] >= 'a' && v[i] <= 'z') || v[i] == ' ' ))
			++letras;
		else if(v[i] >= '0' && v[i] <= '9') // Verifica se � um n�mero.
			++numeros;
	}
	if(!letras || !numeros) 
		return FALSE; // Concluindo... Se n�o possui letras e/ou n�o possui n�meros, � inv�lida.
	return TRUE; // Caso nenhum erro tenha sido encontrado, a string � v�lida.
}
// Decidi utilizar ponteiros.
int main(){ 
	char *nome, dadosAluno[81]; // Dados Aluno ser� o que cont�m o nome completo e duas notas.
	float n1, n2, media;
	nome = (char *) malloc(76 * sizeof(char)); // Nome de at� 75 caracteres.
	
	while(1){ // Loop at� que uma entrada inv�lida seja inserida.
		printf("Insira o nome completo do aluno e suas duas notas (separados por espa�o):\n");
		gets(dadosAluno);
		
		// "Permita que o programa aceite novas entradas at� que uma entrada inv�lida seja fornecida."
		if( !verificaInput(dadosAluno, strlen(dadosAluno)) ){
			printf("O programa foi encerrado pois o usu�rio inseriu uma entrada inv�lida.");
			break;
		} 
		sscanf(dadosAluno, "%[^0-9]", nome);
		nome = (char *) realloc(nome, strlen(nome)+1); // Realoca��o para otimiza��o de uso de mem�ria.
		sscanf(&dadosAluno[strlen(nome)], "%f %f", &n1, &n2);
		media = (n1+n2)/2;
		
		printf("\nNome do aluno: %s\nM�dia aritm�tica: %.2f\n\n", nome, media);
	}
	
	return 0;
}
