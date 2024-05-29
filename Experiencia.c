#include <stdio.h>
#include <stdlib.h>
#include "Regra_Negocio.h"

void menu(){

    int opt;
    puts("||============================================||");
    puts("||        Digite 0 para [ Sair ]              ||");
    puts("||        Digite 1 para [ Cadastrar Conta ]   ||");
    puts("||        Digite 2 para [ Fazer Login ]       ||");
    puts("||        Digite 3 para [ Saber mais ]        ||");
    puts("||============================================||");
    
    scanf("%d", &opt);
    
    switch (opt)
    {
    case 0:
        exit(0);
        break;
    case 1:
        
        break;
    default:
        break;
    }

}
