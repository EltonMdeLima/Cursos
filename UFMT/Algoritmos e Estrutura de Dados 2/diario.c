#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição de constantes
#define MAX_ALUNOS 100
#define MAX_DIAS 31
#define MAX_NOME 50

// Estrutura para armazenar os dados dos alunos
typedef struct {
    char nome[MAX_NOME];
    int presencas[MAX_DIAS];
    float notas[MAX_DIAS];
} Aluno;

// Prototipos de funções
void inicializarAlunos(Aluno alunos[], int quantidade);
void registrarPresenca(Aluno alunos[], int quantidade, int dia);
void registrarNota(Aluno alunos[], int quantidade, int dia);
void salvarDados(Aluno alunos[], int quantidade, int dias);
void carregarDados(Aluno alunos[], int *quantidade, int *dias);
void mostrarRelatorio(Aluno alunos[], int quantidade, int dias);
int obterDiaAtual();

int main() {
    Aluno alunos[MAX_ALUNOS];
    int quantidadeAlunos = 0;
    int dias = 0;
    int opcao, dia;

    // Carrega dados previamente salvos (se existirem)
    carregarDados(alunos, &quantidadeAlunos, &dias);

    // Verifica se já há um número predefinido de alunos
    if (quantidadeAlunos == 0) {
        printf("Digite a quantidade de alunos: ");
        scanf("%d", &quantidadeAlunos);
        inicializarAlunos(alunos, quantidadeAlunos);
    }

    dia = obterDiaAtual();

    do {
        printf("\nMenu:\n");
        printf("1. Registrar Presença\n");
        printf("2. Registrar Nota\n");
        printf("3. Mostrar Relatório\n");
        printf("4. Salvar Dados\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarPresenca(alunos, quantidadeAlunos, dia);
                if (dia >= dias) dias = dia + 1;
                break;
            case 2:
                registrarNota(alunos, quantidadeAlunos, dia);
                if (dia >= dias) dias = dia + 1;
                break;
            case 3:
                mostrarRelatorio(alunos, quantidadeAlunos, dias);
                break;
            case 4:
                salvarDados(alunos, quantidadeAlunos, dias);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

// Função para inicializar os alunos
void inicializarAlunos(Aluno alunos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        for (int j = 0; j < MAX_DIAS; j++) {
            alunos[i].presencas[j] = 0;
            alunos[i].notas[j] = 0.0;
        }
    }
}

// Função para registrar a presença
void registrarPresenca(Aluno alunos[], int quantidade, int dia) {
    for (int i = 0; i < quantidade; i++) {
        printf("Aluno %s está presente no dia %d? (1 para sim, 0 para não): ", alunos[i].nome, dia);
        scanf("%d", &alunos[i].presencas[dia]);
    }
}

// Função para registrar a nota
void registrarNota(Aluno alunos[], int quantidade, int dia) {
    for (int i = 0; i < quantidade; i++) {
        printf("Digite a nota do aluno %s no dia %d: ", alunos[i].nome, dia);
        scanf("%f", &alunos[i].notas[dia]);
    }
}

// Função para salvar os dados em um arquivo
void salvarDados(Aluno alunos[], int quantidade, int dias) {
    FILE *file = fopen("dados_alunos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(file, "%d %d\n", quantidade, dias);
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%s\n", alunos[i].nome);
        for (int j = 0; j < dias; j++) {
            fprintf(file, "%d %.2f\n", alunos[i].presencas[j], alunos[i].notas[j]);
        }
    }
    fclose(file);
    printf("Dados salvos com sucesso!\n");
}

// Função para carregar os dados de um arquivo
void carregarDados(Aluno alunos[], int *quantidade, int *dias) {
    FILE *file = fopen("dados_alunos.txt", "r");
    if (file == NULL) {
        printf("Nenhum dado previamente salvo encontrado.\n");
        return;
    }
    fscanf(file, "%d %d", quantidade, dias);
    for (int i = 0; i < *quantidade; i++) {
        fscanf(file, "%s", alunos[i].nome);
        for (int j = 0; j < *dias; j++) {
            fscanf(file, "%d %f", &alunos[i].presencas[j], &alunos[i].notas[j]);
        }
    }
    fclose(file);
    printf("Dados carregados com sucesso!\n");
}

// Função para mostrar o relatório dos alunos
void mostrarRelatorio(Aluno alunos[], int quantidade, int dias) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nRelatório do Aluno: %s\n", alunos[i].nome);
        printf("Dia\tPresença\tNota\n");
        for (int j = 0; j < dias; j++) {
            printf("%d\t%d\t\t%.2f\n", j, alunos[i].presencas[j], alunos[i].notas[j]);
        }
    }
}

// Função para obter o dia atual baseado no cronograma
int obterDiaAtual() {
    // Pode-se implementar uma lógica mais complexa para obter o dia atual
    // Aqui está um exemplo simples que retorna um dia fixo para demonstração
    // Em um cenário real, pode-se usar a data atual e compará-la com o cronograma
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Exemplo simples: retorna o dia do mês atual (de 0 a MAX_DIAS-1)
    return tm.tm_mday - 1;
}
