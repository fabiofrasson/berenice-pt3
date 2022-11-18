#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include "produto.h"

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void transicao(int milisegundos)
{
    delay(milisegundos);
    limparTela();
}

void limparTela()
{
#ifdef linux
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

void salvarProdutosCadastrados(struct produto *arr, int tam)
{

    char *filename = "produtos.txt";

    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        exit (1);
    }

    fprintf(fp, "quantidade_produtos\n");

    for(int i = 0; i < tam; i++)
    {
        fprintf(fp, "\n%d\n", arr[i].codigo);
        fprintf(fp, "%s\n", arr[i].nomeProduto);
        fprintf(fp, "%.2f\n", arr[i].valorUnitario);
        fprintf(fp, "%d\n", arr[i].quantEstoque);
        fprintf(fp, "%d\n", arr[i].quantVendida);
    }

    fclose(fp);
}

int vendaProdutos()
{

    int opcao = 0, counter = 0;

    while (opcao != 1 && opcao != 2 && opcao != 3)
    {
        if(counter > 0)
        {
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

void imprimeOpcoesSubmenuVendas()
{
    printf("1. Realizar venda\n");
    printf("2. Relatorio de vendas\n");
    printf("3. Voltar\n\n");
}

void realizarVenda(struct produto *arr, int *tam)
{

    int codigoProduto, quantidade;

    printf("Pos 0: %d\n", arr[0].quantEstoque);
    printf("Pos 1: %d\n", arr[1].quantEstoque);
    printf("Pos 2: %d\n", arr[2].quantEstoque);
    printf("Pos 3: %d\n", arr[3].quantEstoque);
    printf("Pos 4: %d\n", arr[4].quantEstoque);

    if(arr[0].quantEstoque == 0 && arr[1].quantEstoque == 0 && arr[2].quantEstoque == 0 && arr[3].quantEstoque == 0 && arr[4].quantEstoque == 0)
    {
        printf("N�o h� itens dispon�veis para venda, retornando ao menu principal.");
        delay(1000);
        return 0;
        // Trabalhar retorno ao menu principal
    }

    printf("Digite o c�digo do produto que deseja vender:\n");
    exibirProdutos(true);
    scanf("%d", &codigoProduto);

    while(codigoProduto != arr[0].codigo && codigoProduto != arr[1].codigo && codigoProduto != arr[2].codigo && codigoProduto != arr[3].codigo && codigoProduto != arr[4].codigo)
    {
        printf("Codigo invalido, digite um codigo valido.\n");
        exibirProdutos(true);
        scanf("%d", &codigoProduto);
    }

    printf("Agora, digite a quantidade:\n");
    scanf("%d", &quantidade);

    while(quantidade <= 0)
    {
        printf("Quantidade invalida, digite uma quantidade acima de zero:\n");
        scanf("%d", &quantidade);
    }
}

void salvarProdutosVendidos(struct produto *arr, int tam)
{

    char filename[40];

    struct tm *timenow;

    time_t now = time(NULL);
    timenow = gmtime(&now);

    strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.txt", timenow);

    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }

    fprintf(fp, "produtos_vendidos\n");

    for(int i = 0; i < tam; i++)
    {
        fprintf(fp, "\n%d\n", arr[i].codigo);
        fprintf(fp, "%s\n", arr[i].nomeProduto);
        fprintf(fp, "%.2f\n", arr[i].valorUnitario);
        fprintf(fp, "%d\n", arr[i].quantEstoque);
        fprintf(fp, "%d\n", arr[i].quantVendida);
    }

    fclose(fp);
}

void exibirProdutos(bool relatorio)
{
    if(relatorio == true)
    {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(C�digo)\tProduto\t\tEstoque\t\tVendidos\tTotal\n");
        for(int i = 0; i < * numeroProdutos; i++) {
            if(&p[i]) {
                printf("\t\t%d\t\t%s\t%d\t\t%d\t\tR$ %.2f\n", p[i].codigo, p[i].nomeProduto, p[i].quantEstoque, p[i].quantVendida, (p[i].valorUnitario * p[i].quantVendida));
            }
        }
    }
    else
    {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("\t\tItem(C�digo)\tNome do Item\t\tValor(Unidade)\t\tEstoque\n");
        for(int i = 0; i < * numeroProdutos; i++) {
            if(&p[i]) {
                printf("\t\t%d\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", p[i].codigo, p[i].nomeProduto, p[i].valorUnitario, p[i].quantEstoque);
            }
        }
    }
    int voltar;
    printf("Digite um n�mero qualquer para voltar para o menu principal\n");
    scanf("%d", &voltar);
    getchar();
    delay(1000);
    menu();
}

void menu()
{
    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\t\tBem-Vindo ao Mercado da Berenice\n\n");
    printf("\t\t\tSelecione um dos n�meros referentes a opera��o\n");
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

    printf("\nSelecione um c�digo do menu acima para interagir com o sistema:\n");
    scanf("%d", &resposta);

    while(resposta != 1 && resposta != 2 && resposta != 3)
    {
        limparTela();

        menu();

        printf("Erro: Op��o inv�lida. Por favor, digite uma op��o v�lida:\n");
        scanf("%d", &resposta);
    }
    return resposta;
}

void produtos()
{
    int opcaoprodutos;

    printf("---------------------------------------------------------------------------------------------\n");
    printf("\t\tProdutos\n\n");
    printf("\t\tSelecione um dos n�meros referentes a opera��o\n");
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
        printf("Erro: Op��o inv�lida. Por favor, digite uma op��o v�lida:\n");
        scanf("%d", &opcaoprodutos);
        getchar();
    }
    switch(opcaoprodutos)
    {
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
    printf("\t\tItem(C�digo)\tNome do Item\tValor(Unidade)\tEstoque\n");
    printf("\t\t%i\t\t%s\tR$%.2f\t\t%d\n", codigo[0], "P�o de Forma", preco[0]); //estoqueItens[0]);
    printf("\t\t%i\t\t%s\tR$%.2f\t\t%d\n", codigo[1], "P�o de Centeio", preco[1]); //estoqueItens[1]);
    printf("\t\t\%i\t\t%s\tR$%.2f\t\t%d\n", codigo[2], "Broa de Milho", preco[2]); //estoqueItens[2]);
    printf("\t\t%i\t\t%s\t\tR$%.2f\t\t%d\n", codigo[3], "Sonho", preco[3]); //estoqueItens[3]);
    printf("\t\t%i\t\t%s\t\tR$%.2f\t\t%d\n", codigo[4], "Tuba�na", preco[4]); //estoqueItens[4]);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Digite um n�mero qualquer para voltar para o menu\n");
    scanf("%d", &voltar);
    getchar();
}

void submenuvendas()
{
    limparTela();
    int opcaovendas;
    printf("\t\t\tSelecione um dos n�meros referentes a opera��o\n");
    printf("\t\t\t1- Realizar venda\n");
    printf("\t\t\t2- Relat�rio de Vendas\n");
    printf("\t\t\t3- Voltar\n");
    printf("---------------------------------------------------------------------------------------------\n");
    scanf("%d", &opcaovendas);
    getchar();

    while(opcaovendas != 1 && opcaovendas != 2 && opcaovendas != 3)
    {
        printf("Erro: Op��o inv�lida. Por favor, digite uma op��o v�lida:\n");
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

void cadastra()
{
    //Solicita ao usuario o tamanho que ele quer que tenha alocado na mem�ria para armarzenar os caracteres
    printf("Numero de produtos: ");
    scanf("%d",&num);
    getchar();
    printf("\n");

    while(num <= 0)
    {
        printf("\nQuantidade invalida. Digite um numero maior que zero: ");
        scanf("%d",&num);
        getchar();
        printf("\n");
    }

    produto produtosArr[num];
    p = (produto *)calloc(num, sizeof(produto));
    p = &produtosArr[0];
    numeroProdutos = &num;
    int nmRep;

    //Enquanto i for menor que zero e i menor que a quantidade de produtos a ser cadastrados, ser� cadastrado +1 produto
    for(int i = 0; i < num; i++)
    {
        printf("Produto %d\n", (i+1));

        // Add valida��o
        printf("Codigo do produto: ");
        scanf("%d",&p[i].codigo);
        getchar();

        while(p[i].codigo <= 0)
        {
            printf("Codigo invalido, digitar um codigo unico e maior que zero: ");
            scanf("%d",&p[i].codigo);
            getchar();
        }

        // Add valida��o
        printf("Nome: ");
        gets(&p[i].nomeProduto);//ponteiro aponta pra quantidade de cadastros a ser alocadae no nome produto

        // N�o precisa de valida��o
        printf("Valor unitario: R$ ");
        scanf("%f",&p[i].valorUnitario);
        getchar();

        while(p[i].valorUnitario <= 0)
        {
            printf("Valor invalido, digitar um valor maior que zero: ");
            scanf("%d",&p[i].valorUnitario);
            getchar();
        }

        printf("Quantidade: ");
        scanf("%d",&p[i].quantEstoque);//ponteiro aponta pra quantidade de cadastros a ser alocada na quantidade de estoque
        getchar();

        while(p[i].quantEstoque <= 0)
        {
            printf("Quantidade de estoque invalida, digitar um numero maior que zero: ");
            scanf("%d",&p[i].quantEstoque);
            getchar();
        }

        printf("\n");
    }
    printf("Todos os produtos foram cadastrados, retornando ao menu principal.\n");
    transicao(1000);
    menu();
}

void deletar()
{

    int pos;

    printf("Codigo\t\tNome\t\tValor Unitario\t\tEstoque\n");
    for(int i = 0; i < *numeroProdutos; i++)
    {
        if(&p[i])
        {
            printf("%d\t\t%s\t\tR$ %.2f\t\t%d\n", p[i].codigo, p[i].nomeProduto, p[i].valorUnitario, p[i].quantEstoque);
        }
    }

    printf("\nDigite o codigo do produto a ser excluido: ");
    scanf("%d", &pos);
    getchar();

    if (pos > 0)
    {
        for(int i = 0; i < num; i++)
        {
            if(&p[i].codigo == pos)
            {
                printf("\n%d\n", &p[i].codigo);
                free(&p[i]);
            }
        }
        printf("Produto de codigo %d excluido. Retornando ao menu principal.\n", pos);
        transicao(1000);
        menu();
    }


}


int sair()
{
    return 0;
}
