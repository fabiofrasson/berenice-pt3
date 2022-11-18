#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include "produto.h"

void delay(int milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void transicao(int milisegundos) {
    delay(milisegundos);
    limparTela();
}

void limparTela() {
#ifdef linux
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

void salvarProdutosCadastrados() {

    if(p == NULL) {
        limparTela();
        printf("Nenhum produto foi cadastrado até o momento. Retornando ao menu principal.");
        transicao(1000);
        menu();
    }

    char *filename = "produtos.txt";

    FILE *fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Erro ao abrir o arquivo %s. Retornando ao menu principal.", filename);
        menu();
    }

    fprintf(fp, "%d\n", &numeroProdutos);

    for(int i = 0; i < &numeroProdutos; i++) {
        fprintf(fp, "\n%d\n", &p[i].codigo);
        fprintf(fp, "%s\n", &p[i].nomeProduto);
        fprintf(fp, "%.2f\n", &p[i].valorUnitario);
        fprintf(fp, "%d\n", &p[i].quantEstoque);
        fprintf(fp, "%d\n", &p[i].quantVendida);
    }

    fclose(fp);

    printf("Produtos salvos no arquivo %s com sucesso! Retornando ao menu principal.");
    limparTela();
    menu();
}

int vendaProdutos() {

    int opcao = 0, counter = 0;

    while (opcao != 1 && opcao != 2 && opcao != 3) {
        if(counter > 0) {
            printf("Opção inválida.\n");
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
    printf("---------------------------------------------------------------------------------------------\n");
    printf("1. Realizar venda\n");
    printf("2. Relatório de vendas\n");
    printf("3. Voltar\n\n");
}

void realizarVenda() {

    int codigoProduto, quantidade;

    printf("Pos 0: %d\n", &p[0].quantEstoque);
    printf("Pos 1: %d\n", &p[1].quantEstoque);
    printf("Pos 2: %d\n", &p[2].quantEstoque);
    printf("Pos 3: %d\n", &p[3].quantEstoque);
    printf("Pos 4: %d\n", &p[4].quantEstoque);

    if(p[0].quantEstoque == 0 && p[1].quantEstoque == 0 && p[2].quantEstoque == 0 && p[3].quantEstoque == 0 && p[4].quantEstoque == 0) {
        printf("Não há itens disponíveis para venda, retornando ao menu principal.");
        delay(1000);
        menu();
    }

    printf("Digite o código do produto que deseja vender:\n");
    exibirProdutos(true);
    scanf("%d", &codigoProduto);

    while(codigoProduto != p[0].codigo && codigoProduto != p[1].codigo && codigoProduto != p[2].codigo && codigoProduto != p[3].codigo && codigoProduto != p[4].codigo) {
        printf("Codigo invalido, digite um codigo valido.\n");
        exibirProdutos(true);
        scanf("%d", &codigoProduto);
    }

    printf("Agora, digite a quantidade:\n");
    scanf("%d", &quantidade);

    while(quantidade <= 0) {
        printf("Quantidade invalida, digite uma quantidade acima de zero:\n");
        scanf("%d", &quantidade);
    }
}

void salvarProdutosVendidos() {

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

    for(int i = 0; i < numeroProdutos; i++) {
        fprintf(fp, "\n%d\n", &p[i].codigo);
        fprintf(fp, "%s\n", &p[i].nomeProduto);
        fprintf(fp, "%.2f\n", &p[i].valorUnitario);
        fprintf(fp, "%d\n", &p[i].quantEstoque);
        fprintf(fp, "%d\n", &p[i].quantVendida);
    }

    fclose(fp);
}

void exibirProdutos(bool relatorio) {

    if(p == NULL) {
        printf("Nenhum produto a ser exibido. Retornando ao menu principal.\n");
        transicao(1000);
        menu();
    }

    if(relatorio == true) {

        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(Código)\tProduto\t\tEstoque\t\tVendidos\tTotal\n");

        for(int i = 0; i < * numeroProdutos; i++) {
            if(&p[i]) {
                printf("\t\t%d\t\t%s\t%d\t\t%d\t\tR$ %.2f\n", p[i].codigo, p[i].nomeProduto, p[i].quantEstoque, p[i].quantVendida, (p[i].valorUnitario * p[i].quantVendida));
            }
        }
    } else {

        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(Código)\tNome do Item\t\tValor(Unidade)\t\tEstoque\n");

        for(int i = 0; i < * numeroProdutos; i++) {
            if(&p[i]) {
                printf("\t\t%d\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", p[i].codigo, p[i].nomeProduto, p[i].valorUnitario, p[i].quantEstoque);
            }
        }
    }
    int voltar;
    printf("Digite um número qualquer para voltar ao menu principal\n");
    scanf("%d", &voltar);
    getchar();
    transicao(1000);
    menu();
}

void menu() {
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tBem-Vindo ao Mercado da Berenice\n\n");
    printf("\t\tSelecione um dos números referentes à operação\n");
    printf("\t\t1- Produtos\n");
    printf("\t\t2- Vendas\n");
    printf("\t\t3- Sair\n");
    printf("---------------------------------------------------------------------------------------------\n");

    int opcaoMenu = escolherItemMenu();

    switch(opcaoMenu) {
    case 1:
        limparTela();
        produtos();
        break;
    case 2:
        limparTela();
        submenuvendas();
        break;
    case 3:
        limparTela();
        sair();
        break;
    }
}

int escolherItemMenu() {
    int resposta = 0;

    printf("\nSelecione um código do menu acima para interagir com o sistema:\n");
    scanf("%d", &resposta);

    while(resposta != 1 && resposta != 2 && resposta != 3) {
        limparTela();

        menu();

        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &resposta);
    }
    return resposta;
}

void produtos() {
    int opcaoprodutos;

    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tProdutos\n\n");
    printf("\t\tSelecione um dos números referentes à operação\n");
    printf("\t\t1- Exibir\n");
    printf("\t\t2- Cadastrar\n");
    printf("\t\t3- Atualizar\n");
    printf("\t\t4- Excluir\n");
    printf("\t\t5- Salvar\n");
    printf("\t\t6- Ler\n");
    printf("\t\t7- Voltar\n");
    printf("---------------------------------------------------------------------------------------------\n");
    scanf("%d", &opcaoprodutos);
    getchar();

    while(opcaoprodutos != 1 && opcaoprodutos != 2 && opcaoprodutos != 3&& opcaoprodutos != 4 && opcaoprodutos != 5 && opcaoprodutos != 6 && opcaoprodutos != 7) {
        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &opcaoprodutos);
        getchar();
    }
    switch(opcaoprodutos) {
    case 1:
        limparTela();
        exibirProdutos(false);
        produtos();
        break;
    case 2:
        limparTela();
        cadastra();
        break;
    case 3:
        break;
    case 4:
        limparTela();
        deletar();
        break;
    case 5:
        salvarProdutosCadastrados();
        break;
    case 6:
        break;
    case 7:
        limparTela();
        menu();
        break;
    }
}

void submenuvendas() {
    limparTela();
    int opcaovendas;
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tSelecione um dos números referentes à operação\n\n");
    printf("\t\t1- Realizar venda\n");
    printf("\t\t2- Relatório de Vendas\n");
    printf("\t\t3- Voltar\n");
    printf("---------------------------------------------------------------------------------------------\n");
    scanf("%d", &opcaovendas);
    getchar();

    while(opcaovendas != 1 && opcaovendas != 2 && opcaovendas != 3) {
        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &opcaovendas);
        getchar();
    }

    switch(opcaovendas) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        limparTela();
        menu();
    }
}

void cadastra() {
    //Solicita ao usuario o tamanho que ele quer que tenha alocado na memória para armarzenar os caracteres
    printf("Número de produtos: ");
    scanf("%d",&num);
    getchar();
    printf("\n");

    while(num <= 0) {
        printf("\nQuantidade inválida. Digite um número maior que zero: ");
        scanf("%d",&num);
        getchar();
        printf("\n");
    }

    produto produtosArr[num];
    p = (produto *)calloc(num, sizeof(produto));
    p = &produtosArr[0];
    numeroProdutos = &num;
    int nmRep;

    //Enquanto i for menor que zero e i menor que a quantidade de produtos a ser cadastrados, será cadastrado +1 produto
    for(int i = 0; i < num; i++) {
        printf("Produto %d\n", (i+1));

        // Add validação
        printf("Código do produto: ");
        scanf("%d",&p[i].codigo);
        getchar();

        while(p[i].codigo <= 0) {
            printf("Código inválido, digitar um código único e maior que zero: ");
            scanf("%d",&p[i].codigo);
            getchar();
        }

        // Add validação
        printf("Nome: ");
        gets(&p[i].nomeProduto);//ponteiro aponta pra quantidade de cadastros a ser alocadae no nome produto

        // Não precisa de validação
        printf("Valor unitário: R$ ");
        scanf("%f",&p[i].valorUnitario);
        getchar();

        while(p[i].valorUnitario <= 0) {
            printf("Valor inválido, digitar um valor maior que zero: ");
            scanf("%d",&p[i].valorUnitario);
            getchar();
        }

        printf("Quantidade: ");
        scanf("%d",&p[i].quantEstoque);//ponteiro aponta pra quantidade de cadastros a ser alocada na quantidade de estoque
        getchar();

        while(p[i].quantEstoque <= 0) {
            printf("Quantidade de estoque inválida, digitar um número maior que zero: ");
            scanf("%d",&p[i].quantEstoque);
            getchar();
        }

        printf("\n");
    }
    printf("Todos os produtos foram cadastrados, retornando ao menu principal.\n");
    transicao(1000);
    menu();
}

void deletar() {

    int pos;

    printf("Código\t\tNome\t\tValor Unitário\t\tEstoque\n");
    for(int i = 0; i < *numeroProdutos; i++) {
        if(&p[i]) {
            printf("%d\t\t%s\t\tR$ %.2f\t\t%d\n", p[i].codigo, p[i].nomeProduto, p[i].valorUnitario, p[i].quantEstoque);
        }
    }

    printf("\nDigite o código do produto a ser excluido: ");
    scanf("%d", &pos);
    getchar();

    if (pos > 0) {
        for(int i = 0; i < num; i++) {
            if(&p[i].codigo == pos) {
                printf("\n%d\n", &p[i].codigo);
                free(&p[i]);
            }
        }
        printf("Produto de código %d excluído. Retornando ao menu principal.\n", pos);
        transicao(1000);
        menu();
    }
}

int sair() {
    printf("Obrigado por usar o sistema Berenice, até a próxima! :)");
    transicao(1000);
    return 0;
}
