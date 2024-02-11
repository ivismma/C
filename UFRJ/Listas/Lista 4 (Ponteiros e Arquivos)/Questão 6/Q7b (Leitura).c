/*
Quest�o 6)
b) Escreva outro programa que ofere�a a op��o de ler um dos dois arquivos criados no exerc�cio
anterior, leia o arquivo informado e ent�o imprima os dados dos tr�s alunos na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct {
	long int dre; // N�mero de identifica��o utilizada pela UFRJ.
	char nome[26], sobrenome[26]; // Obs: aumentei o tamanho do vetor, em rela��o ao que a quest�o pediu.
	short int idade;
	float peso, altura;
} tAluno;

int main(void){
	int n;
	
	printf("Digite:\n- 0 para ler o arquivo de texto\n- 1 para ler o arquivo binario\n\n--> ");
	scanf("%d", &n);
	
	FILE *arquivo;
	if(!n){ // Leitura de texto
		printf("\nLeitura do arquivo de texto:\n");
		char c;
		arquivo = fopen("dados.txt", "r");
		if(!arquivo){
			printf("Erro na abertura do arquivo."); return -1;
		} 
		// Vai imprimir exatamente como est� no arquivo de texto.
		while( (c = fgetc(arquivo)) != EOF) putchar(c);
		fclose(arquivo); // Fechamento do arquivo.
	}
	else{ // Leitura bin�ria (com nova formata��o):
		
		printf("\nLeitura do arquivo binario:\n");
		arquivo = fopen("dados.dat", "rb");
		if(!arquivo){
			printf("Erro na abertura do arquivo."); return -1;
		}
		tAluno aluno[TAM]; // Vetor de tAluno.
		
		fread(aluno, sizeof(tAluno), TAM, arquivo); // Leitura dos tr�s alunos, inseridos no vetor aluno.
		printf("Leitura realizada!\n\n");
		fclose(arquivo); // Fechamento do arquivo.
		
		for(int i = 0; i < TAM; ++i){ // Dados imprimidos na tela.
			printf("------- Aluno %d -------\n", i + 1);
			printf("Nome: %s %s\n", aluno[i].nome, aluno[i].sobrenome);
			printf("DRE: %ld\n", aluno[i].dre);
			printf("Idade: %hd anos\n", aluno[i].idade);
			printf("Peso: %.1f Kg\n", aluno[i].peso);
			printf("Altura: %.2fm", aluno[i].altura);
			printf("\n");
		}
	}
	return 0;
}
