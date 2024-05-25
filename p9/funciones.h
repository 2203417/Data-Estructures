
#include "estructuras.h"

int compare(void *a, void *b);

Heap *initialize_heap();

Node *initialize_node();

void insert(Heap **heap, void *data);

void print_heap(Heap *heap);

void print_heap_2(Heap *heap);
void swap(int **a, int **b);

void delete_file(Heap *heap, int file);

void print_heap_like_queque(Heap *heap);

void heapify(Heap *heap, int i);

void bubbling_up(Heap *heap);

void print_tree(Node *node, int nivel);

void build_tree_from_array(Heap **heap, Node *root);

void changue_priority(Heap *heap);

void process_first_file(Heap *heap);

void all_file_deleter(Heap *heap);

void build_tree_from_array_2(Heap **heap, Node *root, int i);