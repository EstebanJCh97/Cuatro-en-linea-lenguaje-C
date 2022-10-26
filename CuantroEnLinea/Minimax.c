#include <string.h>
#include <stdio.h>
#include "Minimax.h"
#include "matriz.h"
#include "ValidarGane.h"
int conexionesMinimax = 4;
int dimensionMinimax = 7;
char espacioVacio = ' ';

void copiarTablero(char tablero[dimensionMinimax][dimensionMinimax], char tableroJugadaCPU[dimensionMinimax][dimensionMinimax]) {
    memcpy(tableroJugadaCPU, tablero, sizeof(char) * dimensionMinimax * dimensionMinimax);
}

int obtenerFilaDesocupada(int columna, char tablero[dimensionMinimax][dimensionMinimax]) {
    int i;
    for (i = dimensionMinimax - 1; i >= 0; i--) {
        if (tablero[i][columna] == espacioVacio) {
            return i;
        }
    }
    return -1;
}

int verificarFicha(char jugador, int columna, char tablero[dimensionMinimax][dimensionMinimax]) {
    if (columna < 0 || columna >= dimensionMinimax) {
        return 4;
    }
    int fila = obtenerFilaDesocupada(columna, tablero);
    if (fila == -1) {
        return 2;
    }
    tablero[fila][columna] = jugador;
    return 3;
}



int encontrarFIlaVacia(int columna, char tablero[dimensionMinimax][dimensionMinimax]) {
    int fila;
    int filaencontrada = -1;
    for (fila = dimensionMinimax - 1; fila >= 0; fila--) {
        if (tablero[fila][columna] == espacioVacio) {
            filaencontrada = fila;
        }
    }
    return filaencontrada;
}

int JugadaComputadoraMinimax(char jugadorDeTurno, int indiceColumnas, char tablero[dimensionMinimax][dimensionMinimax]) {
    int validarJugada = 3;
    if (indiceColumnas < 0 || indiceColumnas >= dimensionMinimax) {
        validarJugada = 4;
    }
    int fila = encontrarFIlaVacia(indiceColumnas, tablero);
    if (fila == -1) {
        validarJugada = 2;
    }

    if(validarJugada == 3){
        tablero[fila][indiceColumnas] = jugadorDeTurno;

    }

    return validarJugada;
}
int encontrarFilaLlena(int columna, char tablero[dimensionMinimax][dimensionMinimax]) {
    int i;
    for (i = 0; i < dimensionMinimax; ++i) {
        if (tablero[i][columna] != ' ') {
            return i;
        }
    }
    return -1;
}

void mayorPuntuacionComputadora(char jugadorDeTurno, char tablero[dimensionMinimax][dimensionMinimax], int *puntajeComputadora, int *ColumnaJUgadaComputadora) {
    int MayorPuntaje = 0, ColumnaMayorPuntaje = -1;
    char tableroJugadaCPU[dimensionMinimax][dimensionMinimax];
    int indiceColumnas;
    for (indiceColumnas = 0; indiceColumnas < dimensionMinimax; ++indiceColumnas) {
        copiarTablero(tablero, tableroJugadaCPU);
        int jugadaValida = realizarJugada(jugadorDeTurno, indiceColumnas, tableroJugadaCPU); //Valida que la jugada es posible y no crea error
        if (jugadaValida == 3) {
            int filaDePiezaAColocar  = encontrarFilaLlena(indiceColumnas,tableroJugadaCPU);
            if (filaDePiezaAColocar !=-1){
                int contador = validarArriba(indiceColumnas,filaDePiezaAColocar,jugadorDeTurno,tableroJugadaCPU);
                if (contador > MayorPuntaje) {
                    MayorPuntaje = contador;
                    ColumnaMayorPuntaje = indiceColumnas;
                }
                contador = validarDiagonalArribaDerecha(indiceColumnas,filaDePiezaAColocar,jugadorDeTurno,tableroJugadaCPU);
                if (contador > MayorPuntaje) {
                    MayorPuntaje = contador;
                    ColumnaMayorPuntaje = indiceColumnas;
                }
                contador = validarDerecha(indiceColumnas,filaDePiezaAColocar,jugadorDeTurno,tableroJugadaCPU);
                if (contador > MayorPuntaje) {
                    MayorPuntaje = contador;
                    ColumnaMayorPuntaje = indiceColumnas;
                }
                contador = validarDiagonalAbajoDerecha(indiceColumnas,filaDePiezaAColocar,jugadorDeTurno,tableroJugadaCPU);
                if (contador > MayorPuntaje) {
                    MayorPuntaje = contador;
                    ColumnaMayorPuntaje= indiceColumnas;
                }
            }

        }
    }
    *puntajeComputadora = MayorPuntaje;

    *ColumnaJUgadaComputadora = ColumnaMayorPuntaje;


}

int encontrarfilaLLena(int columna, char tablero[dimensionMinimax][dimensionMinimax]) {
    int i;
    for (i = 0; i < dimensionMinimax; ++i) {
        if (tablero[i][columna] != ' ') {
            return i;
        }
    }
    return -1;
}

//Retorna 1 si columna central vacia
int verificarCentroVacio(char jugadorDeTurno, char tablero[dimensionMinimax][dimensionMinimax]) {
    int centroVacio = -1;
    char epsaciocentro = tablero[6][3];
    if(epsaciocentro = espacioVacio){
        centroVacio = 3;


    }
    return centroVacio;
}

int tomarPosicionCentral(char jugadorDeTurno, char tablero[dimensionMinimax][dimensionMinimax]) {


    int puntajeComputadora, ColumnaJUgadaComputadora;

    //Tomar centro si esta vacio
    int centroVacio = verificarCentroVacio(jugadorDeTurno, tablero);
    if (centroVacio = 3) {
        printf("*tomar centro*\n");
        return centroVacio;
    }
    //mayorPuntuacionComputadora(jugadorDeTurno, tablero, &puntajeComputadora, &ColumnaJUgadaComputadora);


    return 0;
}
int obtenerColumnaGanadora(char jugador, char tableroOriginal[dimensionMinimax][dimensionMinimax]) {
    char tableroCopia[dimensionMinimax][dimensionMinimax];
    int i;
    copiarTablero(tableroOriginal,tableroCopia);
    for (i = 0; i < dimensionMinimax; i++) {
        
        int resultado = verificarFicha(jugador, i,tableroCopia);
        if (resultado == 3) {
            int gana = determinarGanador(jugador, tableroCopia);
            if (gana != 0) {
                return i;
            }
        }
    }
    return 0;
}
