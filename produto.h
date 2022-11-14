#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

typedef struct produto {
    int codigo;
    char nomeProduto[25];
    float valorUnitario;
    int quantEstoque;
    int quantVendida;
} produto;

struct produto *p = NULL;
int num, num_novo, num_velho, realoca = 0;
int opcao; //opcao deve ser inteiro se é utlizado como tal
char op;

#endif // PRODUTO_H_INCLUDED
