#include <stdio.h>
#include <string.h>


typedef struct
{
    char titulo[100];
    char autor[50];
    int ano;
    int copias;
}Biblioteca;

void inicializar(Biblioteca *livro, char tituloLivro[100], char autorLivro[50], int anoLivro, int copiasLivro){
    strcpy(livro->titulo, tituloLivro);
    strcpy(livro->autor, autorLivro);
    livro->ano = anoLivro;
    livro->copias = copiasLivro;

}
int emprestarCopia(Biblioteca *livro){
    return --livro->copias;
}
int devolverCopia(Biblioteca *livro){
    return ++livro->copias;
}
void verificarCopias(Biblioteca *livro){
    if (livro->copias > 0){
        printf("Ha: %d copias.", livro->copias);
    }
    else{
        printf("Nao ha copias");
    }
}
void imprimirDetalhes(Biblioteca *livro){
    printf("Nome do livro: %s\n", livro->titulo);
    printf("O autor do livro e: %s\n", livro->autor);
    printf("O ano de lancamento do livro e: %d\n", livro->ano);
    printf("O numero de copias e: %d\n", livro->copias);
}

int main(){
    Biblioteca ASOIAF;
    inicializar(&ASOIAF, "Guerra dos Tronos", "George Martin", 1960, 5);
    imprimirDetalhes(&ASOIAF);
    return 0;
}
