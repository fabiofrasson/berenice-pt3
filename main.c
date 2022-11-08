#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "produto.h" // Adição do header
#include "geral.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

    // Array para teste da função
    struct produto arrayProdutos[] = {
        {18745, "Pão de Forma", 7.5, 10, 1},
        {45462, "Pão de Centeio", 8.69, 10, 7},
        {34654, "Broa de Milho", 5.0, 10, 9},
        {40, "Sonho", 4.5, 10, 5},
        {5000, "Tubaína", 3.25, 10, 3}
    };

    struct produto *produtos = arrayProdutos;

    // salvarProdutosCadastrados(array, 5);
    // salvarProdutosVendidos(array, 5);

    // Exibir produtos
    // exibirProdutos(array, 5, false);

    // Exibir relatório
    // exibirProdutos(array, 5, true);

    vendaProdutos();

    return 0;
}
