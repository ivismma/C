/*
Atividade 3 (OBI 2011):
Pedrinho � um garoto fascinado por jogos de tabuleiro. Nas f�rias de janeiro, ele aprendeu um jogo
chamado Campo Minado, que � jogado em um tabuleiro com N c�lulas dispostas na horizontal. O
objetivo desse jogo � determinar, para cada c�lula do tabuleiro, o n�mero de minas explosivas nos
arredores da mesma (que s�o a pr�pria c�lula e as c�lulas imediatamente vizinhas � direita e �
esquerda, caso existam). Por exemplo, considere um tabuleiro com 5 c�lulas, configuradas da
seguinte forma (# significa �mina�):

[][#][#][][#]

A primeira c�lula n�o possui nenhuma mina explosiva, mas � vizinha de uma c�lula que possui. Nos
arredores da segunda c�lula temos duas minas (ela mesma e a vizinha � direita), e o mesmo
acontece para a terceira e quarta c�lulas; a quinta c�lula s� tem uma mina explosiva em seus
arredores. A resposta para o caso acima seria:

[1][2][2][2][1]

Pedrinho sabe que voc� est� cursando Prog-I e resolveu lhe pedir para escrever um programa em C
que, dado um tabuleiro, imprima o n�mero de minas na vizinhan�a de cada posi��o.
A entrada dever� ser lida de teclado. A primeira linha da entrada cont�m um inteiro N indicando o
n�mero de c�lulas no tabuleiro. O tabuleiro � dado na pr�xima linha. O i-�simo elemento da
segunda linha cont�m 0 se n�o existe uma mina na i-�sima c�lula do tabuleiro e 1 caso contr�rio.
A sa�da � composta por N valores e dever� ser escrita na tela. O i-�simo valor da sa�da cont�m o
n�mero de minas explosivas nos arredores da i-�sima c�lula do tabuleiro.
*/

#include <stdio.h>

void verificaMinas(int v[], int res[], int n){ // Retorna Vetor com o resultado de minas aos arredores do vetor inicial (sa�da).
	int soma = 0, 
	i = 0;
	/*
	Ideia do algoritmo: o vetor resultado (da quantidade minas ao redor) inicia como zero por causa da fun��o zeraVetor(),
	a cada checagem uma express�o l�gica � testada (se tem minas ao redor), ela retorna 1 se for positiva e
	0 caso contr�rio, cada itera��o de res[i] vai terminar com o total de minas ao redor somadas.
	*/
	
	// Checagem de v[] para i = 0, pois i = -1 n�o existe
	res[i] += (v[i] == 1);
	res[i] += (v[i+1] == 1);
	++i;
	
	// Checagem de v[] para i = 1 at� pen�ltimo �ndice.
	do{
		res[i] += (v[i-1] == 1);
		res[i] += (v[i] == 1);
		res[i] += (v[i+1] == 1);
		++i;
	} while(i < n-1); // Usando o do-while, a fun��o fica otimizada economizando uma checagem desnecess�ria (a primeira).
	
	// Checagem de v[] para i = �ltimo �ndice, pois n�o existe vetor de v[n];
	res[i] += (v[i-1] == 1);
	res[i] += (v[i] == 1);
}


/*void verificaMinasRec(int v[], int res[], int n, int i) {
    if (i == n)
        return;
        
    res[i] += (v[i] == 1);
    res[i] += (i > 0 && v[i - 1] == 1);
    res[i] += (i < n - 1 && v[i + 1] == 1);
    verificaMinasRec(v, res, n, i + 1);
}*/

void zeraVetor(int v[], int n){
	for(int i = 0;i < n;++i) v[i] = 0;
}

void exibirVetor(int v[], int n){
	for(int i = 0; i < n; ++i) printf("%d ", v[i]);
}

int main(){
	int n;
	scanf("%d", &n); // 1� linha: tamanho N 
	int v[n], res[n]; zeraVetor(res, n); // Zera vetor resultado de minas ao redor.
	
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]); // 2� linha: Preenche vetor.
	verificaMinas(v, res, n);
	exibirVetor(res, n); // 3� linha: Resultado.
}
