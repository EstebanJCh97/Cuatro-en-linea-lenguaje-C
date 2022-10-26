//
// Created by rodolfo on 19/3/21.
//

#ifndef CUATROENLINEA_CUATROENLINEA_H
#define CUATROENLINEA_CUATROENLINEA_H

void cuatroEnLinea(); //Inicia el juego, lleva turnos de jugadores
char jugadorSiguiente(char jugador);
int remplazoDeJuego();
char jugadorInicial();
int Rangorandom(int minimo, int maximo);
int pedirJugada();
int elegirColumnaCpu(char jugador, char tablero[dimension][dimension]);


#endif //CUATROENLINEA_CUATROENLINEA_H
