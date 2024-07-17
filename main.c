#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "letras.h"
#define charMax (50 +2) // Quantidade máxima de caracteres de uma string, o +2 é referente ao \n e \0.

typedef struct {
    char nome[100];
    int pontuacao;
} Jogador;

// Função para calcular a largura do terminal
int fLarguraDoTerminal(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int cols;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return cols;
}

// Função para desenhar uma letra na tela
void fDesenharLetra(const char *str) {
    int larguraDaLetra = 5 + 2;
    int larguraTotalDaMatriz = strlen(str) * larguraDaLetra;
    //Cálculo para saber a quantidade de espaços em branco necessários para centralizar a matriz
    int espacosEmBranco = (fLarguraDoTerminal() - larguraTotalDaMatriz) / 2;
    
    for (int i = 0; i < 5; i++) {
        for(int esp = 0; esp < espacosEmBranco; esp++){
            printf(" ");
        }
        const char *aux = str;
        while (*aux) {
            char letra = *aux;
            switch (letra) {
                case 'T':
                    for (int j = 0; j < 5; j++){
                        if(T[i][j] != ' '){
                            printf("\033[0;41m \033[0m"); 
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'E':
                    for (int j = 0; j < 5; j++){
                        if(E[i][j] != ' '){
                            printf("\033[0;42m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'R':
                    for (int j = 0; j < 5; j++){
                        if(R[i][j] != ' '){
                            printf("\033[0;45m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'M':
                    for (int j = 0; j < 5; j++){
                        if(M[i][j] != ' '){
                            printf("\033[0;44m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    }
                    break;
                case 'O':
                    for (int j = 0; j < 5; j++){
                        if(O[i][j] != ' '){
                            printf("\033[0;43m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    }
                    break;
                case 'C':
                    for (int j = 0; j < 5; j++){
                        if(C[i][j] != ' '){
                            printf("\033[0;46m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'J':
                    for (int j = 0; j < 5; j++){
                        if(J[i][j] != ' '){
                            printf("\033[0;42m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'G':
                    for (int j = 0; j < 5; j++){
                        if(G[i][j] != ' '){
                            printf("\033[0;41m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'A':
                    for (int j = 0; j < 5; j++){
                        if(A[i][j] != ' '){
                            printf("\033[0;42m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'N':
                    for (int j = 0; j < 5; j++){
                        if(N[i][j] != ' '){
                            printf("\033[0;43m \033[0m"); 
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'K':
                    for (int j = 0; j < 5; j++){
                        if(K[i][j] != ' '){
                            printf("\033[0;44m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'I':
                    for (int j = 0; j < 5; j++){
                        if(I[i][j] != ' '){
                            printf("\033[0;45m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
                    break;
                case 'Q':
                    for (int j = 0; j < 5; j++){
                        if(Q[i][j] != ' '){
                            printf("\033[0;46m \033[0m");
                        }
                        else{
                            printf(" ");
                        }
                    } 
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
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) { // Se o arquivo não existir, cria um novo arquivo vazio
        file = fopen(arquivo, "w");
        fclose(file);
    }
    Jogador jogadores[100]; 
    int num_jogadores = 0;
    // Carrega os jogadores do banco de dados
    while (fscanf(file, "%[^,],%d\n", jogadores[num_jogadores].nome, &jogadores[num_jogadores].pontuacao) != EOF) {
        num_jogadores++;
    }
    fclose(file);
    // Ordena os jogadores por pontuação
    for (int i = 0; i < num_jogadores - 1; i++) {
        for (int j = 0; j < num_jogadores - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }
    system("CLS");
    // Exibe o ranking de jogadores
    fDesenharLetra("RANKING");
    printf("\n");
    for (int i = 0; i < num_jogadores; i++) { 
        printf("%d° %s - %d ponto(s)\n", i+1, jogadores[i].nome, jogadores[i].pontuacao);
    }
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
int fContLista(char **lista){
    int cont = 0;
    for(int i = 0; lista[i] != NULL; i++){
        cont++;
    }
    return cont;
}

void fComoJogar(){
    system("CLS");
    fDesenharLetra("COMO JOGAR Q");
    printf("\n\n- O jogo seleciona aleatoriamente uma palavra secreta de uma lista pre-definida para o jogador advinhar\n");
    printf("- Voce tem um numero limitado de tentativas (6) para adivinhar a palavra\n");
    printf("- Seu palpite deve ter a mesma quantidade de letras que a palavra sorteada\n");
    printf("- Se voce adivinhar uma letra corretamente, essa letra sera revelada na palavra\n");
    printf("- As letras corretas e incorretas sao registradas e mostradas na tela\n");
    printf("- Voce ganha pontos com base no numero de tentativas restantes ao adivinhar a palavra corretamente\n");
    printf("- Ao final, seu score total, a sequencia de vitorias e o tempo que o jogador levou para advinhar sao exibidos\n\n");
}
void iniciarJogo(Jogador *jogador){

    srand(time(NULL));
    const char *arquivo = "database.dat";
    unsigned short int FimDoJogo = 0; //FimDoJogo recebe inicialmente "falso"
    unsigned short int listaNormalTamanho = fContLista(listaNormal);
    unsigned short int listaDesafiadorTamanho = fContLista(listaDesafiador);
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
    unsigned int scoreNormalPorTentativa = 20; // Se houver necessidade de mudar a quantidade de pontos por tentativa
    unsigned int scoreDesafiadorPorTentativa = 40; // Se houver necessidade de mudar a quantidade de pontos por tentativa
    unsigned int scoreMaximoAtingido = 0;
    unsigned short int vitorias = 0;
    // Variáveis para o temporizador
    time_t inicioDoTemporizador, tempoDecorrido;
    unsigned short int segundos = 0;
    unsigned short int minutos = 0;
    unsigned short int horas = 0;
    unsigned short int contagemRegressiva = 3;
    
    do{
        printf("\nEscolha a dificuldade do jogo:\n\n");
        printf("[1] Nivel Normal\n");
        printf("[2] Nivel Dificil\n\n");
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

        // É nesta parte do código que a palavra será sorteada, dependendo da dificuldade escolhida
        if(dificuldade == 1){
            strcpy(palavraSorteada, listaNormal[rand() % listaNormalTamanho]);
        }
        else if(dificuldade == 2){
            strcpy(palavraSorteada, listaDesafiador[rand() % listaDesafiadorTamanho]);
        }
        tamanhoDaPalavraSorteada = strlen(palavraSorteada);
        for(int i = 0; i < tamanhoDaPalavraSorteada; i++){
            palavraSorteadaMontagem[i] = '-';
        }
        palavraSorteadaMontagem[tamanhoDaPalavraSorteada] = '\0';
        

        do{ // Onde o jogador vai tentando acertar

            time(&tempoDecorrido); // Decorre o tempo
            segundos = difftime(tempoDecorrido, inicioDoTemporizador);

            horas = segundos/3600;
            minutos = (segundos%3600)/60;
            segundos = segundos%60;


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
            do{
                system("CLS");
                fPrintTentativas(&tentativasRestantesDoPlayer, &tentativasTotais);
                printf("A palavra tem %d letras\n\n", tamanhoDaPalavraSorteada);
                printf("%s", palavraSorteadaMontagem);
                printf("\n\nLetras corretas: %s\n", letrasCorretasDoJogador);
                printf("Letras incorretas: %s", letrasIncorretasDoJogador);

                // Local onde o usuário digitará seu palpite
                printf("\n\nSua resposta deve ter a mesma quantidade de letras ");
                printf("\nSeu palpite: ");
                fAdjustString(RespostaDoJogador);

            }while(strlen(RespostaDoJogador) != tamanhoDaPalavraSorteada);
            
            system("CLS");

            // Verificando se a resposta do jogador é igual à palavra sorteada
            if(strcmp(palavraSorteada, RespostaDoJogador) == 0){
                printf("Parabens, voce acertou!\n");
                printf("A palavra era: %s\n\n", palavraSorteada);

                //Atribuindo pontos para a dificuldade normal
                if(dificuldade == 1){
                    printf("Ganhou %d pontos!\n", tentativasRestantesDoPlayer * scoreNormalPorTentativa);
                    scoreTotal += tentativasRestantesDoPlayer * scoreNormalPorTentativa;
                    if(vitorias != 0){
                        printf("Ganhou +%.0lf pontos devido as %d vitorias anteriores!\n", ((double) vitorias / 100) * scoreTotal, vitorias);
                    }
                    scoreTotal += ((double) vitorias / 100) * scoreTotal;
                }

                //Atribuindo pontos para a dificuldade desafiadora
                else if(dificuldade == 2){
                    printf("Ganhou %d pontos!\n", tentativasRestantesDoPlayer * scoreDesafiadorPorTentativa);
                    scoreTotal += tentativasRestantesDoPlayer * scoreDesafiadorPorTentativa;
                    if(vitorias != 0){
                        printf("Ganhou +%.0lf pontos devido as %d vitorias anteriores!\n", ((double) vitorias / 100) * scoreTotal, vitorias);
                    }
                    scoreTotal += ((double) vitorias / 100) * scoreTotal;
                }

                if(scoreTotal > scoreMaximoAtingido)
                    scoreMaximoAtingido = scoreTotal;
                printf("\nSeu score no momento: %d\n", scoreTotal);
                vitorias++;
                printf("Sequencia de vitorias: %d\n\n", vitorias);
                printf("Duracao da partida: %02d:%02d:%02d\n\n", horas, minutos, segundos);
                break;
            }

            tentativasRestantesDoPlayer--;

            if(tentativasRestantesDoPlayer == 0){
                printf("Perdeu! Usou todas as suas tentativas!\n");
                printf("A palavra era: %s\n\n", palavraSorteada);
                printf("Seu score total nesta rodada foi: %d\n\n", scoreTotal);
                printf("Seu score recorde foi: %d\n\n", scoreMaximoAtingido);
                printf("Sequencia de vitorias: %d\n\n", vitorias);
                printf("Duracao da partida: %02d:%02d:%02d\n\n", horas, minutos, segundos);
                vitorias = 0; // O jogador perde a sequência de vitórias que havia conseguido
                scoreTotal = 0; // O jogador perde todos os pontos após perder
                break;
            }

        }while(tentativasRestantesDoPlayer > 0);

        do{
            printf("Deseja continuar?\n[S] ou [N]: ");
            fAdjustString(continuarJogo);
            if(continuarJogo[0] == 'N'){
                jogador->pontuacao = scoreMaximoAtingido;
                FimDoJogo = 1; // Fim do jogo recebe verdadeiro
                break;
            }
            else if(continuarJogo[0] == 'S'){
                printf("Deseja mudar a dificuldade?\n[S] ou [N]: \n");
                fAdjustString(continuarJogo);
                if(continuarJogo[0] == 'S'){
                    printf("Digite a dificuldade que deseja alterar\n");
                    printf("[1] Nivel Normal\n");
                    printf("[2] Nivel Dificil\n\n");
                    printf("R: ");
                    scanf("%d", &dificuldade);
                    getchar();
                }
                else if(continuarJogo[0] == 'N'){
                    break;
                }
                else{
                    printf("Insira um comando valido!\n\n");
                }
            }   
            else{
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
    unsigned int aux = 0;
    char escolhaJogador;
    unsigned short int continuarMenu = 1; // continuarMenu inicia como "verdadeiro"
    fDesenharLetra("TERMO");
    Jogador jogador;
    jogador.pontuacao = 0;

    while (continuarMenu) {
        if(aux > 0){
            fDesenharLetra("TERMO");
        }
        printf("\nOla, Jogador!\nSelecione uma opcao:\n");
        printf("\n[1] Iniciar o Jogo\n");
        printf("[2] Como Jogar\n");
        printf("[3] Ranking\n");
        printf("[4] Sair\n\n");
        escolhaJogador = getch();

        switch(escolhaJogador){
            case '1':
                system("CLS");
                printf("Digite seu nome: ");
                fAdjustString(jogador.nome);
                iniciarJogo(&jogador);
                continuarMenu = 1;
                break;
            case '2':
                fComoJogar(); 
                break;
            case '3':
                fCarregarJogadores(arquivo);
                break;
            case '4':
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