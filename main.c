// Comandos pré-processamento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

void menu();
void produtos();
void sair();
void limparTela();
void exibir();
void submenuvendas();
int escolherItemMenu();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
}

void menu()
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\t\tBem-Vindo ao Mercado da Berenice\n\n");
    printf("\t\t\tSelecione um dos números referentes a operação\n");
    printf("\t\t\t1- Produtos\n");
    printf("\t\t\t2- Vendas\n");
    printf("\t\t\t3- Sair\n");
    printf("---------------------------------------------------------------------------------------------\n");

    int opcaoMenu = escolherItemMenu();

    switch(opcaoMenu)
    {
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

int escolherItemMenu()
{
    int resposta = 0;

    printf("\nSelecione um código do menu acima para interagir com o sistema:\n");
    scanf("%d", &resposta);

    while(resposta != 1 && resposta != 2 && resposta != 3)
    {
        limparTela();

        menu();

        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &resposta);
    }
    return resposta;
}

void produtos()
{
    int opcaoprodutos;

    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tProdutos\n\n");
    printf("\t\tSelecione um dos números referentes a operação\n");
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

    while(opcaoprodutos != 1 && opcaoprodutos != 2 && opcaoprodutos != 3&& opcaoprodutos != 4 && opcaoprodutos != 5 && opcaoprodutos != 6 && opcaoprodutos != 7)
    {

        limparTela();

        produtos();

        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &opcaoprodutos);
        getchar();
    }
    switch(opcaoprodutos)
    {
    case 1:
        limparTela();
        exibir();
        limparTela();
        produtos();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        limparTela();
        menu();
        break;
    }
}

void exibir()
{
    int voltar;
    int codigo[5] = {18475, 45462, 34654, 40, 5000};
    float preco[5] = {7.50, 8.69, 5.00, 4.50, 3.25};

    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tItem(Código)\tNome do Item\tValor(Unidade)\tEstoque\n");
    printf("\t\t%i\t\t%s\tR$%.2f\t\t%d\n", codigo[0], "Pão de Forma", preco[0]); //estoqueItens[0]);
    printf("\t\t%i\t\t%s\tR$%.2f\t\t%d\n", codigo[1], "Pão de Centeio", preco[1]); //estoqueItens[1]);
    printf("\t\t\%i\t\t%s\tR$%.2f\t\t%d\n", codigo[2], "Broa de Milho", preco[2]); //estoqueItens[2]);
    printf("\t\t%i\t\t%s\t\tR$%.2f\t\t%d\n", codigo[3], "Sonho", preco[3]); //estoqueItens[3]);
    printf("\t\t%i\t\t%s\t\tR$%.2f\t\t%d\n", codigo[4], "Tubaína", preco[4]); //estoqueItens[4]);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Digite um número qualquer para voltar para o menu\n");
    scanf("%d", &voltar);
    getchar();
}

void submenuvendas()
{
    limparTela();
    int opcaovendas;
    printf("\t\t\tSelecione um dos números referentes a operação\n");
    printf("\t\t\t1- Realizar venda\n");
    printf("\t\t\t2- Relatório de Vendas\n");
    printf("\t\t\t3- Voltar\n");
    printf("---------------------------------------------------------------------------------------------\n");
    scanf("%d", &opcaovendas);
    getchar();

    while(opcaovendas != 1 && opcaovendas != 2 && opcaovendas != 3)
    {

        limparTela();

        submenuvendas();

        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &opcaovendas);
        getchar();
    }

    switch(opcaovendas)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        limparTela();
        menu();
    }
}

void sair()
{
    return 0;
}

void limparTela()
{
#ifdef linux
    system.("clear");
#elif _WIN32
    system("cls");
#else

#endif
}
