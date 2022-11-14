#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Adição dos headers
#include "header.h"
#include "produto.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
    /*

    struct produto *produtos = (produto)*malloc(sizeof(produto*));

    // Array para teste da função
    struct produto arrayProdutos[5] = {
        {18745, "Pão de Forma", 7.5, 10, 1},
        {45462, "Pão de Centeio", 8.69, 10, 7},
        {34654, "Broa de Milho", 5.0, 10, 9},
        {40, "Sonho", 4.5, 10, 5},
        {5000, "Tubaína", 3.25, 10, 3}
    };
    int tam = 5;

    produtos = arrayProdutos;
    int *tamanhoArray = &tam;

    // salvarProdutosCadastrados(array, 5);
    // salvarProdutosVendidos(array, 5);

    // Exibir produtos
    // exibirProdutos(array, 5, false);

    // Exibir relatório
    // exibirProdutos(array, 5, true);

    int opcao = vendaProdutos();

    if(opcao == 1) {
        realizarVenda(&produtos, &tamanhoArray);
    } else if(opcao == 2) {
        // Ajustar print
        exibirProdutos(&produtos, &tamanhoArray, false);
    } else {
        // Chamar o menu principal
    }
    */

    return 0;
}
