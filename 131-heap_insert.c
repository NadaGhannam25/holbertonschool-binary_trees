#include "binary_trees.h"
#include <stdlib.h>

/**
* swap_values - Swaps the values of two heap nodes
* @a: Pointer to first node
* @b: Pointer to second node
*/
void swap_values(heap_t *a, heap_t *b)
{
int tmp;

if (!a || !b)
return;
tmp = a->n;
a->n = b->n;
b->n = tmp;
}

/**
* heap_insert - Inserts a value in a Max Binary Heap
* @root: Double pointer to the root of the heap
* @value: Value to insert
*
* Return: Pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *node, *parent;
heap_t **queue;
size_t front = 0, back = 0;

if (!root)
return (NULL);

/* Create new node */
node = binary_tree_node(NULL, value);
if (!node)
return (NULL);

/* If heap empty, new node becomes root */
if (!*root)
{
*root = node;
return (node);
}

/* Level-order insertion to keep completeness */
queue = malloc(sizeof(heap_t *) * 1024);
if (!queue)
{
free(node);
return (NULL);
}
queue[back++] = *root;
while (front < back)
{
parent = queue[front++];
if (!parent->left)
{
parent->left = node;
node->parent = parent;
break;
}
else
queue[back++] = parent->left;

if (!parent->right)
{
parent->right = node;
node->parent = parent;
break;
}
else
queue[back++] = parent->right;
}
free(queue);

/* Heapify up to maintain Max Heap */
while (node->parent && node->n > node->parent->n)
{
swap_values(node, node->parent);
node = node->parent;
}

return (node);
}

