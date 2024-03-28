#include <stdio.h>
#include <string.h>


typedef struct
{
    char titulo[100];
    char autor[50];
    int ano;
    int copias;
}Biblioteca;

void inicializar(Biblioteca *livro, char tituloLivro[100], char autorLivro, int anoLivro, int copiasLivro){
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



int main{
    return 0;
}
