
#include <stdio.h>
#include <string.h>

#include "movimentacao.h"
#include "validacao.h"
#include "conta.h"



float depositar( conta *contas)
{   
    printf("\n========= DEPOSITAR =========\n");
    float valor;
    printf("Valor a depositar: ");
    scanf("%f", &valor);
    limparbuffer();

    while(valor <= 0){
        printf("Valor invalido\n");
        printf("Valor a depositar: ");
        scanf("%f", &valor);
        limparbuffer();
    }
    contas->saldo += valor;

    return valor;


}

float sacar( conta *contas)
{
    printf("\n========= SAQUE =========\n");
    float valor;
    printf("Valor para sacar: ");
    scanf("%f", &valor);
    limparbuffer();
    while(valor > contas->saldo || valor <= 0)
    {
        printf("Valor Invalido.\n");
        printf("Valor para sacar: ");
        scanf("%f", &valor);
        limparbuffer();
    }
    contas->saldo -= valor;
    return valor;
}

void consultarsaldo(conta *contas)
{
    printf("\n========= CONSULTA DE SALDO =========\n");
    printf("Saldo total disponivel: %.2f\n", contas->saldo);
}

void extrato(movimentacao historico[], int quantidade, conta *contas)
{
    printf("\n========= EXTRATO =========\n");
    if(quantidade == 0 ) 
    {
        printf("Nenhuma movimentacao feita.\n");
    }
    for(int i = 0; i < quantidade; i++)
    {
        printf("%s: R$: %.2f\n", historico[i].tipo, historico[i].valor);
    }
    printf("Saldo total: %.2f\n", contas->saldo);

}

float transferencia(conta *contas, conta *conta_destino)
{   
    int opcao;
    float valor;
    printf("Valor para transferir: ");
    scanf("%f", &valor);
    limparbuffer();

    while(valor > contas->saldo || valor <= 0)
    {
        printf("Valor Invalido.\n");
        printf("Valor para transferir: ");
        scanf("%f", &valor);
        limparbuffer();
    }
    if(contas->numero_conta == conta_destino->numero_conta)
    {
        printf("Nao e possivel transferir para a mesma conta.\n");
        return 0;
    }
    else{
        printf("Dados:");
        printf("\nNome: %s", conta_destino->nome);

        printf("\nNumero da conta: %d", conta_destino->numero_conta);

        printf("\nValor: %.2f", valor);
        

        printf("\nDeseja confirmar a transferencia?\n(1)Sim (2)Nao\n");
        scanf("%d", &opcao);
        limparbuffer();

        switch(opcao)
        {
            case 1:
                contas->saldo -= valor;
                conta_destino->saldo += valor;
                printf("\nTransferencia realizada com sucesso para %s!\n", conta_destino->nome);    
                printf("Saldo total: %.2f\n", contas->saldo);
                contas->historico[contas->quantidade_movimentacao].valor = valor;
                strcpy(contas->historico[contas->quantidade_movimentacao].tipo, "Transferencia enviada");

                conta_destino->historico[conta_destino->quantidade_movimentacao].valor = valor;
                strcpy(conta_destino->historico[conta_destino->quantidade_movimentacao].tipo, "Transferencia recebida");
                
                contas->quantidade_movimentacao++;
                conta_destino->quantidade_movimentacao++;
                
                
                return valor;
                break;
            case 2:
                printf("Transferencia cancelada.\n");
                break;
            default:
                printf("Opcao invalida. Transferencia cancelada.\n");
                break;
        }
       
        
        
    }
    

}