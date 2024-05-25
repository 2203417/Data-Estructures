#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define MAX 100
int compare(void *a, void *b) // esta expresion retorna un 1 si num1 es mayor a num2
{
    // como utilzamos void pointers casteamos a dato entero
    int num1 = *((int *)a);
    int num2 = *((int *)b); // se castea a un dato int
    if (num1 <= num2)
    {
        return 1;
    }
    return -1;
    // esta expresion retorna un 1 si num1 es mayor a num2
}
// -------------------------------------------------------------------FUNCIONES INICIALIZADORAS-------------------------------------------------------------------
Heap *initialize_heap()
{
    Heap *new_heap = (Heap *)malloc(sizeof(Heap));                // se crea un nuevo heap
    new_heap->root = NULL;                                        // se inicializa la raiz del heap
    new_heap->node_array = (Node **)malloc(MAX * sizeof(Node *)); // se crea un arreglo de nodos doble apuntador por que es un arreglo de nodos
    new_heap->size = 0;
    new_heap->typeofheap = 0; // se inicializa el arreglo de nodos
    return new_heap;
}

Node *initialize_node()
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // se crea un nuevo nodo
    new_node->data = NULL;                         // se inicializa el dato del nodo
    new_node->left = NULL;                         // se inicializa el hijo izquierdo
    new_node->right = NULL;
    return new_node; // se inicializa el hijo derecho
}
void process_first_file(Heap *heap)
{
    if (heap->size == 0)
    {
        printf("No hay archivos para procesar\n");
        return;
    }
    printf("Procesando archivo #%d\n", *((int *)heap->node_array[0]->data));
    delete_file(heap, 0);
}
void insert(Heap **heap, void *data)
{
    if (((*heap)->size) == 0)
    {
        // printf("Posicion %d\n", (*heap)->size);
        Node *new_node = initialize_node(); // se crea un nuevo nodo
        new_node->data = data;              // se le asigna el dato al nodo
        // printf("Data antes de entrar %d\n", *(int *)new_node->data);
        (*heap)->root = new_node;                      // se le asigna el nodo a la raiz
        (*heap)->node_array[(*heap)->size] = new_node; // se guarda el nodo en el arreglo y en la posicion actual(*heap)->node_array[(*heap)->size] = new_node; // se guarda el nodo en el arreglo y en la posicion actual
        (*heap)->size++;
        return; // se incrementa el tamaño del heap
    }
    else
    {
        // printf("guardado en el array de heap = %d\n", *((int *)(*heap)->node_array[(*heap)->size - 1]->data));
        Node *new_node = initialize_node(); // se crea un nuevo nodo
        new_node->data = data;              // le asignamos la data
        if ((*heap)->size % MAX == 0)
        {
            // printf("Heap lleno\n"); // por lo tanto creamos mas memoria
            (*heap)->node_array = (Node **)realloc((*heap)->node_array, MAX * sizeof(Node *));
            if ((*heap)->node_array == NULL)
            {
                // printf("No se pudo reservar memoria\n");
                return;
            }
        }
        // printf("Data antes de entrar %d\n", *(int *)new_node->data);
        // printf("Posicion %d\n", (*heap)->size);
        // printf("guardado en el array de heap = %d\n", *((int *)(*heap)->node_array[(*heap)->size - 1]->data));
        (*heap)->node_array[(*heap)->size] = new_node; // se guarda el nodo en el arreglo y en la posicion actual
        (*heap)->size++;                               // se incrementa el tamaño del heap
        bubbling_up(*heap);
        //  printf("dato guardado %d\n", *((int *)(*heap)->node_array[(*heap)->size]->data));
    }
}

void print_heap(Heap *heap)
{
    int i;
    if (heap->size == 0)
    {
        printf("Heap vacio\n");
        return;
    }
    int level = 0;
    int levelindex = 1;
    int counter = 0;
    while (counter < heap->size)
    {
        printf("Level %d: ", level);
        for (i = 0; i < levelindex && counter < heap->size; i++) // se imprime el nivel
        {
            if (heap->node_array[counter]->data != NULL)
            {
                printf("%d ", *((int *)heap->node_array[counter]->data));
            }
            counter++;
        }
        printf("\n");
        level++;
        levelindex *= 2;
    }
}
void print_heap_2(Heap *heap) // funcion a medias
{
    if (heap->size == 0)
    {
        printf("La heap esta vacia :P\n");
        return;
    }
    printf("Heap: \n");
    for (int i = 0; i < heap->size; i++)
    {
        printf("[%d]-Archivo numero #%d\n", i, *((int *)heap->node_array[i]->data));
    }
}
void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void delete_file(Heap *heap, int file) // el heap y la posicion dela rchivo
{
    if (heap->size < file)
    {
        printf("No se puede eliminar el archivo\n");
        return;
    }
    swap((int **)&heap->node_array[file], (int **)&heap->node_array[heap->size - 1]); // cambiamos el dato de la posicion file por el dato de la ultima posicion
    heap->node_array[heap->size - 1] = NULL;
    heap->size--;      // eliminamos el archivo
    bubbling_up(heap); // reacomodamos los elementos
}

void print_heap_like_queque(Heap *heap)
{
    if (heap->size == 0)
    {
        printf("La heap esta vacia :P\n");
        return;
    }
    printf("Heap: \n");
    for (int i = 0; i < heap->size; i++)
    {
        printf("[%d]-Archivo numero #%d\n", i, *((int *)heap->node_array[i]->data));
    }
}

void heapify(Heap *heap, int i) // FUNCION PESADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
{
    int largest = i; // se inicializa el mas grande
    // formulazo donde i es el indice del nodo padre
    int left = 2 * i + 1;  // se obtiene el hijo izquierdo
    int right = 2 * i + 2; // se obtiene el hijo derecho
    //
    if (heap->typeofheap == 1)                                                                                // definimos el tipo de heap
    {                                                                                                         // si es minHeap 1 o maxHeap es -1.
        if (left < heap->size && compare(heap->node_array[left]->data, heap->node_array[largest]->data) == 1) // si el hijo izquierdo es mayor que el padre
        {
            largest = left; // se cambia el mas grande es el indice del nodo hijo izquierdo
        }
        if (right < heap->size && compare(heap->node_array[right]->data, heap->node_array[largest]->data) == 1) // si el hijo derecho es mayor que el padre
        {
            largest = right; // se cambia el mas grande es el indice del nodo hijo izquierdo
        } // o sea si es mayor que su nodo padre entonces se considera como el mayor
    }
    else
    {
        if (left < heap->size && compare(heap->node_array[left]->data, heap->node_array[largest]->data) == -1) // si el hijo izquierdo es mayor que el padre
        {
            largest = left; // se cambia el mas grande es el indice del nodo hijo izquierdo
        }
        if (right < heap->size && compare(heap->node_array[right]->data, heap->node_array[largest]->data) == -1) // si el hijo derecho es mayor que el padre
        {
            largest = right; // se cambia el mas grande es el indice del nodo hijo izquierdo
        } // o sea si es mayor que su nodo padre entonces se considera como el mayor
    }
    if (largest != i) // si el mas grande no es el padre
    {
        swap((int **)&heap->node_array[i], (int **)&heap->node_array[largest]); // se cambia el padre por el mas grande
        heapify(heap, largest);                                                 // se llama recursivamente a la funcion
    }
}

void bubbling_up(Heap *heap) // despues de insertar elementos se tiene que reacomodar los elementos
{
    int StartIndex = (heap->size / 2) - 1; // se obtiene el padre
    printf("StartIndex %d\n", StartIndex);
    for (int i = StartIndex; i >= 0; i--) // desde el indice padre, hasta que sea 0 se llama a la funcion heapify
    {                                     // esto se hace por que despues de insertar un elemento se tiene que reacomodar los elementos
        heapify(heap, i);                 // se llama recursivamente a la funcion
    }
    build_tree_from_array(&heap, heap->root);
    print_tree(heap->root, 0);
    printf("\n");
}

void changue_priority(Heap *heap)
{
    if (heap->typeofheap == 1)
    {
        heap->typeofheap = -1;
    }
    else
    {
        heap->typeofheap = 1;
    }
}

void build_tree_from_array(Heap **heap, Node *root)
{
    // Se asigna la raíz al nodo en la posición 0 del arreglo de nodos
    // printf("HEAPSIZE--%d ", (*heap)->size);
    for (int j = 0; j < (*heap)->size; j++)
    {
        int left_index = 2 * j + 1;  // Se obtiene el índice del hijo izquierdo
        int right_index = 2 * j + 2; // Se obtiene el índice del hijo derecho
        // printf("LEFT--%d ", left_index);
        // printf("RIGHT--%d ", right_index);
        // printf("HEAPSIZE--%d ", (*heap)->size);
        // printf("CONTADOR %d", j);
        (*heap)->node_array[j]->left = (*heap)->node_array[left_index];

        (*heap)->node_array[j]->right = (*heap)->node_array[right_index];
    }
    (*heap)->root = (*heap)->node_array[0];
    // printf("ROOT -- %d\n", *((int *)(*heap)->root->data));
}

void build_tree_from_array_2(Heap **heap, Node *root, int i)
{
    // Se asigna la raíz al nodo en la posición 0 del arreglo de nodos
    if (root == NULL)
    {
        return;
    }
    if (i == 0)
    {
        (*heap)->root = (*heap)->node_array[0];
        printf("ROOT -- %d\n", *((int *)(*heap)->root->data));
    }

    int left_index = 2 * i + 1;  // Se obtiene el índice del hijo izquierdo
    int right_index = 2 * i + 2; // Se obtiene el índice del hijo derecho
    printf("LEFT--%d ", left_index);
    printf("RIGHT--%d ", right_index);
    printf("HEAPSIZE--%d ", (*heap)->size);

    // Se comprueba si el hijo izquierdo existe y se asigna como hijo izquierdo del nodo actual
    if (left_index <= (*heap)->size)
    {
        if (i == 0)
        {
            root->left = (*heap)->node_array[left_index];
            root->right = (*heap)->node_array[right_index];
            printf("LEFT->DATA -- %d \n", *((int *)root->left->data));
            build_tree_from_array_2(heap, root->left, left_index);
        }
        else if (i != 0)
        {
            root = (*heap)->node_array[left_index];
            root->right = (*heap)->node_array[right_index];
            printf("LEFT->DATA  -- %d \n", *((int *)root->data));
            build_tree_from_array_2(heap, root->left, left_index);
        }
        // root->left = (*heap)->node_array[left_index];
        //  Se construye recursivamente el subárbol izquierdo
        printf("Salio de left\n");
    }
}

void print_tree(Node *node, int nivel)
{
    int i;
    if (node != NULL)
    {
        printf("%d", *((int *)node->data));
        if (node->right != NULL)
        {
            printf("\n");
            for (i = 0; i < nivel + 1; i++)
            {
                if (i == nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            print_tree(node->right, nivel + 1);
        }
        if (node->left != NULL)
        {
            printf("\n");
            for (i = 0; i < nivel + 1; i++)
            {
                printf(" |      ");
            }
            printf("\n");
            for (i = 0; i < nivel + 1; i++)
            {
                if (i == nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            print_tree(node->left, nivel + 1);
        }
    }
}

void all_file_deleter(Heap *heap)
{
    for (int i = 0; i < ((Heap *)heap)->size; i++)
    {
        free(((Heap *)heap)->node_array[i]->data);
        free(((Heap *)heap)->node_array[i]);
    }
    heap->size = 0;
}