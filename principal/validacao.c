#include <stdio.h>
#include <string.h>

#include "validacao.h"


int validarnome(char nome[])
{
    if(strlen(nome) == 0)
    {
        return 0;
    }
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if(!((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z') || nome[i] == ' '))
        {
            return 0;
        }
    }
    return 1;

}

int validarcpf(char cpf[])
{
    if (strlen(cpf) != 11)
        return 0;

    for (int i = 0; cpf[i] != '\0'; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0;
    }

    return 1;
}

int validardata(char data[])
{
    if (strlen(data) != 10)
        return 0;

    if (data[2] != '/' || data[5] != '/')
        return 0;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
            continue;

        if (data[i] < '0' || data[i] > '9')
            return 0;
    }

    return 1;
}

int validartelefone(char telefone[])
{
    if (strlen(telefone) != 11)
        return 0;

    for (int i = 0; telefone[i] != '\0'; i++)
    {
        if (telefone[i] < '0' || telefone[i] > '9')
            return 0;
    }

    return 1;
}

void limparbuffer()
{
    int c;
    while(((c = getchar())) != '\n' && c != EOF);
}