// Comandos pré-processamento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Constantes dos números do código
#define produtocodigo1 "18745"
#define produtocodigo2 "45462"
#define produtocodigo3 "34654"
#define produtocodigo4 "40"
#define produtocodigo5 "5000"

// Constantes dos nomes dos produtos
#define produtoOpcao1 "Pão de Fôrma"
#define produtoOpcao2 "Pão de Centeio"
#define produtoOpcao3 "Broa de Milho"
#define produtoOpcao4 "Sonho"
#define produtoOpcao5 "Tubaína"

// Constantes dos preços dos produtos
#define precoProduto1 7.50
#define precoProduto2 8.69
#define precoProduto3 5.0
#define precoProduto4 4.5
#define precoProduto5 3.25

void menu();
void produtos();
void vendas();
void sair();
void limparTela();
void exibir();
void submenuvendas();
int escolherItemMenu();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcaoMenu = escolherItemMenu();
    menu();

    if(opcaoMenu == 1){ // Exibir submenu de Produtos
        produtos();
    }
        else if(opcaoMenu == 2){ // Exibir Submenu de Vendas
                vendas();
        }
            else if(opcaoMenu == 3){ // Sair do programa
                sair();
            }
                    return 0;
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

void menu(){
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\t\tBem-Vindo ao Mercado da Berenice\n\n");
    printf("\t\t\tSelecione um dos números referentes a operação\n");
    printf("\t\t\t1- Produtos\n");
    printf("\t\t\t2- Vendas\n");
    printf("\t\t\t3- Sair\n");
    printf("---------------------------------------------------------------------------------------------\n");
}

void produtos(){
    int opcaoprodutos;

    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tProdutos\n\n");
    printf("\t\tSelecione um dos números referentes a operação");
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

    while(opcaoprodutos != 1 && opcaoprodutos != 2 && opcaoprodutos != 3&& opcaoprodutos != 4 && opcaoprodutos != 5 && opcaoprodutos != 6 && opcaoprodutos != 7){

    limparTela();

    produtos();

    printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
    scanf("%d", &opcaoprodutos);
    getchar();

    if(opcaoprodutos = 7){
        menu();
    }
}

void exibir(){
    
    int produtocodigo1 "18745", produtocodigo2 "45462", produtocodigo3 "34654", produtocodigo4 "40", produtocodigo5 "5000";
    char produtoOpcao1 "Pão de Fôrma", produtoOpcao2 "Pão de Centeio", produtoOpcao3 "Broa de Milho", produtoOpcao4 "Sonho", produtoOpcao5 "Tubaína";
    float precoProduto1 7.50, precoProduto2 8.69, precoProduto3 5.0, precoProduto4 4.5, precoProduto5 3.25;
    
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tItem(Código)\tNome do Item\tValor(Unidade)\tEstoque");
    printf("\t\t\t\t1\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtocodigo1, produtoOpcao1, precoProduto1); //estoqueItens[0]);
    printf("\t\t\t\t2\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtocodigo2, produtoOpcao2, precoProduto2); //estoqueItens[1]);
    printf("\t\t\t\t3\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtocodigo3, produtoOpcao3, precoProduto3); //estoqueItens[2]);
    printf("\t\t\t\t4\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtocodigo4, produtoOpcao4, precoProduto4); //estoqueItens[3]);
    printf("\t\t\t\t5\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtocodigo5, produtoOpcao5, precoProduto5); //estoqueItens[4]);
    printf("---------------------------------------------------------------------------------------------\n");
}

void submenuvendas(){
    int opcaovendas;
    printf("\t\t\tSelecione um dos números referentes a operação\n");
    printf("\t\t\t1- Realizar venda\n");
    printf("\t\t\t2- Relatório de Vendas\n");
    printf("\t\t\t3- Voltar\n");
    printf("---------------------------------------------------------------------------------------------\n");
    scanf("%d", &opcaovendas);
    getchar();

    while(opcaovendas != 1 && opcaovendas != 2 && opcaovendas != 3){

    limparTela();

    submenuvendas();

    printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
    scanf("%d", &opcaovendas);
    getchar();

    if(opcaovendas = 3){
        menu();
    }
}

}

void sair(){
    return 0;
}

void limparTela()
{
#ifdef __linux__
    system.("clear");
#elif _WIN32
    system("cls");
#else

#endif
}
