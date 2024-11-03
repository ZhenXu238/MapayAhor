#include <stdio.h>

char mapa[10][10];
int vidas = 5;
int X = 0;
int Y = 0;

void inicializarMapa() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mapa[i][j] = '-';
        }
    }
    mapa[4][4] = 'R';  
    mapa[9][9] = 'F';  
}


void mostrarMapa() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == X && j == Y)
                printf("X ");
            else
                printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}


int ahorcado(char palabra[], char adivinada[], int longitud) {
    char intento;
    int letrasCorrectas = 0;
    int vidasReto = 5;

    while (vidasReto > 0 && letrasCorrectas < longitud) {
        printf("\nPalabra: %s\n", adivinada);
        printf("Vidas restantes: %d\n", vidasReto);
        printf("Introduce una letra: ");
        scanf_s(" %c", &intento);

        int acierto = 0;
        for (int i = 0; i < longitud; i++) {
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

    if (letrasCorrectas == longitud) {
        printf("\n¡Has adivinado la palabra!\n");
        return 1;
    }
    else {
        printf("\n¡Te has quedado sin vidas!\n");
        return 0;
    }
}

int main() {
    int juegoTerminado = 0;
    char movimiento;

    inicializarMapa();

    while (!juegoTerminado && vidas > 0) {
        mostrarMapa();
        printf("Vidas: %d\n", vidas);
        printf("Moverse con WASD: ");
        scanf_s(" %c", &movimiento);

       
        if (movimiento == 'w' && X > 0) X--;
        else if (movimiento == 's' && X < 9) X++;
        else if (movimiento == 'a' && Y > 0) Y--;
        else if (movimiento == 'd' && Y < 9) Y++;

        //Primera palabra
        if (X == 4 && Y == 4) {
            printf("¡Has encontrado el reto del ahorcado!\n");
            char palabra1[] = "apruebamepol";
            char adivinada1[] = "____________";
            if (ahorcado(palabra1, adivinada1, 12)) {
                juegoTerminado = 1;
            }
            else {
                vidas = 0;
            }
        }

        //Segunda palabra
        if (X == 9 && Y == 9) {
            printf("¡Has encontrado el reto del ahorcado!\n");
            char palabra2[] = "porfavor";
            char adivinada2[] = "________";
            if (ahorcado(palabra2, adivinada2, 8)) {
                juegoTerminado = 1;
            }
            else {
                vidas = 0;
            }
        }
    }

   
    if (vidas == 0) {
        printf("Juego terminado.\n");
    }
    else if (juegoTerminado) {
        printf("¡Felicidades! Has completado el juego.\n");
    }

    return 0;
}
