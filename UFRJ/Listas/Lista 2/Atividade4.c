/* Quest�o 4) Vimos em aula que a avalia��o de uma express�o l�gica em C d�-se da esquerda
para a direita, e � encerrada t�o logo seu valor de verdade seja obtido.
? O que ser� impresso ap�s a execu��o de cada uma das linhas onde h� um coment�rio de
interroga��o (�// ?�) � direita?
Primeiro TENTE determin�-los mentalmente e ESCREVA em cada linha o que voc� espera como
resultado. Somente depois disso VERIFIQUE em um programa se a sua resposta � correta. Algo saiu
diferente do esperado? Se sim, procure ENTENDER o porqu�, e efetue as corre��es necess�rias na
sua resposta final.
*/

#include<stdio.h>
int f(int a);

int main() {
	int a = 2, b = 3, c = 4;
	f(a) || f(b) && f(c); // Ser� impresso: 2
	f(a) || (f(b) && f(c)); // Ser� impresso: 2 
	(f(a) || f(b)) && f(c); // Ser� impresso:  2 4
	(a > b) && f(a) || f(b) && f(c); // Ser� impresso: 3 4
	(b > a) && f(a) || f(b) && f(c); // Ser� impresso: 2
	((b > a) && f(a) || f(b)) && f(c); // Ser� impresso: 2 4 <-- f(c)
	return 0;
}

int f(int a) {
	printf("%d ", a);
	return a;
}
