#ifndef GERAL_H_INCLUDED
#define GERAL_H_INCLUDED

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void transicao(int milisegundos)
{
    delay(milisegundos);
    limparTela();
}

void limparTela()
{
#ifdef linux
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

#endif // GERAL_H_INCLUDED
