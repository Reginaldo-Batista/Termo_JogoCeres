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
void printTentativas(short int *tentativa, short int *tentativasTotal){
    printf("Tentativas restantes: %d/%d\n\n", *tentativa, *tentativasTotal);
}

int main(){

    srand(time(NULL));

    char *lista[] = {
    "ACEITAR", "AJUSTAR", "ANALISAR", "APLICAR", "APONTAR", "APRENDER", "APROVAR", "ARMAZENAR", "ARRASTAR", "ASSINAR", "ASSOCIAR", "ASSUMIR", "ATUALIZAR", "AUTENTICAR", "AUTORIZAR", "BALANCEAR", "BLOQUEAR", "CALIBRAR", "CANCELAR", "CAPTURAR", "CARREGAR", "CELEBRAR", "CLASSIFICAR", "CLONAR", "COBRIR", "COLIDIR" "COMANDAR", "COMENTAR", "COMERCIALIZAR", "COMPARAR", "COMPETIR", "COMPLETAR", "COMPLICAR", "COMUNICAR", "CONCEDER", "CONFIRMAR", "CONGELAR", "CONQUISTAR", "CONSERVAR", "CONSIDERAR", "CONSOLIDAR", "CONSTRUIR", "CONSULTAR", "CONTAR", "CONTINUAR", "CONTRATAR", "CONTROLAR", "CONVERTER", "COORDENAR", "CORRIGIR", "CRIAR", "CRITICAR", "DEFENDER", "DEFINIR", "DELEGAR", "DELETAR", "DEMONSTRAR", "DENUNCIAR", "DEPOSITAR", "DESCANSAR", "DESCREVER", "DESENHAR", "DESENVOLVER", "DESMONTAR", "DESTACAR", "DETECTAR", "DETERMINAR", "DEVOLVER", "DIAGNOSTICAR", "DIFERENCIAR", "DIMINUIR", "DIRECIONAR", "DISCUTIR", "DISPARAR", "DISPENSAR", "DISPOR", "DISTINGUIR", "DISTRIBUIR", "DIVERTIR", "DOMINAR", "DURAR", "EDITAR", "ELEVAR", "ELIMINAR", "EMITIR", "ENCERRAR", "ENCONTRAR", "ENDEREÇAR", "ENGAJAR", "ENRIQUECER", "ENSINAR", "ENTENDER", "ENTRAR", "ENTREGAR", "ENUMERAR", "EQUIPAR", "ERGUER", "ESCALAR", "ESCOLHER", "ESCREVER", "ESPECIFICAR", "ESPERAR", "ESTABELECER", "ESTIMAR", "ESTUDAR", "EVITAR", "EVOLUIR", "EXCEDER", "EXCLUIR", "EXECUTAR"
};

    short int tentativasTotal, tentativa;
    short int fim = 0; //Fim recebe inicialmente "falso"
    char continuar[2];
    char palavra[charMax];
    short int palavraTam;
    char palavraMontagem[charMax];
    char letrasCorretas[charMax];
    char letrasIncorretas[charMax];
    short int auxCorreta;
    short int auxIncorreta;
    char user[charMax];
    unsigned int score = 0;
    unsigned int pontoPorTentativa = 20; // Se houver necessidade de mudar a quantidade de pontos por tentativa

    do{ //(re)Iniciando o jogo do zero

        system("CLS");

        for(int i = 0; i < charMax; i++){ // Limpando todos os vetores de char, exceto 'palavra'
            letrasCorretas[i] = '\0';
            letrasIncorretas[i] = '\0';
            palavraMontagem[i] = '\0';
            user[i] = '\0';
        }

        // Reiniciando a maioria das variáveis, exceto 'palavraTam'
        auxCorreta = 0;
        auxIncorreta = 0;
        tentativasTotal = 6;
        tentativa = tentativasTotal;

        // É nesta parte do código em que haverá a escolha da palavra e o cálculo do tamanho desta
        strcpy(palavra, lista[rand() % 109]);
        palavraTam = strlen(palavra);

        for(int i = 0; i < palavraTam; i++){
            palavraMontagem[i] = '-';
        }

        do{ //Onde o jogador vai tentando acertar

            printTentativas(&tentativa, &tentativasTotal);

            printf("A palavra tem %d letras:\n", palavraTam);
            for(int j = 0; palavra[j] != '\0'; j++){
                if(user[j] == palavra[j]){
                    palavraMontagem[j] = palavra[j];
                }
                //Verificando se existe o caractere na palavra, e se a lista já existe na lista
                if(strchr(palavra, user[j]) != NULL && strchr(letrasCorretas, user[j]) == NULL){
                    letrasCorretas[auxCorreta] = user[j];
                    letrasCorretas[auxCorreta + 1] = ' '; // Caractere separador
                    auxCorreta += 2;
                }
                //Verificando se a existência do caractere na palavra é falso, e se já existe na lista
                else if(strchr(palavra, user[j]) == NULL && strchr(letrasIncorretas, user[j]) == NULL){
                    letrasIncorretas[auxIncorreta] = user[j];
                    letrasIncorretas[auxIncorreta + 1] = ' '; // Caractere separador
                    auxIncorreta += 2;
                }
            }
            printf("%s", palavraMontagem);

            printf("\n\nLetras corretas: %s\n", letrasCorretas);

            printf("Letras incorretas: %s", letrasIncorretas);

            // Local onde o usuário digitará seu palpite
            printf("\n\nSua resposta: ");
            adjustString(user);

            system("CLS");

            if(strcmp(palavra, user) == 0){
                printf("Acertou!\n");
                printf("A palavra era: %s\n\n", palavra);
                printf("Ganhou %d pontos!\n\n", tentativa * pontoPorTentativa);
                score += tentativa * pontoPorTentativa;
                printf("Seu score no momento: %d\n\n", score);
                break;
            }

            tentativa--;

            if(tentativa == 0){
                printf("Perdeu! Usou todas as suas tentativas!\n");
                printf("A palavra era: %s\n\n", palavra);
                printf("Seu score total foi: %d\n\n", score);
                score = 0;
                break;
            }

        }while(tentativa > 0);

        do{
            printf("Deseja continuar? [S] ou [N]: ");
            adjustString(continuar);
            if(continuar[0] == 'N'){
                fim = 1;
                break;
            }
            else if(continuar[0] != 'S')
                printf("Insira um comando valido!\n\n");
        }while(continuar[0] != 'S');

    }while(fim != 1);

    system("CLS");

    system("Pause");

    return 0;
}