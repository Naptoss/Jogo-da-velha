#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char campo[10];

void umJogador();            
void doisJogadores();       
void ajuda();              
void creditos();            
int checarCompleto();
int checarVitoria(char);
char entradaUsuario(int);
void IA(int);


void limparConsole() {
    system("cls"); 
}

void resetarCampo() {
    for (int i = 0; i < 10; i++) {
        campo[i] = ' ';
    };
}

void menu() {                  
    while (1) {                 
        resetarCampo();         
        char entradaMenu;       
        printf("\n\n"           
               "MENU\n\n"
               "1: Um Jogador\n"
               "2: Dois Jogadores\n"
               "3: Ajuda\n"
               "4: Créditos\n"
               "5: Sair\n\n\n"
               "Entrada: ");
        scanf(" %c", &entradaMenu);     
        if (entradaMenu == '1')        
            umJogador();
        else if (entradaMenu == '2')    
            doisJogadores();
        else if (entradaMenu == '3')    
            ajuda();
        else if (entradaMenu == '4')
            creditos();
        else if (entradaMenu == '5' || entradaMenu == 's')  
            return;
        else {
            limparConsole();
            printf("\nEntrada Inválida!");   
        }
    }
}

void desenharCampo() {   
    limparConsole();
    printf("\n\n\n"
           "     %c | %c | %c\n"
           "    ---|---|---\n"
           "     %c | %c | %c\n"
           "    ---|---|---\n"  
           "     %c | %c | %c\n",
           campo[1], campo[2], campo[3], campo[4], campo[5], campo[6], campo[7], campo[8], campo[9]);   // O campo é impresso na tela.
}

void umJogador() {    // Esta função é o modo umJogador. Ela é chamada quando o usuário escolhe o modo umJogador no menu.
    limparConsole();
    char entrada = ' ';
    int dificuldade = 0;    // A variável dificuldade é declarada para armazenar a dificuldade escolhida pelo usuário.
    printf("\n\n\nDIFICULDADE\n\n\nF: Fácil\n\nM: Médio\n\nD: Difícil\n\n");    // O menu de dificuldade é impresso na tela.
    printf("\n\n\nEntrada: ");
    scanf(" %c", &entrada);    // A entrada do usuário é lida e armazenada na variável entrada.
    switch (entrada) {
        case 'F':
            dificuldade = 1;
            break;
        case 'f':
            dificuldade = 1;
            break;
        case 'M':
            dificuldade = 2;
            break;
        case 'm':
            dificuldade = 2;
            break;
        case 'D':
            dificuldade = 3;    // A dificuldade é definida de acordo com a entrada do usuário.
            break;
        case 'd':
            dificuldade = 3;
            break;
        case 'S':
            return;
            break;
        case 's':
            return;
            break;
        default:
            printf("\nEntrada Inválida!");  
            umJogador();
            break;
    }
