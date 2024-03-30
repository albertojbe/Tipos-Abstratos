#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int id;
    char cargo[50];
    float salario;
    struct Departamento *departamento;
} Empregados;

typedef struct Departamento {
    char nome[50];
    int id;
    char localizacao[50];
    Empregados **empregados;
    int num_empregados;
} Departamento;

Departamento* criarDepartamento(char nome[], int id, char localizacao[]) {
    Departamento *depto = (Departamento*)malloc(sizeof(Departamento));
    if (depto == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para Departamento.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(depto->nome, nome);
    depto->id = id;
    strcpy(depto->localizacao, localizacao);
    depto->empregados = NULL;
    depto->num_empregados = 0;
    return depto;
}

void adicionarEmpregado(Departamento *departamento, Empregados *empregado) {
    departamento->empregados = (Empregados**)realloc(departamento->empregados, (departamento->num_empregados + 1) * sizeof(Empregados*));
    if (departamento->empregados == NULL) {
        fprintf(stderr, "Erro: Falha ao realocar memória para Empregados do Departamento.\n");
        exit(EXIT_FAILURE);
    }
    departamento->empregados[departamento->num_empregados] = empregado;
    departamento->num_empregados++;
}

void imprimirEmpregados(Departamento *departamento) {
    printf("Lista de Empregados:\n\n");
    for (int i = 0; i < departamento->num_empregados; i++) {
        Empregados *empregado = departamento->empregados[i];
        printf("Nome: %s\n", empregado->nome);
        printf("ID: %d\n", empregado->id);
        printf("Cargo: %s\n", empregado->cargo);
        printf("Salário: %.2f\n\n", empregado->salario);
    }
}

void informacoesDepartamento(Departamento *departamento) {
    printf("Nome: %s\n", departamento->nome);
    printf("ID: %d\n", departamento->id);
    printf("Localização: %s\n", departamento->localizacao);
}

int main() {
    Empregados *Alberto = (Empregados*)malloc(sizeof(Empregados));
    Empregados *Carlos = (Empregados*)malloc(sizeof(Empregados));
    Departamento *Recepcao = criarDepartamento("Recepção", 1, "Entrada");

    strcpy(Alberto->nome, "Alberto");
    Alberto->id = 18;
    strcpy(Alberto->cargo, "Atendente");
    Alberto->salario = 1300.00f;
    Alberto->departamento = NULL;

    strcpy(Carlos->nome, "Carlos");
    Carlos->id = 18;
    strcpy(Carlos->cargo, "Atendente");
    Carlos->salario = 1300.00f;
    Carlos->departamento = NULL;

    adicionarEmpregado(Recepcao, Alberto);
    adicionarEmpregado(Recepcao, Carlos);

    imprimirEmpregados(Recepcao);
    informacoesDepartamento(Recepcao);

    free(Alberto);
    free(Carlos);
    free(Recepcao->empregados);
    free(Recepcao);

    return 0;
}
