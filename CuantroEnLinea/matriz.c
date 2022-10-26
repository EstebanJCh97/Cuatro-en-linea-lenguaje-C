#include "matriz.h"
#include <stdio.h>
#include "ValidarGane.h"


int realizarJugada(char jugador, int columna, char tablero[dimension][dimension]) {
    if (columna < 0 || columna >= dimension) {
        printf("%d",columna);
        printf( "Selecciono una columna que no existe" );
	return 1;
    }
    int fila = verificarFilaVacia(columna, tablero);
    if (fila == -1) {
	      printf( "Columna llena, seleccione otra columna para seguir jugando" );
	      return 2;
    }
    tablero[fila][columna] = jugador;
    return 3;

}


int verificarFilaVacia(int columna, char tablero[dimension][dimension]) {
    int indice;
    for (indice = dimension - 1; indice >= 0; indice--) {
        if (tablero[indice][columna] == ' '){
            return indice;
        }
    }

    printf("Fila no valida");	
    return -1;
  
}


int verificarTableroLleno(char tablero[dimension][dimension]) {
    int indice;
    for (indice = 0; indice < dimension; ++indice) {
        int validando = verificarFilaVacia(indice, tablero);
        if (validando != -1) {
            return 0;
        }
    }
    return 1;
}

void borrarTablero(char tablero[dimension][dimension]) {
    int indice;
    for (indice = 0; indice < dimension; ++indice) {
        int subindice;
        for (subindice = 0; subindice < dimension; ++subindice) {
            tablero[indice][subindice] = ' ';
        }
    }
}

void dibujarNumeroColumnas(int columnas) {
    printf("\n");
    int i;
    for (i = 0; i < columnas; ++i) {
        printf("|%d", i + 1);
        if (i + 1 >= columnas) {
            printf("|");
        }

    }
}

int imprimirTablero(char tablero[dimension][dimension]) {
    dibujarNumeroColumnas(dimension);
    printf("\n");
    int i;
    for (i = 0; i < dimension; ++i) {
        int j;
        for (j = 0; j < dimension; ++j) {
            printf("|");
            if (tablero[i][j]=='x'){
                
                printf("\033[1;31m");
            }else if(tablero[i][j]=='o'){
                printf("\033[1;33m");
            }
            printf("%c", tablero[i][j]);
            printf("\033[0m");
            if (j + 1 >= dimension) {
                printf("|");
            }
        }
        printf("\n");
    }
    return 0;
}



