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

void separa (char file[10],char tipo[10])
{
    int freio=0;
    FILE *f = fopen(file,"r++");
    if(f==NULL)
    {
        printf("Não foi possivel abrir o arquivo %s\n",file);
    }
    int n=0;
    fscanf(f,"%d",&n);
    n++;
    fseek(f,0,SEEK_SET);
    fprintf(f,"%d",n);
    fseek(f,0,SEEK_END);
    fprintf(f,"\n%s",tipo);
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
    printf("\n===============================\n");
    
    printf("%s\n", inf.nome);
    printf("%s\n", inf.cpf);
    printf("%s\n", inf.conta);
    printf("%s\n", inf.tipo); 
    printf("%s\n", inf.senha);
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

    puts("Digite seu nome:");
    scanf(" %[^\n]", &inf.nome);
    valida_nome();
    separa("Nome.txt",inf.nome);

    puts("Digite os 8 números da sua conta\n");
    inf.conta[7]='-';
    printf("_______%c_\r",inf.conta[7]);
    scanf(" %s", &inf.conta);
    valida_conta();
    separa("Conta.txt",inf.conta);

    puts("Digite seu cpf");
    scanf(" %s", &inf.cpf);
    separa("Cpf.txt",inf.cpf);
    

    puts("Para criar conta pupança tecle(1) Para conta corrente tecle(2)");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        {
            sprintf(inf.tipo,"poupança");
            separa("tipo.txt",inf.conta);
            break;
        }

        case 2:
        {
             sprintf(inf.tipo, "corrente");
             separa("tipo.txt",inf.conta);
             break;
        }
        
    }

    puts("Digite sua senha:");
    omite_senha();
    separa("senha.txt",inf.senha);
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
    //login();

    return 0;
}