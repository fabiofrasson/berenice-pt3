#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdbool.h>
#include "produto.h"

void delay(int milliseconds);
void transicao(int milisegundos);
void limparTela();
void salvarProdutosCadastrados(struct produto *arr, int tam);
int vendaProdutos();
void imprimeOpcoesSubmenuVendas();
void realizarVenda(struct produto *arr, int *tam);
void salvarProdutosVendidos(struct produto *arr, int tam);
void exibirProdutos(bool relatorio);
void menu();
void produtos();
int sair();
void limparTela();
void exibir();
void submenuvendas();
int escolherItemMenu();
void cadastra();
void deletar();

#endif // HEADER_H_INCLUDED
