#include <stdio.h>

char map[10][10];  // Mapa 10x10
int vidas = 3;     // Vidas iniciales del jugador
int playerX = 0;   // Posición inicial del jugador en X
int playerY = 0;   // Posición inicial del jugador en Y

// Función para inicializar el mapa
void inicializarMapa() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '-';
        }
    }
    map[4][4] = 'R';  // Colocamos el reto del ahorcado en la posición [4][4]
}

// Función para mostrar el mapa
void mostrarMapa() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerX && j == playerY)
                printf("X ");  // Mostramos el jugador
            else
                printf("%c ", map[i][j]);  // Mostramos el mapa
        }
        printf("\n");
    }
}

// Función que implementa el juego del ahorcado
int ahorcado() {
    char palabra[] = "gato";  // Palabra a adivinar
    char adivinada[] = "____";  // Estado de la palabra adivinada
    char intento;
    int letrasCorrectas = 0;
    int vidasReto = 3;  // Vidas para el reto del ahorcado

    while (vidasReto > 0 && letrasCorrectas < 4) {
        printf("\nPalabra: %s\n", adivinada);
        printf("Vidas restantes: %d\n", vidasReto);
        printf("Introduce una letra: ");
        scanf_s(" %c", &intento);

        int acierto = 0;
        for (int i = 0; i < 4; i++) {
            if (palabra[i] == intento && adivinada[i] == '_') {
                adivinada[i] = intento;
                letrasCorrectas++;
                acierto = 1;
            }
        }

        if (!acierto) {
            printf("¡Letra incorrecta!\n");
            vidasReto--;
        }
    }

    if (letrasCorrectas == 4) {
        printf("\n¡Has adivinado la palabra!\n");
        return 1;  // El reto ha sido completado
    }
    else {
        printf("\n¡Te has quedado sin vidas! La palabra era: %s\n", palabra);
        return 0;  // El jugador falló el reto
    }
}

// Función principal
int main() {
    int juegoTerminado = 0;  // Variable para saber si el juego ha terminado
    char movimiento;

    inicializarMapa();  // Inicializamos el mapa

    while (!juegoTerminado && vidas > 0) {
        mostrarMapa();  // Mostramos el mapa actual
        printf("Vidas: %d\n", vidas);
        printf("Moverse con WASD: ");
        scanf_s(" %c", &movimiento);

        // Movemos al jugador según la entrada del usuario
        if (movimiento == 'w' && playerX > 0) playerX--;
        else if (movimiento == 's' && playerX < 9) playerX++;
        else if (movimiento == 'a' && playerY > 0) playerY--;
        else if (movimiento == 'd' && playerY < 9) playerY++;

        // Si el jugador llega a la posición del reto (4, 4)
        if (playerX == 4 && playerY == 4) {
            printf("¡Has encontrado el reto del ahorcado!\n");
            if (ahorcado()) {
                juegoTerminado = 1;  // El jugador completó el reto
            }
            else {
                vidas = 0;  // El jugador perdió todas sus vidas
            }
        }
    }

    if (vidas == 0) {
        printf("Game Over. Te has quedado sin vidas.\n");
    }
    else if (juegoTerminado) {
        printf("¡Felicidades! Has completado el juego.\n");
    }

    return 0;
}
