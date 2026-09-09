#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include "conta.h"

float depositar( conta *contas);

float sacar( conta *contas);

void consultarsaldo(conta *contas);

void extrato(movimentacao historico[], int quantidade, conta *contas);

float transferencia(conta *contas, conta *conta_destino);

#endif