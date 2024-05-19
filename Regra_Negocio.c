#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Regra_Negocio.h"
#define TAM 50


void separa(char dados[100])
{
  //Variaveis de transposição  

    char nome[TAM]={0};
    char cpf[TAM]={0};
    char conta[TAM]={0};
    char senha[TAM]={0};
    char tipo[TAM]={0};

  //Variaveis de acesso de índice  

    int nome_a=0;
    int cpf_a=0;
    int conta_a=0;
    int senha_a=0;
    int tipo_a=0;
    
  //Variaveis de verificação  

    int freio=0;
    int tamanho_f=strlen(dados);
    
  //Loop  

    for (int i=0;i<tamanho_f;i++)
    {
        if(dados[i]!=',')
        {
            
            if(freio==0)
            {
                nome[nome_a++]=dados[i];
            }

            else if(freio==1)
            {
                conta[conta_a++] = dados[i];
            }

            else if(freio==2)
            {            
                cpf[cpf_a++]=dados[i];
            }

            else if(freio==3)
            {
                
                tipo[tipo_a++]=dados[i];
            }

            else if(freio==4)
            {
                
                senha[senha_a++]=dados[i];
            }
        }

        else
        {
            freio++;
        }
    }

  //Pondo caracter núlo  

    nome[nome_a] = '\0';
    conta[conta_a] = '\0';
    cpf[cpf_a] = '\0';
    tipo[tipo_a] = '\0';
    senha[senha_a] = '\0';

  //Impressão dos dados separadamente

    printf("%s\n", nome);
    printf("%s\n", cpf);
    printf("%s\n", conta);
    printf("%s\n", tipo); 
    printf("%s\n", senha);
  

}

void contaExiste()
{

  //Abertura e verificação do arquivo
    FILE *f;
    char contaFull[100];
    f = fopen("Accounts.txt", "r");
    if(f != NULL){
        fscanf(f, " %s" ,contaFull);
    }
    else
    {
        putss("Não foi possivel abrir o banco de dados");
    }
   
    separa(contaFull);
    
    fclose(f);
}

int main()
{
    contaExiste();
    
}



