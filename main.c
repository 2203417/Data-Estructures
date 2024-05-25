#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
// banderas de compilacion y como compilar el progama
// gcc - Wall -Werror -pendatic -std=c99 main.c funciones.c -o practica10

int main()
{

    int ciclo = 0;
    int op = 0;
    while (ciclo == 0)
    {
        // system("clear");
        printf("[0] CAMBIAR PRIORIDAD\n");
        printf("[1] MOSTRAR COLA DE IMPRESION\n");
        printf("[2] AGREGAR ARCHIVO\n");
        printf("[3] ELIMINAR ARCHIVO\n");
        printf("[4] ELIMINAR TODO LOS ARCHIVOS\n");
        printf("[5] PROCESAR/IMPRIMIR ARCHIVO\n");
        printf("[6] TERMINAR PROGAMA\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:

            break;
        case 1:

            break;
        case 2:
            // -------------------------------------------------------------------INCOMPLETA-------------------------------------------------------------------
            printf("\n");
            break;
        case 3:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------

            break;
        case 4:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------

            break;
        case 5:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------

            break;
        case 6:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------
            printf("Saliendo\n");
            ciclo = 1;
            break;
        default:
            printf("OPCION NO VALIDA\n");
            break;
        }
    }
}