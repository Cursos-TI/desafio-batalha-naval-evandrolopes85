#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void preencherTabuleiro(int tabuleiro[10][10], int tamanhoLinha, int tamanhoColuna){
    for(int i = 0; i < tamanhoLinha; i++){
        for(int j = 0; j < tamanhoColuna; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[10][10], char colunasTabuleiro[10], int tamanhoLinha, int tamanhoColuna){
    for(int i = 0; i < tamanhoLinha; i++){
        if(i == 0)
            printf("%5c ", colunasTabuleiro[i]);
        else
            printf("%2c ", colunasTabuleiro[i]);
    }
    printf("\n");
    for(int i = 0; i < tamanhoLinha; i++){
        printf("%2d ", i+1);
        for(int j = 0; j < tamanhoColuna; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int navioVertical(int tabuleiro[10][10], int navio[3], int tamanhoLinha, int tamanhoColuna, int coordenadaX, int coordenadaY){
    if(coordenadaX > 7){
        printf("Coordenada informada ultrapassam o tamanho do tabuleiro. Tente novamete!\n");
        return 1;
    }else if (coordenadaY > 7){
        printf("Coordenada informada ultrapassam o tamanho do tabuleiro. Tente novamete!\n");
        return 1;
    }
    int index = 0;
    for(int i = index; i < tamanhoLinha; i++){
        if(tabuleiro[i + coordenadaX][coordenadaY] != 0){
            printf("Posição x[%d] e y[%d] ocupada!\n", i + coordenadaX, coordenadaY);
            return 1;
        }
        tabuleiro[i + coordenadaX][coordenadaY] = navio[index];
        index++;
        if(index == 3){
            break;
        }
    }

    return 0;
}

int navioHorizontal(int tabuleiro[10][10], int navio[3], int tamanhoLinha, int tamanhoColuna, int coordenadaX, int coordenadaY){
    if(coordenadaX > 7){
        printf("Coordenada informada ultrapassam o tamanho do tabuleiro. Tente novamete!\n");
        return 1;
    }else if (coordenadaY > 7){
        printf("Coordenada informada ultrapassam o tamanho do tabuleiro. Tente novamete!\n");
        return 1;
    }
    int index = 0;
    for(int j = index; j < tamanhoColuna; j++){
        if(tabuleiro[coordenadaX][j + coordenadaY] != 0){
            printf("Posição x[%d] e y[%d] ocupada!\n", coordenadaX, j + coordenadaY);
            return 1;
        }
        tabuleiro[coordenadaX][j + coordenadaY] = navio[index];
        index++;
        if(index == 3){
            break;
        }
    }
    return 0;
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    const int LINHA = 10;
    const int COLUNA = 10;
    char colunasTabuleiro[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[LINHA][COLUNA];
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
    int coordenadaX = 3;
    int coordenadaY = 3;

    preencherTabuleiro(tabuleiro, LINHA, COLUNA);
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    coordenadaX--;  // subtrai coordenada tendo em vista que o tabuleiro começa na posicao 0 e não 1
    coordenadaY--;  // subtrai coordenada tendo em vista que o tabuleiro começa na posicao 0 e não 1

    navioVertical(tabuleiro, navio1, LINHA, COLUNA, coordenadaX, coordenadaY);

    coordenadaX = 8; // Se coordenada maior que 8 vair retornar erro, ultrapassa o tamanho do tabuleiro
    coordenadaY = 8; // Se coordenada maior que 8 vair retornar erro, ultrapassa o tamanho do tabuleiro
    coordenadaX--; // subtrai coordenada tendo em vista que o tabuleiro começa na posicao 0 e não 1
    coordenadaY--; // subtrai coordenada tendo em vista que o tabuleiro começa na posicao 0 e não 1
    int isErro = navioHorizontal(tabuleiro, navio2, LINHA, COLUNA, coordenadaX, coordenadaY); 

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    if(isErro == 0)
        exibirTabuleiro(tabuleiro, colunasTabuleiro, LINHA, COLUNA);
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
