//
// Created by rodolfo on 19/3/21.
//

#ifndef CUATROENLINEA_MINIMAX_H
#define CUATROENLINEA_MINIMAX_H


int conexionesMinimax;
int dimensionMinimax;
char espacioVacio;

void copiarTablero(char tablero[7][7], char nuevoTablero[7][7]);
int juagadaComputadora(char jugadorDeTurno, char tablero[7][7]);
int tomarCentro(char jugadorDeTurno, char tablero[7][7]);
int tomarCualquiera(char jugadorDeTurno, char tablero[7][7]);
int tomarColumnaMax(char jugadorDeTurno, char tablero[7][7], int *cuenta,int *index);
int tomarFilaLlena(int columna, char tablero[7][7]);
int conectaCuatro(char jugadorDeTurno, char tablero[7][7]);
int encontrarFIlaVacia(int columna, char tablero[dimensionMinimax][dimensionMinimax]);
int numeroRandom(int minimo, int maximo);
int elegirColumnaCpu(char jugadorDeTurno, char tablero[dimensionMinimax][dimensionMinimax]);
int obtenerColumnaGanadora(char jugador, char tableroOriginal[dimensionMinimax][dimensionMinimax]);
int verificarFicha(char jugador, int columna, char tablero[dimensionMinimax][dimensionMinimax]);

#endif //CUATROENLINEA_MINIMAX_H

