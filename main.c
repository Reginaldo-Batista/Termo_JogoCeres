#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define charMax 15 + 2


//A função remove o '\n' e deixa todos os caracteres maiúsculos.
void adjustString(char *string){
    fgets(string, charMax, stdin);
    string[strlen(string) - 1] = '\0';
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

int main(){

short int tentativas = 3;
char palavra[] = "CARRO";
char user[charMax];

do{

    printf("Tentativas restantes: %d\n\n", tentativas);
    printf("Sua resposta: ");
    adjustString(user);

    system("CLS");

    if(strcmp(palavra, user) == 0){
        printf("Acertou!\n");
        break;
    }
    tentativas--;
    if(tentativas == 0){
        printf("Perdeu! Usou todas as suas tentativas\n");
        break;
    }

}while(tentativas > 0);

return 0;
}