# Relatorio do Jogo-da-velha

ALUNOS:
  * Antonio Gabinio Filho - RGM/33200033
  * Joao Pedro Coutinho Nobrega - RGM/33482799
  * David Ramalho Teixeira de Carvalho - RGM/34262407
  * Adijair Pinto Viana Gonçalves de Araujo - RGM/33296162
  * Ramon Sávio Fontes Rocha - RGM/33676402

Professor responsavel:
  * Walace Sartori Bonfim

Descrição Geral do Jogo:

O jogo implementado é uma versão do clássico jogo da velha em que dois jogadores (ou um jogador contra a maquina) alternam turnos para colocar seu símbolo ('X' ou 'O') em uma grade 3x3. O objetivo é formar uma linha, coluna ou diagonal completa com seus símbolos antes do oponente. O jogo é projetado para ser executado no console, e os jogadores fazem suas escolhas digitando o número do campo em que desejam colocar seu símbolo.

Exemplificação de Código Fonte:

    O código fornece três modos de jogo: um jogador contra a inteligência artificial, dois jogadores ou visualização da ajuda. O programa utiliza funções para modularizar diferentes aspectos do jogo, tornando o código mais legível e fácil de entender.

    A função umJogador() permite que o jogador jogue contra a inteligência artificial. A dificuldade do oponente pode ser escolhida no início do jogo.

   ![printjogador()](https://github.com/Naptoss/Jogo-da-velha/assets/59514617/955cf61c-5a8d-4d1f-a192-8e824bf1c99c)



Dificuldades Encontradas e Soluções Implementadas:

    Limpar o Console em Ambientes Diferentes:
        Dificuldade: O código usa system("clear") para limpar o console, mas isso pode variar em diferentes sistemas operacionais (por exemplo, "clear" no Linux e MacOS, "cls" no Windows).
        Solução: Pode-se usar diretivas de pré-processador para ajustar automaticamente o comando de limpeza conforme o sistema operacional.

    Permitir Acentos na Entrada do Usuário:

       Dificuldade: O código lê a entrada do usuário como caracteres simples, o que pode ser um problema para entradas com acentos.
       Solução: Adicionar suporte a acentos pode envolver a alteração da leitura de caracteres e o uso de bibliotecas específicas para lidar com caracteres acentuados.

    Melhorar a Lógica da Inteligência Artificial:

      Dificuldade: A lógica da inteligência artificial pode ser aprimorada para tomar decisões mais estratégicas.
      Solução: Refatorar a lógica da função IA() para tomar decisões com base em estratégias mais avançadas, como bloquear o oponente de ganhar.


Resultado:(COLOCAR PRINTS DE EXEMPLOS DO CODIGO AQUI)






 
  
