#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cadastro{
    char nome[20];
    int quantidade;
} cadastro; //faltava agora o completar do typedef

cadastro *p = NULL;

int num, num_novo, num_velho, realoca=0;
int opcao; //opcao deve ser inteiro se é utlizado como tal
char op;

void cadastra();
void exibe();
void menu();
void deletar();

int main() // Início do bloco de código
{
    do{
        menu();

        printf("\tOpcao: ");
        scanf("%d",&opcao);
        fflush(stdin);

            switch(opcao){
                case 0:
                    break;

                case 1:{
                    do{
                        cadastra();
                        printf("Deseja cadastrar mais (s/n): "); scanf(" %c", &op); //Cadastro de produtos

                    }while(toupper(op)!='N');
                    break;
                }

                case 2:
                    exibe();
                    break;
                case 3:
                    deletar();
                    break;

                default:
                    printf("Opcao invalida.\n\n");
            }
    }while(opcao!=0);

    //getchar();

    return 0;
}

void menu()
{
    printf("\t[0] Sair\n\t[1] Cadastrar\n\t[2] Exibe\n\t[3] Excluir\n");

}

void cadastra()
{
    if(p == NULL){
        printf("Numero de cadastros: ");
        scanf("%d",&num);

        p = (cadastro *)calloc(num, sizeof(cadastro));

        int i;
        for(i=0; i<num; i++){
            printf("Cadastro %d\n",i+1);
            printf("Nome: "); scanf("%s", p[i].nome);
            printf("Quantidade: "); scanf("%d",&p[i].quantidade);fflush(stdin);
            printf("\n\n");

        }
    }else{

        num_velho = num++;
        p = realloc(p,num);
        printf("Cadastro %d\n",num_velho);
        printf("Nome: "); scanf("%s",p[num_velho].nome);
        printf("Quantidade: "); scanf("%d",&p[num_velho].quantidade);fflush(stdin);

    }
}

void deletar(){
    printf("Qual a posição a excluir?");
    int pos;
    scanf("%d", &pos);
    pos-- ; //para ajustar aos indices que começam em 0

    if (pos >= 0 && pos < num){ //se a posição é valida
        int i;
        for (i = pos;i < num - 1; ++i){
            p[i] = p[i + 1];
        }

        p = realloc(p, --num * sizeof(cadastro));
    }
}

void exibe()
{
    int posicao;
    if(p==NULL)
        printf("\t -- Cadastro vazio. --\n\n");


    else{

        for(posicao=0; posicao<num;posicao++){

            printf("Posição %d\n\n", posicao); //faltava o j aqui
            printf("Nome: %s\n",p[posicao].nome);
            printf("Quantidade: %d",p[posicao].quantidade);
            puts("\n\n");
        }
    }
}
