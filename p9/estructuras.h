#include <stdio.h>
#pragma once
typedef struct Node
{
    struct Node *right;
    struct Node *left;
    void *data; // data
} Node;

typedef struct
{
    Node *root;
    Node **node_array; // para almacenar las referencais de los nodos creados
    int size;
    int typeofheap; // si es 1 es minHeap o -1 si es MaxHeap
} Heap;