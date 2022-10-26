//
// Created by rodolfo on 19/3/21.
//

#ifndef CUATROENLINEA_VALIDARGANE_H
#define CUATROENLINEA_VALIDARGANE_H

int conexiones;
int dimension;

int validarArriba(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]); //Contar conexiones hacia arriba
int validarDiagonalArribaDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]); //Contar conexiones Diagonal Derecha Arriba
int validarDiagonalAbajoDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]); //Contar conexiones Diagonal Abajo Arriba
int validarDerecha(int columna, int fila, char jugadorDeTurno, char tablero[dimension][dimension]); //Contar conexiones Derecha
int determinarGanador(char jugadorDeTurno, char tablero[dimension][dimension]); // Recibe cracter de jugador y tablero. Retorna ganador>0 si hay ganador 0 si no lo hay 

#endif //CUATROENLINEA_VALIDARGANE_H
