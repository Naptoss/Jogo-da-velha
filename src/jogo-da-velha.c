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

void ajuda() {  
    limparConsole();
    printf("\n\n\nAJUDA\n\nUm Jogador:\nNo modo Um Jogador, você joga contra o Computador\n\n"
           "Dois Jogadores:\nNo modo Dois Jogadores, você joga contra um segundo jogador. A entrada alterna entre X e O. "
           "Você também pode jogar neste modo para testar novas táticas ou apenas jogar contra si mesmo.\n\n"
           "Controles:\nPara escolher um campo, você deve digitar um número entre 1 e 9. O primeiro campo está no canto superior esquerdo, "
           "o segundo ao lado dele, etc.\n\n");
    return;
}

void creditos() { 
    limparConsole();
    printf("Este programa foi feito por:\n\n");
    printf("Ramon Sávio Fonts Rocha\nDavid Ramalho Teixeira de Carvalho\nJoão Pedro Coutinho Nôbrega\nAdijair Pinto Viana Gonçalves de Araujo\n");
    return;
}

char entradaUsuario(int x) {    
    while (1) {
        printf("\n\nEntrada: ");
        char entrada = ' '; 
        scanf(" %c", &entrada);
        int numeroEntrada = entrada - '0';
        if (numeroEntrada > 9 || numeroEntrada < 1) {   
            if (entrada == 's')
                return entrada;
            else
                printf("\nEntrada Inválida!");
        } else if (campo[numeroEntrada] != ' ') {
            printf("\nEste campo já está em uso");
        } else {
            if (x)
                campo[numeroEntrada] = 'X';  
            else
                campo[numeroEntrada] = 'O'; 
            return entrada;
        }
    }
}

int checarVitoria(char sinal) {  
    if ((campo[1] == sinal && campo[2] == sinal && campo[3] == sinal) || (campo[1] == sinal && campo[4] == sinal && campo[7] == sinal) ||
        (campo[1] == sinal && campo[5] == sinal && campo[9] == sinal) || (campo[2] == sinal && campo[5] == sinal && campo[8] == sinal) ||
        (campo[3] == sinal && campo[6] == sinal && campo[9] == sinal) || (campo[3] == sinal && campo[5] == sinal && campo[7] == sinal) ||
        (campo[4] == sinal && campo[5] == sinal && campo[6] == sinal) || (campo[7] == sinal && campo[8] == sinal && campo[9] == sinal)) {
        return 1;
    }
    return 0;
}
int checarCompleto() {  
    for (int i = 1; i <= 9; i++) {
        if (campo[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

void IA(int dificuldade) { 
    if (checarCompleto()) {
        return;
    }

    srand(time(NULL)); 

    if (dificuldade == 1) { 
        int check = rand() % 3; 
        if (check != 1) { 
            for (int i = 1; i < 10; i++) { 
                if (campo[i] == ' ') { 
                    campo[i] = 'O'; 
                    if (checarVitoria('O')) { 
                        return;
                    } else { 
                        campo[i] = ' ';
                    }
                }
            }
        } else if (check != 2) { 
            for (int i = 1; i < 10; i++) { 
                if (campo[i] == ' ') { 
                    campo[i] = 'X'; 
                    if (checarVitoria('X')) { 
                        campo[i] = 'O'; 
                        return;
                    } else {
                        campo[i] = ' '; 
                    }
                }
            }
        }
        while (1) {
            int i = rand() % 9 + 1; 
            if (campo[i] == ' ') { 
                return;
            }
        }