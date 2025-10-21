#include "binary_trees.h"

/**
* array_to_bst - builds a BST from an array
* @array: pointer to first element
* @size: number of elements
* Return: pointer to root node, or NULL
*/
bst_t *array_to_bst(int *array, size_t size)
{
bst_t *root = NULL;
size_t i;

if (array == NULL || size == 0)
return (NULL);

for (i = 0; i < size; i++)
bst_insert(&root, array[i]);

return (root);
}

