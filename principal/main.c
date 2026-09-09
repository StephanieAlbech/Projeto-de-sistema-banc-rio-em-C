#include <stdio.h>
#include <string.h>

#include "conta.h"
#include "validacao.h"
#include "movimentacao.h"


int main(void)
{   
    char senha[20];
    conta contas[100];
    int conta_logada = -1;
    int quantidade_contas = 0;
    float valor;
    int opcao;
    
    
    do
    {
        printf("\n========= BANCO =========\n");
        printf("\n(1)Criar conta");
        printf("\n(2)Login");
        printf("\n(3)Depositar");
        printf("\n(4)Sacar");
        printf("\n(5)Consultar Saldo");
        printf("\n(6)Extrato");
        printf("\n(7)Transferencia");
        printf("\n(8)logout");
        printf("\n(9)Sair\n");
        scanf("%d", &opcao);
        limparbuffer();

        switch(opcao)
        {
            case 1:
                contas[quantidade_contas].numero_conta = quantidade_contas + 1001;
                criarconta(&contas[quantidade_contas]);
                

                printf("conta criada com sucesso!\n");
                printf("Numero da conta: %d\n", contas[quantidade_contas].numero_conta);
                quantidade_contas++;
                break;
            
            case 2:
                 if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                    int numero;
                    int indice;

                    printf("Numero da conta: ");
                    scanf("%d", &numero);
                    limparbuffer();

                    indice = encontrarconta(contas, quantidade_contas, numero);

                    if(indice == -1)
                    {
                        printf("Conta nao encontrada.\n");
                    }
                    else 
                    {
                        if(login(senha, &contas[indice]))
                        {
                            conta_logada = indice;
                             printf("Login concluido com sucesso.\n");
                        }
                        
                    }
                   
                    break;
                }

            case 3:
                if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                    if(conta_logada == -1){
                        printf("Faca login primeiro.\n");
                        break;
                    }
                    else
                    {
                        valor = depositar(&contas[conta_logada]);

                        contas[conta_logada].historico[contas[conta_logada].quantidade_movimentacao].valor = valor;
                        strcpy(contas[conta_logada].historico[contas[conta_logada].quantidade_movimentacao].tipo, "deposito");
                        printf("Valor depositado com sucesso. \nsaldo total: %.2f\n", contas[conta_logada].saldo);
                        
                        contas[conta_logada].quantidade_movimentacao++;
                        
                        break;
                    }

                }
                
            case 4:
                 if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                     if(conta_logada == -1){
                        printf("Faca login primeiro.\n");
                        break;
                    }
                    else
                    {
                        valor = sacar(&contas[conta_logada]);
                        contas[conta_logada].historico[contas[conta_logada].quantidade_movimentacao].valor = valor;
                        strcpy(contas[conta_logada].historico[contas[conta_logada].quantidade_movimentacao].tipo, "saque");

                        printf("Valor sacado com sucesso!\nSaldo total: %.2f\n", contas[conta_logada].saldo);
                        
                        contas[conta_logada].quantidade_movimentacao++;

                        break;
                    }
                    
                }
                

            case 5:
                if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                    if(conta_logada == -1){
                        printf("Faca login primeiro.\n");
                        break;
                    }
                    else
                    {
                        consultarsaldo(&contas[conta_logada]);
                        break;
                    }
                    
                }
                

            case 6:
                if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                    if(conta_logada == -1){
                        printf("Faca login primeiro.\n");
                        break;
                    }
                    else
                    {
                        extrato(contas[conta_logada].historico, contas[conta_logada].quantidade_movimentacao, &contas[conta_logada]);
                        break;
                    }
                    
                }
            case 7:
                if(quantidade_contas == 0)
                {
                    printf("Crie uma conta primeiro\n");
                    break;
                }
                else{
                    if(conta_logada == -1){
                        printf("Faca login primeiro.\n");
                        break;
                    }
                    else
                    {   int numero_conta_destino;
                        int indice;

                        printf("\n========= TRANSFERENCIA =========\n");
                        printf("Numero da conta destino: ");
                        scanf("%d", &numero_conta_destino);
                        limparbuffer();

                        indice = encontrarconta(contas, quantidade_contas, numero_conta_destino);

                        if(indice == -1)
                        {
                            printf("Conta nao encontrada.\n");
                        }
                        else 
                        {
                            transferencia(&contas[conta_logada], &contas[indice]);
                        }
                    
                        
                        break;
                    }
                    
                }
                
            case 8:
                if(conta_logada == -1){
                    printf("Nenhuma conta logada.\n");
                    break;
                }
                else{
                    conta_logada = -1;
                    printf("Logout realizado com sucesso.\n");
                    break;
                }
            case 9:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("opcao invalida.");

                
        }
    }while(opcao != 9);
    return 0;
}

/*gcc main.c conta.c validacao.c movimentacao.c -o banco*/