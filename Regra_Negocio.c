#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Regra_Negocio.h"


void separa(char dados[100])
{
    char nome[50];
    char cpf[20];
    char conta[20];
    char senha[20];
    int freio=0;

    int tamanho_f=strlen(dados);
    int contador = tamanho_f;

    printf("%d\n", tamanho_f);
    printf("%d\n", contador);
    
    for (int i=0;i<contador;i++)
    {
        if(dados[i]!= ',' && freio==0)
        {
            nome[i]=dados[i];
        }

         else if(dados[i]!=',' && freio==1)
        {
            conta[i]=dados[i];
        }

        else if(dados[i]!=',' && freio==2)
        {
            cpf[i]=dados[i];
        }

        else if(dados[i]!=',' && freio==3)
        {
            senha[i]=dados[i];
        }


        else
        {
            freio++;
            
        }
    }
    printf("%s\n", nome);
    printf("%s\n", cpf);
    printf("%s\n", conta);
    printf("%s\n", senha);

    
    
}

int contaExiste(int cpf, char tipo[15]){

    FILE *f;

    char contaFull[100];
    f = fopen("Accounts.txt", "r");
    if(f != 0){
        fscanf(f, " %s" ,contaFull);
    }
    printf("%s\n", contaFull);

    separa(contaFull);
}

int main()
{
    contaExiste(10, "poupança");
    
}



