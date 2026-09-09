#ifndef CONTA_H
#define CONTA_H

typedef struct 
{
    char tipo[40];
    float valor;
}movimentacao;

typedef struct
{
    movimentacao historico[100];
    int quantidade_movimentacao;
    int numero_conta;
    char nome[50];
    char cpf[15];
    char datanasc[11];
    char telefone[20];
    int tipo_de_conta;
    char senha[20];
    float saldo;
}conta;

int encontrarconta(conta contas[], int quantidade, int numero);

void criarconta(conta *contas);

int login(char senha[], conta *contas);

int validarsenha(char senha[], conta *contas);


#endif