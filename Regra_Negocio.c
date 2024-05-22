#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Regra_Negocio.h"

informações inf;
inde ind;

void separa(char dados[120])
{
 
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
                inf.nome[ind.nome_a++]=dados[i];
            }

            else if(freio==1)
            {
                inf.conta[ind.conta_a++] = dados[i];
            }

            else if(freio==2)
            {            
                inf.cpf[ind.cpf_a++]=dados[i];
            }

            else if(freio==3)
            {
                
                inf.tipo[ind.tipo_a++]=dados[i];
            }

            else if(freio==4)
            {
                
                inf.senha[ind.senha_a++]=dados[i];
            }
        }

        else
        {
            freio++;
        }
    }

  //Pondo caracter núlo  

    inf.nome[ind.nome_a] = '\0';
    inf.conta[ind.conta_a] = '\0';
    inf.cpf[ind.cpf_a] = '\0';
    inf.tipo[ind.tipo_a] = '\0';
    inf.senha[ind.senha_a] = '\0';

  //Impressão dos dados separadamente

    printf("%s\n", inf.nome);
    printf("%s\n", inf.cpf);
    printf("%s\n", inf.conta);
    printf("%s\n", inf.tipo); 
    printf("%s\n", inf.senha);
  

}

void contaExiste()
{

  //Abertura e verificação do arquivo
    FILE *f;
    char contaFull[120];
    f = fopen("Accounts.txt", "r");
    if(f == NULL)
    {
        puts("Não foi possivel abrir o banco de dados");
    }
    int  n=0;

    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++);
    {
        fscanf(f, " %s" ,&contaFull);
    }
    printf("(%s)\n",contaFull);
    separa(contaFull);
    
    fclose(f);
}

void cadastro()
{
  //Espaço variaveis  
    char po[11];
    char co[10];
    sprintf(po,"poupança");
    sprintf(co,"corrente");
    int c = 0;
  //Criar validação de tamanho

    puts("Digite seu nome:");
    scanf(" %s", &inf.nome);

    puts("Digite o número da sua conta");
    scanf(" %s", &inf.conta);

    puts("Digite seu cpf");
    scanf(" %s", &inf.cpf);

    puts("Para criar conta pupança tecle(1) Para conta corrente tecle(2)");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        {
            sprintf(inf.tipo,"poupança");
            break;
        }

        case 2:
        {
             sprintf(inf.tipo, "corrente");
             break;
        }
        
    }

    puts("Digite sua senha:");
    scanf("%s", inf.senha);

  //Adicionando o cadastro no banco de dados

     FILE *f=fopen("Accounts.txt", "r++");
    if(f==NULL)
    {
        puts("Não foi possivel acessar arquivo");
    }

    int n=0;
    fscanf(f,"%d",&n);
    n++;
    fseek(f,0,SEEK_SET);
    fprintf(f,"%d",n);
    fseek(f,0,SEEK_END);
    fprintf(f,"\nNome:%s,Conta:%s,CPF:%s,Tipo:%s,Senha:%s", inf.nome,inf.conta,inf.cpf,inf.tipo,inf.senha);
}

int main()
{
    cadastro();
    contaExiste();
    
}



