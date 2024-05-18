#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int contaExiste(int cpf, char tipo[15]){

    FILE *f;

    char contaFull[100];
    f = fopen("Accounts.txt", "r");
    if(f != 0){
        fscanf(f, " %s" ,contaFull);
    }
    printf("%s\n", contaFull);
}

int main(){

    contaExiste(10, "poupança");
}



