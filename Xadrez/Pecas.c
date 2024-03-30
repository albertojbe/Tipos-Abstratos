#include <stdio.h>
#include <stdbool.h>

void imprimir(char* texto) {
    printf("%s\n", texto);
}

typedef struct {
    char* tipo;
    char* cor;
    int linha;
    int coluna;
} Pecas;

void inicializarPecas(Pecas* peca, char* tipo, char* cor, int linha, int coluna) {
    peca->tipo = tipo;
    peca->cor = cor;
    peca->linha = linha;
    peca->coluna = coluna;
}

void imprimirInformacoes(Pecas* peca) {
    imprimir("Tipo da peça: ");
    imprimir(peca->tipo);
    imprimir("Cor da peça: ");
    imprimir(peca->cor);
    printf("Posição: %d%d\n", peca->linha, peca->coluna);
}

typedef struct {
    Pecas super;
} Peao;

void inicializarPeao(Peao* peao, char* tipo, char* cor, int linha, int coluna) {
    inicializarPecas(&(peao->super), tipo, cor, linha, coluna);
}

bool verificarMovimento(Peao* peao, int novaLinha) {
    if ((peao->super.linha == 2 || peao->super.linha == 7) && (novaLinha == 4 || novaLinha == 5)) {
        return true;
    } else if (novaLinha - peao->super.linha == 1 || peao->super.linha - novaLinha == 1) {
        return true;
    } else {
        return false;
    }
}

void movimentarPeao(Peao* peao, int novaLinha) {
    if (verificarMovimento(peao, novaLinha)) {
        peao->super.linha = novaLinha;
        imprimir("Movimento Realizado");
    } else {
        imprimir("Movimento Inválido");
    }
}

void capturarPeca(Peao* peao, int colunaCapturar, int linhaCapturar, char* pecaCapturada) {
    if (((colunaCapturar - peao->super.coluna == 1) || (peao->super.coluna - colunaCapturar == 1)) && ((linhaCapturar - peao->super.linha == 1) || (peao->super.linha - linhaCapturar == 1))) {
        printf("A peça %s foi capturada com sucesso na linha %d coluna %d!\n", pecaCapturada, linhaCapturar, colunaCapturar);
    } else {
        imprimir("Movimento inválido!");
    }
}
