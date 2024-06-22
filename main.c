#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define charMax 50 +2 // Quantidade máxima de caracteres de uma string, o +2 é referente ao \n e \0.


//A função remove o '\n' e deixa todos os caracteres maiúsculos.
void fAdjustString(char *string){
    fgets(string, charMax, stdin);
    string[strlen(string) - 1] = '\0';
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
}

//Função para imprimir o número de tentativas restantes
void fPrintTentativas(unsigned short int *tentativasRestantesDoPlayer, unsigned short int *tentativasTotais){
    printf("Tentativas restantes: %d/%d\n\n", *tentativasRestantesDoPlayer, *tentativasTotais);
}

//Função que conta automaticamente a quantidade de palavras na lista, sem a necessidade de intervenção do programador
int fContLista(char **lista){
    int cont = 0;
    for(int i = 0; lista[i] != NULL; i++){
        cont++;
    }
    return cont;
}

int main(){

    srand(time(NULL));

    char *lista[] = {
        "SALVO", "TREVO", "MANTO", "LIMPO", "TENSO", "FAROL", "PLANO", "GRUPO",
        "MARCO", "SOMAR", "PONTO", "SENHA", "FALSO", "LIVRO", "CASAR", "PESAR",
        "NORMA", "FORMA", "SIGLA", "TEMPO", "FESTA", "FRUTA", "FLORA", "FARTO",
        "FAZER", "ENTRE", "CORTE", "COSTA", "BOLSA", "BLOCO", "ATRIZ", "ARENA",
        "ALGUM", "ACASO", "ABRIR", "VASCO", "CARGO", "CINTO", "CLUBE", "CREME",
        "CRIVO", "DENTE", "DOSEI", "DUELO", "EIXOS", "ELEVA", "CARRO", "ESTAR",
        "FURIA", "FORTE", "FORMA", "FRACO", "BOLAS", "PEDRA", "FELIZ",  NULL
    };

    unsigned short int FimDoJogo = 0; //FimDoJogo recebe inicialmente "falso"
    unsigned short int listaTamanho = fContLista(lista);
    unsigned short int tentativasTotais, tentativasRestantesDoPlayer;
    char palavraSorteada[charMax];
    char palavraSorteadaMontagem[charMax];
    char RespostaDoJogador[charMax];
    char continuarJogo[2];
    char letrasCorretasDoJogador[charMax];
    char letrasIncorretasDoJogador[charMax];
    unsigned short int auxLetrasCorretas;
    unsigned short int auxLetrasIncorretas;
    unsigned int scoreTotal = 0;
    unsigned int scorePorTentativa = 20; // Se houver necessidade de mudar a quantidade de pontos por tentativa
    unsigned short int vitorias = 0;
    // Variáveis para o temporizador
    time_t inicioDoTemporizador, tempoDecorrido;
    unsigned short int segundos = 0;
    unsigned short int minutos = 0;
    unsigned short int horas = 0;

    time(&inicioDoTemporizador);//Função que dá início ao temporizador

    do{ //(re)Iniciando o jogo do zero

        system("CLS");

        for(int i = 0; i < charMax; i++){ // Limpando todos os vetores de char, exceto 'palavraSorteada'
            letrasCorretasDoJogador[i] = '\0';
            letrasIncorretasDoJogador[i] = '\0';
            RespostaDoJogador[i] = '\0';
        }

        // Reiniciando a maioria das variáveis, exceto 'palavraTam'
        auxLetrasCorretas = 0;
        auxLetrasIncorretas = 0;
        tentativasTotais = 6; // Se quiser alterar o número de tentativas total é nesta parte
        tentativasRestantesDoPlayer = tentativasTotais;

        // É nesta parte do código que a palavra será sorteada
        strcpy(palavraSorteada, lista[rand() % listaTamanho]);
        strcpy(palavraSorteadaMontagem, "-----");

        do{ // Onde o jogador vai tentando acertar

            time(&tempoDecorrido); // Decorre o tempo
            segundos = difftime(tempoDecorrido, inicioDoTemporizador);

            horas = segundos/3600;
            minutos = (segundos%3600)/60;
            segundos = segundos%60;

            fPrintTentativas(&tentativasRestantesDoPlayer, &tentativasTotais);

            for(int j = 0; palavraSorteada[j] != '\0'; j++){
                if(RespostaDoJogador[j] == palavraSorteada[j]){
                    palavraSorteadaMontagem[j] = palavraSorteada[j];
                }
                
                //Verificando se existe o caractere na palavra, e se a lista já existe na lista
                if(strchr(palavraSorteada, RespostaDoJogador[j]) != NULL && strchr(letrasCorretasDoJogador, RespostaDoJogador[j]) == NULL){
                    letrasCorretasDoJogador[auxLetrasCorretas] = RespostaDoJogador[j];
                    letrasCorretasDoJogador[auxLetrasCorretas + 1] = ' '; // Caractere separador
                    auxLetrasCorretas += 2;
                }
                //Verificando se a existência do caractere na palavra é falso, e se já existe na lista
                else if(strchr(palavraSorteada, RespostaDoJogador[j]) == NULL && strchr(letrasIncorretasDoJogador, RespostaDoJogador[j]) == NULL){

                    letrasIncorretasDoJogador[auxLetrasIncorretas] = RespostaDoJogador[j];
                    letrasIncorretasDoJogador[auxLetrasIncorretas + 1] = ' '; // Caractere separador
                    auxLetrasIncorretas += 2;
                }
            }
            printf("%s", palavraSorteadaMontagem);

            printf("\n\nLetras corretas: %s\n", letrasCorretasDoJogador);

            printf("Letras incorretas: %s", letrasIncorretasDoJogador);

            // Local onde o usuário digitará seu palpite
            printf("\n\nSua resposta: ");
            fAdjustString(RespostaDoJogador);

            system("CLS");

            // Verificando se a resposta do jogador é igual à palavra sorteada
            if(strcmp(palavraSorteada, RespostaDoJogador) == 0){
                printf("Acertou!\n");
                printf("A palavra era: %s\n\n", palavraSorteada);
                printf("Ganhou %d pontos!\n\n", tentativasRestantesDoPlayer * scorePorTentativa);
                scoreTotal += tentativasRestantesDoPlayer * scorePorTentativa;
                printf("Seu score no momento: %d\n\n", scoreTotal);
                vitorias++;
                printf("Sequencia de vitorias: %d\n\n", vitorias);
                printf("Duracao da partida: %02d:%02d:%02d\n\n", horas, minutos, segundos);
                break;
            }

            tentativasRestantesDoPlayer--;

            if(tentativasRestantesDoPlayer == 0){
                printf("Perdeu! Usou todas as suas tentativas!\n");
                printf("A palavra era: %s\n\n", palavraSorteada);
                printf("Seu score total foi: %d\n\n", scoreTotal);
                printf("Sequencia de vitorias: %d\n\n", vitorias);
                printf("Duracao da partida: %02d:%02d:%02d\n\n", horas, minutos, segundos);
                vitorias = 0; // O jogador perde a sequência de vitórias que havia conseguido
                scoreTotal = 0; // O jogador perde todos os pontos após perder
                break;
            }
        

        }while(tentativasRestantesDoPlayer > 0);

        do{
            printf("Deseja continuar? [S] ou [N]: ");
            fAdjustString(continuarJogo);
            if(continuarJogo[0] == 'N'){
                FimDoJogo = 1; // Fim do jogo recebe verdadeiro
                break;
            }
            else if(continuarJogo[0] != 'S'){
                printf("Insira um comando valido!\n\n");
            }    
        }while(continuarJogo[0] != 'S');
        
        time(&inicioDoTemporizador); //Reinicia o temporizador a cada partida

    }while(FimDoJogo == 0);

    system("CLS");

    system("Pause");

    return 0;
}