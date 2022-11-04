#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

// Definição da struct
typedef struct produto {
    int codigo;
    char nomeProduto[25];
    float valorUnitario;
    int quantEstoque;
    int quantVendida;
};

// Corpo da função
void salvarProdutos(struct produto *arr, int tam) {

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

#endif // PRODUTO_H_INCLUDED
