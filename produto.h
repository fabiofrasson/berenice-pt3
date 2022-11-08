#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <time.h>
#include <stdbool.h>
#include "geral.h"

// Definição da struct
typedef struct produto {
    int codigo;
    char nomeProduto[25];
    float valorUnitario;
    int quantEstoque;
    int quantVendida;
};

// Corpo da função
void salvarProdutosCadastrados(struct produto *arr, int tam) {

    char *filename = "produtos.txt";

    FILE *fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }

    fprintf(fp, "quantidade_produtos\n");

    for(int i = 0; i < tam; i++) {
        fprintf(fp, "\n%d\n", arr[i].codigo);
        fprintf(fp, "%s\n", arr[i].nomeProduto);
        fprintf(fp, "%.2f\n", arr[i].valorUnitario);
        fprintf(fp, "%d\n", arr[i].quantEstoque);
        fprintf(fp, "%d\n", arr[i].quantVendida);
    }

    fclose(fp);
}

int vendaProdutos() {

    int opcao = 0, counter = 0;

    while (opcao != 1 && opcao != 2 && opcao != 3) {
        if(counter > 0) {
            printf("Opcao invalida.\n");
            transicao(1000);
        }
        imprimeOpcoesSubmenuVendas();
        scanf("%d", &opcao);
        getchar();
        counter++;
    }
    return opcao;
}

void imprimeOpcoesSubmenuVendas() {
    printf("1. Realizar venda\n");
    printf("2. Relatorio de vendas\n");
    printf("3. Voltar\n\n");
}

void realizarVenda(struct produto *arr, int *tam) {

    int codigoProduto, quantidade;

    printf("Pos 0: %d\n", arr[0].quantEstoque);
    printf("Pos 1: %d\n", arr[1].quantEstoque);
    printf("Pos 2: %d\n", arr[2].quantEstoque);
    printf("Pos 3: %d\n", arr[3].quantEstoque);
    printf("Pos 4: %d\n", arr[4].quantEstoque);

    if(arr[0].quantEstoque == 0 && arr[1].quantEstoque == 0 && arr[2].quantEstoque == 0 && arr[3].quantEstoque == 0 && arr[4].quantEstoque == 0) {
        printf("Não há itens disponíveis para venda, retornando ao menu principal.");
        delay(1000);
        return 0;
        // Trabalhar retorno ao menu principal
    }

    printf("Digite o código do produto que deseja vender:\n");
    exibirProdutos(&arr, &tam, true);
    scanf("%d", &codigoProduto);

    while(codigoProduto != arr[0].codigo && codigoProduto != arr[1].codigo && codigoProduto != arr[2].codigo && codigoProduto != arr[3].codigo && codigoProduto != arr[4].codigo) {
        printf("Codigo invalido, digite um codigo valido.\n");
        exibirProdutos(&arr, &tam, true);
        scanf("%d", &codigoProduto);
    }

    printf("Agora, digite a quantidade:\n");
    scanf("%d", &quantidade);

    while(quantidade <= 0) {
        printf("Quantidade invalida, digite uma quantidade acima de zero:\n");
        scanf("%d", &quantidade);
    }
}

void salvarProdutosVendidos(struct produto *arr, int tam) {

    char filename[40];

    struct tm *timenow;

    time_t now = time(NULL);
    timenow = gmtime(&now);

    strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.txt", timenow);

    FILE *fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }

    fprintf(fp, "produtos_vendidos\n");

    for(int i = 0; i < tam; i++) {
        fprintf(fp, "\n%d\n", arr[i].codigo);
        fprintf(fp, "%s\n", arr[i].nomeProduto);
        fprintf(fp, "%.2f\n", arr[i].valorUnitario);
        fprintf(fp, "%d\n", arr[i].quantEstoque);
        fprintf(fp, "%d\n", arr[i].quantVendida);
    }

    fclose(fp);
}

void exibirProdutos(struct produto *arr, int tam, bool relatorio) {

    if(relatorio == true) {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(Código)\tProduto\t\tEstoque\t\tVendidos\tTotal\n");
        printf("\t\t%d\t\t%s\t%d\t\t%d\t\tR$ %.2f\n", arr[0].codigo, arr[0].nomeProduto, arr[0].quantEstoque, arr[0].quantVendida, (arr[0].valorUnitario * arr[0].quantVendida));
        printf("\t\t%d\t\t%s\t%d\t\t%d\t\tR$ %.2f\n", arr[1].codigo, arr[1].nomeProduto, arr[1].quantEstoque, arr[1].quantVendida, (arr[1].valorUnitario * arr[1].quantVendida));
        printf("\t\t%d\t\t%s\t%d\t\t%d\t\tR$ %.2f\n", arr[2].codigo, arr[2].nomeProduto, arr[2].quantEstoque, arr[2].quantVendida, (arr[2].valorUnitario * arr[2].quantVendida));
        printf("\t\t%d\t\t%s\t\t%d\t\t%d\t\tR$ %.2f\n", arr[3].codigo, arr[3].nomeProduto, arr[3].quantEstoque, arr[3].quantVendida, (arr[3].valorUnitario * arr[3].quantVendida));
        printf("\t\t%d\t\t%s\t\t%d\t\t%d\t\tR$ %.2f\n", arr[4].codigo, arr[4].nomeProduto, arr[4].quantEstoque, arr[4].quantVendida, (arr[4].valorUnitario * arr[4].quantVendida));
        printf("---------------------------------------------------------------------------------------------\n");
    } else {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(Código)\tNome do Item\t\tValor(Unidade)\t\tEstoque\n");
        printf("\t\t%d\t\t%s\t\tR$ %.2f\t\t\t%d\n", arr[0].codigo, arr[0].nomeProduto, arr[0].valorUnitario, arr[0].quantEstoque);
        printf("\t\t%d\t\t%s\t\tR$ %.2f\t\t\t%d\n", arr[1].codigo, arr[1].nomeProduto, arr[1].valorUnitario, arr[1].quantEstoque);
        printf("\t\t%d\t\t%s\t\tR$ %.2f\t\t\t%d\n", arr[2].codigo, arr[2].nomeProduto, arr[2].valorUnitario, arr[2].quantEstoque);
        printf("\t\t%d\t\t%s\tR$ %.2f\t\t\t%d\n", arr[3].codigo, arr[3].nomeProduto, arr[3].valorUnitario, arr[3].quantEstoque);
        printf("\t\t%d\t\t%s\t\tR$ %.2f\t\t\t%d\n", arr[4].codigo, arr[4].nomeProduto, arr[4].valorUnitario, arr[4].quantEstoque);
        printf("---------------------------------------------------------------------------------------------\n");
    }
}

#endif // PRODUTO_H_INCLUDED
