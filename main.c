#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "letras.h"
#define charMax 50 +2 // Quantidade máxima de caracteres de uma string, o +2 é referente ao \n e \0.

typedef struct {
    char nome[100];
    int pontuacao;
} Jogador;

// Função para desenhar uma letra na tela
void fDesenharLetra(const char *str){
    for (int i = 0; i < 5; i++) {
        const char *aux = str;
        while (*aux) {
            char letra = *aux;
            switch (letra) {
                case 'T':
                    for (int j = 0; j < 5; j++) printf("\033[0;31m%c", T[i][j]); printf("\033[0m");
                    break;
                case 'E':
                    for (int j = 0; j < 5; j++) printf("\033[0;32m%c", E[i][j]); printf("\033[0m");
                    break;
                case 'R':
                    for (int j = 0; j < 5; j++) printf("\033[0;35m%c", R[i][j]); printf("\033[0m");
                    break;
                case 'M':
                    for (int j = 0; j < 5; j++) printf("\033[0;34m%c", M[i][j]); printf("\033[0m");
                    break;
                case 'O':
                    for (int j = 0; j < 5; j++) printf("\033[0;33m%c", O[i][j]); printf("\033[0m");
                    break;
                case 'C':
                    for (int j = 0; j < 5; j++) printf("\033[0;36m%c", C[i][j]); printf("\033[0m");
                    break;
                case 'J':
                    for (int j = 0; j < 5; j++) printf("\033[0;32m%c", J[i][j]); printf("\033[0m");
                    break;
                case 'G':
                    for (int j = 0; j < 5; j++) printf("\033[0;31m%c", G[i][j]); printf("\033[0m");
                    break;
                case 'A':
                    for (int j = 0; j < 5; j++) printf("\033[0;32m%c", A[i][j]); printf("\033[0m");
                    break;
                case 'N':
                    for (int j = 0; j < 5; j++) printf("\033[0;33m%c", N[i][j]); printf("\033[0m");
                    break;
                case 'K':
                    for (int j = 0; j < 5; j++) printf("\033[0;34m%c", K[i][j]); printf("\033[0m");
                    break;
                case 'I':
                    for (int j = 0; j < 5; j++) printf("\033[0;35m%c", I[i][j]); printf("\033[0m");
                    break;
                case 'Q':
                    for (int j = 0; j < 5; j++) printf("\033[0;36m%c", Q[i][j]); printf("\033[0m");
                    break;
                default:
                    for (int j = 0; j < 5; j++) printf(" ");
                    break;
            }
            printf("  "); 
            aux++;
        }
        printf("\n");
    }
}

// Função para adicionar um jogador ao banco de dados
void fAdicionarJogador(const char *arquivo, Jogador jogador) {
    FILE *file = fopen(arquivo, "a");
    if(strcmp(jogador.nome, "") == 0) {
        strcpy(jogador.nome, "DESCONHECIDO");
    }
    fprintf(file, "%s, %d\n", jogador.nome, jogador.pontuacao);
    fclose(file);
}

// Função para carregar jogadores do banco de dados
void fCarregarJogadores(const char *arquivo) {
    int num_jogadores = 0;
    Jogador jogadores[100];
    Jogador temp;
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) { // Se o arquivo não existir, cria um novo arquivo vazio
        file = fopen(arquivo, "w");
        fclose(file);
    }
    // Carrega os jogadores do banco de dados
    while (fscanf(file, "%[^,],%d\n", jogadores[num_jogadores].nome, &jogadores[num_jogadores].pontuacao) != EOF) {
        num_jogadores++;
    }
    fclose(file);
    // Ordena os jogadores por pontuação
    for (int i = 0; i < num_jogadores - 1; i++) {
        for (int j = 0; j < num_jogadores - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }
    system("CLS");
    // Exibe o ranking de jogadores
    fDesenharLetra("RANKING");
    printf("\n\n");
    for (int i = 0; i < num_jogadores; i++) {
        if(i + 1 == 1){
            printf("\033[0;33m🥇 %s - %d ponto(s)\033[0m\n", jogadores[i].nome, jogadores[i].pontuacao);
        }else if(i + 1 == 2){
            printf("\033[38;5;247m🥈 %s - %d ponto(s)\033[0m\n", jogadores[i].nome, jogadores[i].pontuacao);
        }else if(i + 1 == 3){
            printf("\033[38;2;205;127;50m🥉 %s - %d ponto(s)\033[0m\n", jogadores[i].nome, jogadores[i].pontuacao);
        }else{
            printf("%d° %s - %d ponto(s)\n", i+1, jogadores[i].nome, jogadores[i].pontuacao);
        }
    }
    printf("\n");
}

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

//Função que conta automaticamente a quantidade de palavras na listaNormal, sem a necessidade de intervenção do programador
int fContlistaNormal(char **listaNormal){
    int cont = 0;
    for(int i = 0; listaNormal[i] != NULL; i++){
        cont++;
    }
    return cont;
}

//Função que conta automaticamente a quantidade de palavras na listaDesafiador, sem a necessidade de intervenção do programador
int fContlistaDesafiador(char **listaDesafiador){
    int cont = 0;
    for(int i = 0; listaDesafiador[i] != NULL; i++){
        cont++;
    }
    return cont;
}

void fComoJogar(){
    system("CLS");
    fDesenharLetra("COMO JOGARQ");
    printf("\n\n- O jogo seleciona aleatoriamente uma palavra secreta de uma lista pre-definida para o jogador advinhar\n");
    printf("- Voce tem um numero limitado de tentativas (6) para adivinhar a palavra\n");
    printf("- Se voce adivinhar uma letra corretamente, essa letra sera revelada na palavra\n");
    printf("- As letras corretas e incorretas sao registradas e mostradas na tela\n");
    printf("- Voce ganha pontos com base no numero de tentativas restantes ao adivinhar a palavra corretamente\n");
    printf("- Ao final, seu score total, a sequencia de vitorias e o tempo que o jogador levou para advinhar sao exibidos\n\n");
}
void iniciarJogo(Jogador *jogador){

    srand(time(NULL));
    const char *arquivo = "database.dat";
    unsigned short int FimDoJogo = 0; //FimDoJogo recebe inicialmente "falso"
    unsigned short int listaNormalTamanho = fContlistaNormal(listaNormal);
    unsigned short int listaDesafiadorTamanho = fContlistaDesafiador(listaDesafiador);
    unsigned short int tentativasTotais, tentativasRestantesDoPlayer;
    unsigned short int tamanhoDaPalavraSorteada = 0;
    unsigned int dificuldade;
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
    unsigned short int contagemRegressiva = 3;
    
    do{
        printf("\nEscolha a dificuldade do jogo:\n\n");
        printf("1 - Nivel Normal\n");
        printf("2 - Nivel Dificil\n\n");
        printf("R: ");
        scanf("%d", &dificuldade);
        getchar();
    }while(dificuldade < 1 || dificuldade > 2);

    do{
        system("CLS");
        printf("O jogo comeca em: %d", contagemRegressiva);
        Sleep(1000);
        contagemRegressiva--;
    }while(contagemRegressiva > 0);

    time(&inicioDoTemporizador); //Função que dá início ao temporizador

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
        if(dificuldade == 1){
            strcpy(palavraSorteada, listaNormal[rand() % listaNormalTamanho]);
            strcpy(palavraSorteadaMontagem, "-----");
        }
        else if(dificuldade == 2){
            strcpy(palavraSorteada, listaDesafiador[rand() % listaDesafiadorTamanho]);
            tamanhoDaPalavraSorteada = strlen(palavraSorteada);
            for(int i = 0; i < tamanhoDaPalavraSorteada; i++){
                palavraSorteadaMontagem[i] = '-';
            }
            palavraSorteadaMontagem[tamanhoDaPalavraSorteada] = '\0';
        }

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
                
                //Verificando se existe o caractere na palavra, e se ele já existe na listaNormal
                if(strchr(palavraSorteada, RespostaDoJogador[j]) != NULL && strchr(letrasCorretasDoJogador, RespostaDoJogador[j]) == NULL){
                    letrasCorretasDoJogador[auxLetrasCorretas] = RespostaDoJogador[j];
                    letrasCorretasDoJogador[auxLetrasCorretas + 1] = ' '; // Caractere separador
                    auxLetrasCorretas += 2;
                }
                //Verificando se a existência do caractere na palavra é falso, e se já existe na listaNormal
                else if(strchr(palavraSorteada, RespostaDoJogador[j]) == NULL && strchr(letrasIncorretasDoJogador, RespostaDoJogador[j]) == NULL){

                    letrasIncorretasDoJogador[auxLetrasIncorretas] = RespostaDoJogador[j];
                    letrasIncorretasDoJogador[auxLetrasIncorretas + 1] = ' '; // Caractere separador
                    auxLetrasIncorretas += 2;
                }
            }

            if(dificuldade == 1){
                printf("A palavra tem 5 letras\n\n");
            }
            else if(dificuldade == 2){
                printf("A palavra tem %d letras\n\n", tamanhoDaPalavraSorteada);
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
                printf("Parabens, voce acertou!\n");
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
                jogador->pontuacao = scoreTotal;
                break;
            }
            else if(continuarJogo[0] != 'S'){
                printf("Insira um comando valido!\n\n");
            }    
        }while(continuarJogo[0] != 'S');
        
        time(&inicioDoTemporizador); //Reinicia o temporizador a cada partida

    }while(FimDoJogo == 0);
    
    fAdicionarJogador(arquivo, *jogador);

    system("CLS");
}

int main() {
    const char *arquivo = "database.dat";
    unsigned int escolhaJogador, aux = 0;
    unsigned short int continuarMenu = 1; // continuarMenu inicia como 'verdadeiro'
    fDesenharLetra("TERMO");
    Jogador jogador;
    jogador.pontuacao = 0;

    while (continuarMenu) {
        if(aux > 0){
            fDesenharLetra("TERMO");
        }
        printf("\nOlá, Jogador! Selecione uma opção:\n\n");
        printf("1 - Iniciar o Jogo\n");
        printf("2 - Como Jogar\n");
        printf("3 - Ranking\n");
        printf("4 - Sair\n\n");
        printf("R: ");
        scanf("%d", &escolhaJogador);
        getchar();

        switch(escolhaJogador){
            case 1:
                system("CLS");
                printf("Digite seu nome: ");
                fAdjustString(jogador.nome);
                iniciarJogo(&jogador);
                continuarMenu = 1;
                break;
            case 2:
                fComoJogar(); 
                break;
            case 3:
                fCarregarJogadores(arquivo);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        if(continuarMenu){
            printf("\nPressione ENTER para continuar...\n");
            getchar();
            system("CLS");
            aux++;
        }
    }
    return 0;
}