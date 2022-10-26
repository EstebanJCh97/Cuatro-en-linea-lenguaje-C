//
// Created by rodolfo on 20/3/21.
//

#ifndef IC_4700_LENGUAJES_2021_I_PROGRAMACI_N_IMPERATIVA_EN_C_TABLERO_H
#define IC_4700_LENGUAJES_2021_I_PROGRAMACI_N_IMPERATIVA_EN_C_TABLERO_H



int realizarJugada(char jugador, int columna, char tablero[7][7]);
int verificarFilaVacia(int columna, char tablero[7][7]);
int verificarTableroLleno(char tablero[7][7]);
void borrarTablero(char tablero[7][7]);
void dibujarNumeroColumnas(int columnas);
int imprimirTablero(char tablero[7][7]);




#endif //IC_4700_LENGUAJES_2021_I_PROGRAMACI_N_IMPERATIVA_EN_C_TABLERO_H
