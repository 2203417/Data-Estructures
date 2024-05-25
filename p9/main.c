#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
// banderas de compilacion y como compilar el progama
// gcc - Wall -Werror -pendatic -std=c99 main.c funciones.c -o practica9
int main()
{

    int ciclo = 0;
    int op = 0;
    int data = 0;
    int position = 0;
    Heap *heap = initialize_heap(&heap);
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
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------
            changue_priority(heap);
            bubbling_up(heap);
            printf("Nuevo orden del heap\n");
            printf("Nuevo orden del heap\n");
            print_heap(heap);
            break;
        case 1:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------
            // print_heap(heap);
            build_tree_from_array(&heap, heap->root);
            print_tree(heap->root, 0);
            printf("\n");
            break;
        case 2:
            // -------------------------------------------------------------------INCOMPLETA-------------------------------------------------------------------
            printf("INGRESE EL NUMERO DE ARCHIVO\n");
            scanf("%d", &data);
            int *new_data = (int *)malloc(sizeof(int)); // Crear un nuevo entero en el heap
            *new_data = data;                           // Copiar el valor ingresado al nuevo entero
            insert(&heap, new_data);
            print_heap(heap);
            printf("\n");

            printf("\n");
            break;
        case 3:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------

            print_heap_like_queque(heap);
            printf("INGRESE EL NUMERO DE ARCHIVO\n");
            scanf("%d", &position);
            delete_file(heap, position);
            print_heap_like_queque(heap);
            print_heap(heap);
            break;
        case 4:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------
            all_file_deleter(heap);
            break;
        case 5:
            // -------------------------------------------------------------------COMPLETA-------------------------------------------------------------------
            process_first_file(heap);
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
    return 0;
}
