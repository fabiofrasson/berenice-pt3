#include <stdio.h>
#include <stdlib.h>
#include "produto.h" // Adição do header

int main() {

    // Array para teste da função
    struct produto array[5] = {
        {1, "Produto 1", 5.0, 10, 1},
        {2, "Produto 2", 6.69, 10, 7},
        {3, "Produto 3", 10.5, 10, 9},
        {4, "Produto 4", 8.79, 10, 5},
        {5, "Produto 5", 325, 10, 3}
    };

    // Chamada da função
    salvarProdutosCadastrados(array, 5);
    salvarProdutosVendidos(array, 5);

    return 0;
}
