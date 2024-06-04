//Bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
//Bibliotecas propias
#include "Regra_Negocio.h"

//Declarando st
informações inf;
informações inf2;
inde ind;

void configurar_terminal() 
{
    struct termios newtio;
    tcgetattr(STDIN_FILENO, &newtio); // Pega a configuração atual do terminal
    newtio.c_lflag &= ~ICANON; // Desativa o modo canônico
    newtio.c_lflag &= ~ECHO;   // Desativa o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio); // Aplica a nova configuração
}

void restaurar_terminal()
{
    struct termios newtio;
    tcgetattr(STDIN_FILENO, &newtio); // Pega a configuração atual do terminal
    newtio.c_lflag |= ICANON; // Ativa o modo canônico
    newtio.c_lflag |= ECHO;   // Ativa o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio); // Aplica a nova configuração
}

void separa ()
{
    
}

void valida_nome()
{
    
    for(int i=0;inf.nome[i]!='\0';i++)
    {
        if(isspace(inf.nome[i]))
        {
            inf.nome[i]='_';
        }
        
        if(isdigit(inf.nome[i]))
        {
            puts("!!!Não pode conter números no seu nome!!!");

            puts("Digite seu nome corretemente");
            scanf("%s", &inf.nome);
            valida_nome();
        }
    }
}

void valida_conta()
{
    for (int i=0;inf.conta[i]!='\0';i++)
    {
        if(i>8 && i != 9)
        {
            puts("   !!!O número da conta deve conter 8 digitos!!!");
            puts("Digite o número da conta corretamente");
            inf.conta[7]='-';
            printf("_______%c_\r",inf.conta[7]);
            scanf(" %s", &inf.conta);
            valida_conta();  
        }

        if(inf.conta[7]!='-')
        {
            puts("!!!Coloque o ( - ) no lugar correto!!!");
            puts("Digite os 8 números da conta corretamente");
            inf.conta[7]='-';
            printf("_______%c_\r",inf.conta[7]);
            scanf(" %s", inf.conta);
            valida_conta();
        }


        inf.conta[7]='0';
        if(!isdigit(inf.conta[i]))
        {
            puts("!!!Deve conter apenas números em sua conta!!!");
            puts("Digite os 8 números da conta corretamente");
            inf.conta[7]='-';
            printf("_______%c_\r",inf.conta[7]);
            scanf(" %s", inf.conta);
            valida_conta();           
        }
        inf.conta[7]='-';
    }   
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

    printf("\n===============================\n");
    
    printf("%s\n", inf.nome);
    printf("%s\n", inf.cpf);
    printf("%s\n", inf.conta);
    printf("%s\n", inf.tipo); 
    printf("%s\n", inf.senha);
    
    fclose(f);
}

void omite_senha()
{
    for(int i=0;i<8;i++)
    {
        configurar_terminal();
        scanf(" %c",&inf.senha[i]);

        for (int j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\r");
        inf.senha[(i+1)]='\0';
    }
    restaurar_terminal();
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
    scanf(" %[^\n]", &inf.nome);
    valida_nome();

    puts("Digite os 8 números da sua conta\n");
    inf.conta[7]='-';
    printf("_______%c_\r",inf.conta[7]);
    scanf(" %s", &inf.conta);
    valida_conta();

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
    omite_senha();

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
    fprintf(f,"\n%s,%s,%s,%s,%s", inf.nome,inf.conta,inf.cpf,inf.tipo,inf.senha);
}

void login()
{
   printf("Digite seu cpf:\n->"); 
   scanf ("%s", &inf2.cpf);
   if(strcmp(inf.cpf, inf2.cpf))
   {
        printf("\nVocê consta em nosso banco de dados\n");
   }

   else
   {
     puts("\nImpostor do carai\n");
   }
}

int main()
{
   cadastro();
   contaExiste();
    login();

    return 0;
}