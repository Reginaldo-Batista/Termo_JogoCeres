#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define charMax 50 +2 // Quantidade máxima de caracteres de uma string, o +2 é referente ao \n e \0.


//A função remove o '\n' e deixa todos os caracteres maiúsculos.
void adjustString(char *string){
    fgets(string, charMax, stdin);
    string[strlen(string) - 1] = '\0';
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

//Função para imprimir o número de tentativas restantes
void printTentativas(short int tentativa, short int tentativasTotal){
    printf("Tentativas restantes: %d/%d\n\n", tentativa, tentativasTotal);
}

int main(){

    srand(time(NULL));

    short int tentativasTotal = 10;
    short int tentativa = tentativasTotal;

    char *lista[] = {
    "ACEITAR", "AJUSTAR", "ANALISAR", "APLICAR", "APONTAR", "APRENDER", "APROVAR", "ARMAZENAR", "ARRASTAR", "ASSINAR", "ASSOCIAR", "ASSUMIR", "ATUALIZAR", "AUTENTICAR", "AUTORIZAR", "BALANCEAR", "BLOQUEAR", "CALIBRAR", "CANCELAR", "CAPTURAR", "CARREGAR", "CELEBRAR", "CLASSIFICAR", "CLONAR", "COBRIR", "COLIDIR" "COMANDAR", "COMENTAR", "COMERCIALIZAR", "COMPARAR", "COMPETIR", "COMPLETAR", "COMPLICAR", "COMUNICAR", "CONCEDER", "CONFIRMAR", "CONGELAR", "CONQUISTAR", "CONSERVAR", "CONSIDERAR", "CONSOLIDAR", "CONSTRUIR", "CONSULTAR", "CONTAR", "CONTINUAR", "CONTRATAR", "CONTROLAR", "CONVERTER", "COORDENAR", "CORRIGIR", "CRIAR", "CRITICAR", "DEFENDER", "DEFINIR", "DELEGAR", "DELETAR", "DEMONSTRAR", "DENUNCIAR", "DEPOSITAR", "DESCANSAR", "DESCREVER", "DESENHAR", "DESENVOLVER", "DESMONTAR", "DESTACAR", "DETECTAR", "DETERMINAR", "DEVOLVER", "DIAGNOSTICAR", "DIFERENCIAR", "DIMINUIR", "DIRECIONAR", "DISCUTIR", "DISPARAR", "DISPENSAR", "DISPOR", "DISTINGUIR", "DISTRIBUIR", "DIVERTIR", "DOMINAR", "DURAR", "EDITAR", "ELEVAR", "ELIMINAR", "EMITIR", "ENCERRAR", "ENCONTRAR", "ENDEREÇAR", "ENGAJAR", "ENRIQUECER", "ENSINAR", "ENTENDER", "ENTRAR", "ENTREGAR", "ENUMERAR", "EQUIPAR", "ERGUER", "ESCALAR", "ESCOLHER", "ESCREVER", "ESPECIFICAR", "ESPERAR", "ESTABELECER", "ESTIMAR", "ESTUDAR", "EVITAR", "EVOLUIR", "EXCEDER", "EXCLUIR", "EXECUTAR"
};
    char palavra[charMax];
    strcpy(palavra, lista[rand() % 100]);
    short int palavraTam = strlen(palavra);

    char palavraMontagem[charMax];
    for(int i = 0; i < palavraTam; i++){
        palavraMontagem[i] = '-';
    }
    palavraMontagem[palavraTam] = '\0';

    char letrasCorretas[charMax] = "";
    char letrasIncorretas[charMax] = "";
    short int auxCorreta = 0;
    short int auxIncorreta = 0;
    
    char user[charMax] = "";

    do{

        printTentativas(tentativa, tentativasTotal);

        printf("Palavra:\n");
        for(int j = 0; palavra[j] != '\0'; j++){
            if(user[j] == palavra[j]){
                palavraMontagem[j] = palavra[j];
            }
            //Verificando se existe o caractere na palavra, e se a lista já tem essa palavra;
            if(strchr(palavra, user[j]) != NULL && strchr(letrasCorretas, user[j]) == NULL){
                letrasCorretas[auxCorreta] = user[j];
                letrasCorretas[auxCorreta + 1] = ' ';
                auxCorreta += 2;
            }
            //Verificando se a existência do caractere na palavra é falso, e se já tem
            else if(strchr(palavra, user[j]) == NULL && strchr(letrasIncorretas, user[j]) == NULL){
                letrasIncorretas[auxIncorreta] = user[j];
                letrasIncorretas[auxIncorreta + 1] = ' ';
                auxIncorreta += 2;
            }
        }
        printf("%s", palavraMontagem);

        printf("\n\nA palavra tem %d letras\n", palavraTam);

        printf("Letras corretas: %s\n", letrasCorretas);

        printf("Letras incorretas: %s", letrasIncorretas);
        // For verificando quais caracteres estao incorretos
        printf("\n\nSua resposta: ");
        adjustString(user);

        system("CLS");

        if(strcmp(palavra, user) == 0){
            printf("Acertou!\n\n");
            break;
        }

        tentativa--;

        if(tentativa == 0){
            printf("Perdeu! Usou todas as suas tentativas!\n");
            printf("A palavra era: %s\n\n", palavra);
            break;
        }

    }while(tentativa > 0);


    system("Pause");

    return 0;
}