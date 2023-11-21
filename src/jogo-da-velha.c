#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char campo[10];

void umJogador();           
void doisJogadores();       
void ajuda();               
int checarCompleto();
int checarVitoria(char);
char entradaUsuario(int);
void IA(int);

void resetarCampo() {
    for (int i = 0; i < 10; i++) {
        campo[i] = ' ';
    };
}
