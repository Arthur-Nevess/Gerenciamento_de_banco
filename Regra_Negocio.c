#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Regra_Negocio.h"

informações inf;
informações inf2;
inde ind;

void valida_nome()
{
    
    for(int i=0;inf2.nome[i]!='\0';i++)
    {
        if(isspace(inf2.nome[i]))
        {
            inf2.nome[i]='_';
        }
        
        if(isdigit(inf2.nome[i]))
        {
            puts("!!!Não pode conter números no seu nome!!!");

            puts("Digite seu nome corretemente");
            scanf("%s", &inf2.nome);
            valida_nome();
        }
    }
}

void valida_conta()
{
    for (int i=0;inf2.conta[i]!='\0';i++)
    {
        
        if(i>8||i<8)
        {
            puts("   !!!O número da conta deve conter 8 digitos!!!");
            puts("Digite o número da conta corretamente");
            inf2.conta[7]='-';
            printf("_______%c_\r",inf2.conta[7]);
            scanf("%s", &inf2.conta);
            valida_conta();  
        }

        if(inf2.conta[7]!='-')
        {
            puts("!!!Coloque o ( - ) no lugar correto!!!");
            puts("Digite os 8 números da conta corretamente");
            inf2.conta[7]='-';
            printf("_______%c_\r",inf2.conta[7]);
            scanf("%s", inf2.conta);
            valida_conta();
        }


        inf2.conta[7]='0';
        if(!isdigit(inf2.conta[i]))
        {
            puts("!!!Deve conter apenas números em sua conta!!!");
            puts("Digite os 8 números da conta corretamente");
            inf2.conta[7]='-';
            printf("_______%c_\r",inf2.conta[7]);
            scanf("%s", inf2.conta);
            valida_conta();           
        }
        inf2.conta[7]='-';
    }   
}

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

    printf("===============================\n");
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
    scanf("%[^\n]", &inf2.nome);
    valida_nome();

    puts("Digite os 8 números da sua conta\n");
    inf2.conta[7]='-';
    printf("_______%c_\r",inf2.conta[7]);
    scanf("%s", &inf2.conta);
    valida_conta();

    puts("Digite seu cpf");
    scanf(" %s", &inf2.cpf);

    puts("Para criar conta pupança tecle(1) Para conta corrente tecle(2)");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        {
            sprintf(inf2.tipo,"poupança");
            break;
        }

        case 2:
        {
             sprintf(inf2.tipo, "corrente");
             break;
        }
        
    }

    puts("Digite sua senha:");
    scanf("%s", inf2.senha);

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
    fprintf(f,"\nNome:%s,Conta:%s,CPF:%s,Tipo:%s,Senha:%s", inf2.nome,inf2.conta,inf2.cpf,inf2.tipo,inf2.senha);
}

int main()
{
    cadastro();
    contaExiste();
    
}



