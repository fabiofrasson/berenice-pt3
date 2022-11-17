#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

typedef struct produto {
    int codigo;
    char nomeProduto[25];
    float valorUnitario;
    int quantEstoque;
    int quantVendida;
} produto;

produto *p;

int num, num_novo, num_velho, realoca;
int opcao; //opcao deve ser inteiro se � utlizado como tal


#endif // PRODUTO_H_INCLUDED
