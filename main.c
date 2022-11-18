#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Adição dos headers
#include "header.h"
#include "produto.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}
