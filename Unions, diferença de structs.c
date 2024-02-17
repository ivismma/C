#include <stdio.h>
#include <string.h>

struct Aluno{ // Struct armazena quantos forem necess�rios simultaneamente.
	char nome[60];
	long long matricula;      // Total: 80 bytes
	float CR;                   
};                        

union Temperatura{ // Union s� armazena um dado por vez.
	double celsius;
	double fahrenheit;       // Total: 8 bytes 
	double kelvin;           // Se fosse struct: 24 bytes.
};

int main(void){
	struct Aluno aluno;
	union Temperatura temp;
	
	strcpy(aluno.nome, "Joao");
	aluno.matricula = 23619723282;
	aluno.CR = 7.77;
	
	printf("Struct:\n%s | %lld | %f\n", aluno.nome, aluno.matricula, aluno.CR);
	// Ser� impresso os tr�s dados.
	
	temp.celsius = 40;
	temp.fahrenheit = 104;
	temp.kelvin = 313.15;  // <-- �ltima atribui��o.
	
	printf("Union: %f | %f | %f", temp.celsius, temp.fahrenheit, temp.kelvin);
	
	// Ser� impresso da Union o valor Kelvin tr�s vezes pois uma union armazena somente
	// um dado por vez, que nesse caso o �ltimo inserido foi a da unidade Kelvin.
	// � �til para economizar espa�o quando s� ir� ser utilizado um dos dados por vez,
	// pois este ir� sobrescrever o dado atual e permanecer como �nico na Union.
	
	return 0;
}
