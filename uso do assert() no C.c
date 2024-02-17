#include <stdio.h>
#include <assert.h>

// Exemplo de uso do assert no C.

int main(void){

	int x = 5;
	int y = 8;
	// Suponha que y nunca dever� ser menor que x durante a execu��o.
	// Al�m disso, haver� checagens durante a execu��o do programa.
	
	assert(y > x); // OK.
	printf("%d\n%d\n", x, y);
	
	// Exemplo de altera��o durante execu��o.
	int i = 0;
	while(i++ < 10){
		x += 2;
		++y;
		printf("Iteracao: %d\n", i);
		assert(y > x); // Checagem.
	}
	// O programa ir� ser executado at� a terceira itera��o, Assertion Failed.
	// x ultrapassou y em uma determinada checagem, quebra de regra.

	return 0;
}
