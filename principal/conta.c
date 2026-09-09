#include <stdio.h>
#include <string.h>

#include "conta.h"
#include "validacao.h"



int encontrarconta(conta contas[], int quantidade, int numero)
{
    for(int i = 0; i < quantidade; i++)
    {
        if(contas[i].numero_conta == numero)
        {
            return i;
        }
    }

    return -1;
}

int validarsenha(char senha[], conta *contas)
{
    printf("Digite sua senha: ");
    fgets(senha, 20, stdin);

    senha[strcspn(senha, "\n")] = '\0';

    if (strcmp(senha, contas->senha) == 0)
    {
        return 1;
    }

    return 0;
}



void criarconta(conta *contas)
{
    
    printf("\n========= CRIAR CONTA =========\n");

    do{
        printf("Nome completo: ");
        fgets(contas->nome, sizeof(contas->nome), stdin);
        contas->nome[strcspn(contas->nome, "\n")] = '\0';

         if (!validarnome(contas->nome))
        {
            printf("Nome invalido! Digite novamente.\n");
        } 

    } while (!validarnome(contas->nome));
   
    do{
        printf("Cpf: ");
        fgets(contas->cpf, sizeof(contas->cpf), stdin);
        contas->cpf[strcspn(contas->cpf, "\n")] = '\0';
        if (!validarcpf(contas->cpf))
        {
            printf("Cpf invalido! Digite novamente. Favor digitar sem pontuacoes.");

        }

    } while(!validarcpf(contas->cpf));
   
    do
    {
        printf("Data de nascimento: ");
        fgets(contas->datanasc, sizeof(contas->datanasc), stdin);
        contas->datanasc[strcspn(contas->datanasc, "\n")] = '\0';
        if(!validardata(contas->datanasc))
        {
            printf("Data de nascimento invalida.");
        }

    } while (!validardata(contas->datanasc));
    
   
    do{
        printf("Telefone: ");
        limparbuffer();
        fgets(contas->telefone, sizeof(contas->telefone), stdin);
        contas->telefone[strcspn(contas->telefone, "\n")] = '\0';

        if(!validartelefone(contas->telefone))
        {
            printf("Telefone invalido. Porfavor digite novamente.");
        }

    } while(!validartelefone(contas->telefone));
   
    do
    {
        printf("(1)Corrente\n");
        printf("(2)Conta poupanca\n");
        printf("Tipo de conta:");
        scanf("%d", &contas->tipo_de_conta);
        limparbuffer();
        if(contas->tipo_de_conta != 1 && contas->tipo_de_conta != 2)
        {
            printf("Tipo invalido, selecione um tipo valido.");
        }

    } while (contas->tipo_de_conta != 1 && contas->tipo_de_conta != 2);
    
    
    printf("\nCrie uma senha: ");
    fgets(contas->senha, sizeof(contas->senha), stdin);
    contas->senha[strcspn(contas->senha, "\n")] = '\0';

    contas->saldo = 0;
    contas->quantidade_movimentacao = 0;
}

int login(char senha[], conta *contas)
{
    int resultado;

    printf("========= LOGIN =========\n");

    do
    {
        resultado = validarsenha(senha, contas);

        if (resultado)
        {
            printf("Senha correta!\n");
        }
        else
        {
            printf("Senha incorreta!\n");
        }

    } while (!resultado);

    return 1;
}

