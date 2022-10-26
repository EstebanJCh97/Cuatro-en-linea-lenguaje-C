//
// Created by rodolfo on 20/3/21.
//
#include "ValidarGane.h"

int conexiones = 4;
int dimension = 7;

int validarArriba(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]){
    int filaInicial;
    if (fila - conexiones >= 0) {
        filaInicial = fila - conexiones + 1; //Posicion de cuarta ficha
    }
    else {
        filaInicial = 0; // Desde fila 3 hacia abajo empezar en primera fila
    }

    int contadorDefichas = 0;
    for (; filaInicial <= fila; filaInicial++) {
        if (tablero[filaInicial][columna] == jugadorDeTurno) {
            contadorDefichas++;
        } else {
            contadorDefichas = 0;
        }
    }
    return contadorDefichas;

}



int validarDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]) {
    int columnaFinal;
    if (columna + conexiones < dimension) {
        columnaFinal = columna + conexiones - 1; //Posicion de cuarta ficha
    }
    else {
        columnaFinal = dimension - 1;
    }
    int contadorDefichas = 0;
    for (; columna <= columnaFinal; columna++) {
        if (tablero[fila][columna] == jugadorDeTurno) {
            contadorDefichas++;
        } else {
            contadorDefichas = 0;
        }
    }
    return contadorDefichas;
}

int validarDiagonalArribaDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]) {
    int filaInicial;
    if (fila - conexiones >= 0) {
        filaInicial = fila - conexiones + 1; //Posicion de cuarta ficha
    }
    else {
        filaInicial = 0; // Desde fila 3 hacia abajo empezar en primera fila
    }
    int columnaFinal;
    if (columna + conexiones < conexiones) {
        columna + conexiones - 1; //Posicion de cuarta ficha
    }
    else {
        columnaFinal = dimension - 1;
    }
    int contadorDefichas = 0;
    while (columna <= columnaFinal && filaInicial <= fila) {
        if (tablero[fila][columna] == jugadorDeTurno) {
            contadorDefichas++;
        } else {
            contadorDefichas = 0;
        }
        columna++;
        fila--;
    }
    return contadorDefichas;
}

int validarDiagonalAbajoDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]) {
    int columnaFinal;
    if (columna + conexiones < dimension) {
        columnaFinal = columna + conexiones - 1; //Posicion de cuarta ficha
    }
    else {
        columnaFinal = dimension - 1;
    }
    int filaInicial;
    if (fila + conexiones < dimension) {
        filaInicial = fila + conexiones - 1; //Posicion de cuarta ficha
    }
    else {
        filaInicial = dimension - 1; // Desde fila 3 hacia abajo empezar en primera fila
    }

    int contadorDefichas = 0;
    while (columna <= columnaFinal && fila <= filaInicial) {
        if (tablero[fila][columna] == jugadorDeTurno) {
            contadorDefichas++;
        } else {
            contadorDefichas = 0;
        }
        columna++;
        fila++;
    }
    return contadorDefichas;
}



int determinarGanador(char jugadorDeTurno, char tablero[dimension][dimension]) {
    int fila;
    int ganador = 0;
    for (fila = 0; fila < dimension; fila++) {
        int columna;
        for (columna = 0; columna < dimension; columna++) {
            int conectaArriba = validarArriba(columna, fila, jugadorDeTurno, tablero);
            if (conectaArriba >= conexiones) {
                ganador = 1;
            }
            if (validarDerecha(columna, fila, jugadorDeTurno, tablero) >= conexiones) {
                ganador = 2;
            }
            if (validarDiagonalArribaDerecha(columna, fila, jugadorDeTurno, tablero) >= conexiones) {
                ganador = 3;
            }
            if (validarDiagonalAbajoDerecha(columna, fila, jugadorDeTurno, tablero) >= conexiones) {
                ganador = 4;
            }
        }
    }
    return ganador;
}


/* Tablero de pruebas
 *     char abc[7][7] ={
            {' ','o',' ',' ',' ',' ',' '},
            {' ',' ','o',' ',' ',' ',' '},
            {' ',' ',' ','o',' ',' ',' '},
            {' ',' ',' ',' ','o',' ',' '},
            {' ',' ',' ','x',' ',' ',' '},
            {' ',' ',' ','x',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' '}
    };
    int ganador = determinarGanador('o', abc);
 */