#include <stdio.h>
#include <stdlib.h>
#include "matriz.c"
#include "ValidarGane.c"
#include "Minimax.c"
#include "CuatroEnLinea.h"


void cuatroEnLinea(){

    char tableroOriginal[dimension][dimension];
    char jugadorActual =  jugadorInicial();
    borrarTablero(tableroOriginal);
    imprimirTablero(tableroOriginal);

    while (1){
        int posicionAJugar = 0;
        printf("\n Turno del Jugador %c\n",jugadorActual);
        imprimirTablero(tableroOriginal);
        if (jugadorActual == 'x'){
            printf("Computadora realizando jugada...");
            posicionAJugar = elegirColumnaCpu(jugadorActual,tableroOriginal);
            
        }else{
            posicionAJugar= pedirJugada();
        }
        int juego = realizarJugada(jugadorActual,posicionAJugar,tableroOriginal);
        if (juego == 1){
            printf("Error: Columna llena");
            jugadorActual = jugadorSiguiente(jugadorActual);
        }else if (juego == 2)
        {
            printf("Fila Incorrecta");
            jugadorActual = jugadorSiguiente(jugadorActual);
        }else if (juego == 3)
        {
            int g = determinarGanador(jugadorActual, tableroOriginal);
            if (g != 0) {
                imprimirTablero(tableroOriginal);
                printf("Gana el jugador %c.", jugadorActual);
                break;
            } else if (verificarTableroLleno(tableroOriginal)) {
                imprimirTablero(tableroOriginal);
                printf("Empate");
                break;
            }
        }
        jugadorActual = jugadorSiguiente(jugadorActual);

    }

}


char jugadorInicial() {

    char Jugador_1 = 'x';
    char Jugador_2 = 'o';

    int numero = Rangorandom(0, 1);
    if (numero) {
        return Jugador_1 ;
    } else {
        return Jugador_2;
    }
}


char jugadorSiguiente(char jugador) {
    if (jugador == 'x') {
        return 'o';
    } else {
        return 'x';
    }
}

int pedirJugada() {
    int columna = 0;
    printf("Seleccione la columna en la que desea jugar: ");
    scanf("%d", &columna);
    columna--;
    return columna;
}


int Rangorandom(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int elegirColumnaCpu(char jugador, char tablero[dimension][dimension]) {
    printf("elegirColumna");
    int columnaDeCuartaFicha = obtenerColumnaGanadora(jugador, tablero);
    if (columnaDeCuartaFicha != 0) {
        
        return columnaDeCuartaFicha;
    }
    
   
    int posibleColumnaGanadoraDeOponente = obtenerColumnaGanadora('o', tablero);
    if (posibleColumnaGanadoraDeOponente != 0) {
        return posibleColumnaGanadoraDeOponente;
    }
    int puntuacionComputadora, posicionDelCpu;
    mayorPuntuacionComputadora('o', tablero, &puntuacionComputadora, &posicionDelCpu);
    printf("%d %d\n",&puntuacionComputadora,&posicionDelCpu);
    int puntuacionJugador, posicionDelJugador;

    mayorPuntuacionComputadora('x', tablero, &puntuacionJugador, &posicionDelJugador);
    printf("%d %d\n",&puntuacionJugador,&posicionDelJugador);
    if (puntuacionJugador > puntuacionComputadora) {
        
        return posicionDelJugador;
    } else if (puntuacionComputadora > 1) {
        return posicionDelCpu;
    }
    // Si no, regresar la central por si está desocupada

    int columnaCentral = tomarPosicionCentral(jugador, tablero);
    if (columnaCentral != -1) {
        printf("*elijo ponerla en el centro*\n");
        return columnaCentral;
    }
    // Finalmente, devolver la primera disponible de manera aleatoria
    int columna = jugadaAleatorio(0, dimensionMinimax-1);
    if (columna != -1) {
        printf("*elijo la primera vacía aleatoria*\n");
        return columna;
    }
    printf("Esto no debería suceder\n");
    return 0;
}
int jugadaAleatorio(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
int main() {
    cuatroEnLinea();

    return 0;
}
