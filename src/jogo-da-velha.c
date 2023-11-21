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
        else if (entradaMenu == '5' || entradaMenu == 's')  // Se a entrada for 4 ou s, o programa é encerrado.
            return;
        else {
            limparConsole();
            printf("\nEntrada Inválida!");   // Se a entrada for inválida, o usuário é informado e o menu é impresso novamente.
        }
    }
}

