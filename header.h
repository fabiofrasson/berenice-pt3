#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdbool.h>
#include "produto.h"

void delay(int milliseconds);
void transicao(int milisegundos);
void limparTela();
void salvarProdutosCadastrados();
int vendaProdutos();
void imprimeOpcoesSubmenuVendas();
void realizarVenda(struct produto *arr, int *tam);
void salvarProdutosVendidos();
void exibirProdutos(bool relatorio);
void menu();
void produtos();
int sair();
void limparTela();
void submenuvendas();
int escolherItemMenu();
void cadastra();
void deletar();

#endif // HEADER_H_INCLUDED
