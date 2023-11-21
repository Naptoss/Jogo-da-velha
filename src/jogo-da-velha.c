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
           campo[1], campo[2], campo[3], campo[4], campo[5], campo[6], campo[7], campo[8], campo[9]);   
}

void umJogador() {    
    limparConsole();
    char entrada = ' ';
    int dificuldade = 0;    
    printf("\n\n\nDIFICULDADE\n\n\nF: Fácil\n\nM: Médio\n\nD: Difícil\n\n");    
    printf("\n\n\nEntrada: ");
    scanf(" %c", &entrada);    
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
            dificuldade = 3;   
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
    };

}

void doisJogadores() {  
    char entrada = ' '; 
    int vezJogador1 = 1;    
    while (1) {            
        desenharCampo();
        if (checarVitoria('X')) {
            printf("\nJogador 1 venceu\n\n");   
            return;
        } else if (checarVitoria('O')) {
            printf("\n Jogador 2 venceu\n\n");
            return;
        }
        if (checarCompleto()) {
            printf("Empate\n\n");
        }
        entrada = entradaUsuario(vezJogador1);  
        if (entrada == 's') {   
            return;
        }
        vezJogador1 = !vezJogador1;  
    }
}
