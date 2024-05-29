#include <stdio.h>
#include <stdlib.h>
#include "Regra_Negocio.h"



void headder(int row){


    for (int i = 0; i < row; i++)
    {
        puts("****************************************");
    }
    for (int i = 0; i < 3; i++)
    {
        puts("||                                    ||");
    }
    
    puts("||          BEM VINDO AO BANCO        ||");
        for (int i = 0; i < 3; i++)
    {
        puts("||                                    ||");
    }
    for (int i = 0; i < row; i++)
    {
        puts("****************************************");
    }


}


void menu(){

    int opt;
    puts( "||============================================||" );
    puts( "||        Digite 0 para [ Sair ]              ||" );
    puts( "||        Digite 1 para [ Cadastrar Conta ]   ||" );
    puts( "||        Digite 2 para [ Fazer Login ]       ||" );
    puts( "||        Digite 3 para [ Saber mais ]        ||" );
    puts( "||============================================||" );
    
    scanf(" %d", &opt);

    switch ( opt )
    {
    case 0:
        exit(0);
        break;
    case 1:
        cadastro();
        break;
    default:
        break;
    }

}


void main(){
    headder(3);
    menu();

}