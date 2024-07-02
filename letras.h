#ifndef LETRAS_H
#define LETRAS_H


// Definições das letras em pixels
char T[5][5] = {
    {'#', '#', '#', '#', '#'},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '}
};

char E[5][5] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' '},
    {'#', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', ' '},
    {'#', '#', '#', '#', '#'}
};

char R[5][5] = {
    {'#', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'}
};

char M[5][5] = {
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'}
};

char O[5][5] = {
    {' ', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {' ', '#', '#', '#', ' '}
};

char C[5][5] = {
    {' ', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' '},
    {'#', ' ', ' ', ' ', ' '},
    {'#', ' ', ' ', ' ', ' '},
    {' ', '#', '#', '#', '#'}
};

char J[5][5] = {
    {' ', ' ', ' ', ' ', '#'},
    {' ', ' ', ' ', ' ', '#'},
    {' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {' ', '#', '#', '#', ' '}
};

char G[5][5] = {
    {' ', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' '},
    {'#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {' ', '#', '#', '#', '#'}
};

char A[5][5] = {
    {' ', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'}
};

char N[5][5] = {
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#'}
};

char K[5][5] = {
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' '},
    {'#', '#', '#', ' ', ' '},
    {'#', ' ', ' ', '#', ' '},
    {'#', ' ', ' ', ' ', '#'}
};

char I[5][5] = {
    {'#', '#', '#', '#', '#'},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '},
    {'#', '#', '#', '#', '#'}
};

char Q[5][5] = {
    {' ', '#', '#', '#', ' '},
    {'#', ' ', ' ', ' ', '#'},
    {' ', ' ', '#', '#', ' '},
    {' ', ' ', '#', ' ', ' '},
    {' ', ' ', '#', ' ', ' '}
};


char *listaNormal[] = {
    "PROVA", "ANEXO", "ALGUM", "ACASO", "ABRIR",
    "BOMBA", "BOLSA", "BAILE", "BOTAS", "BAIXO", 
    "CARGO", "CRIME", "CINTO", "CAMPO", "CESTA", 
    "DUELO", "DADOS", "DEUSA", "DOIDA", "DOSES", 
    "ESTAR", "ENVIO", "ENTRA", "EXAME", "EVADE",
    "FURIA", "FLORA", "FORMA", "FONTE", "FILHO", 
    "GESTO", "GATOS", "GOSTA", "GRATO", "GRITO", 
    "HOTEL", "HUMOR", "HINOS", "HONRA", "HASTE",
    "PUNHO", "IMPAR", "IRADO", "IGUAL", "ICONE", 
    "JOGAR", "JOVEM", "JUNTO", "JUROU", "JOIAS", 
    "MISTO", "LINDO", "LICOR", "LIMPO", "LENTO", 
    "MONTE", "MANTO", "MOLAS", "MORTE", "FREVO", 
    "NAVIO", "NARIZ", "NOITE", "NOIVA", "NORTE", 
    "OMBRO", "ONTEM", "OSCAR", "OLHAR", "OSTRA", 
    "PULAR", "PODER", "PRIMO", "PRATO", "PAPEL", 
    "ROSCA", "ROLHA", "RADIO", "ROUPA", "REINO",
    "SALVO", "SUAVE", "SANTO", "SOBRA", "SINAL", 
    "TERMO", "TENSO", "PRESO", "TREVO", "TRAVE", 
    "VENTO", "VAZIO", "VALOR", "VIOLA", "VOZES", NULL
};

char *listaDesafiador[] = {
    "ABACATE", "ALEGRE", "ARQUIVADO", "AMENIZOU", "AMIZADE", 
    "BANQUETE", "BATERIA", "BORRACHUDO", "BALANCEADO", "BRINCADEIRA",
    "CABRITO", "CANETA", "CAMINHO", "CINTURAO", "COVARDE",
    "DOURADO", "DOBRADO", "DIVERTIDO", "DINHEIRO", "DESEJADO",
    "ESCRITA", "ESPORTISTA", "ESPALHADO", "ENERGIZADO", "EQUIPARADO",
    "FERIADO", "FILTRAGEM", "FILMANDO", "FERRUGEM", "FESTIVAL",
    "GOLEIRO", "GRIPADO", "GRANITO", "GAFANHOTO", "GLADIADOR",
    "HABITUAL", "HORARIO", "HUMANIDADE", "HONESTIDADE", "HOMENAGEM",
    "IDENTICO", "IMPETUOSO", "INFORMATIVO", "INSPIRADOR", "INVENTARIO",
    "JORNADA", "JOGADOR", "JUVENIL", "JURADOS", "JUDIACAO",
    "LATITUDE", "LAMPADAS", "LONGITUDE", "LIMPEZA", "LARANJADA",
    "MELANCIA", "MERGULHO", "MEDIOCRE", "MARATONA", "MARITMOS", 
    "NAVEGACAO", "NAVIO", "NEGOCIADOR", "NOVENA", "NUMERACAO",
    "OPERACAO", "OPOSICAO", "OMBREIRA", "OFUSCAVA", "OBRIGACAO", 
    "PARALELO", "PIMENTA", "PARENTE", "PORTEIRA", "PAREDAO", 
    "RESPEITADOR", "REALIZADO", "RETIFICA", "REGULAMENTAR", "RATAZANA",
    "SUSTENTADO", "SENTIDOS", "SENTADO", "SIMBOLOGIA", "SONHADOR",
    "TIGRESA", "TENTADOR", "TRABALHADOR", "TREVOSO", "TESTAMENTO", 
    "VIOLENTO", "VIZINHOS", "VANTAJOSO", "VIAJANTE", "VIOLINO", NULL
};

#endif