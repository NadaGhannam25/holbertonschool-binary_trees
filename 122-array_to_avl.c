#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * Return: pointer to root of AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    size_t i;
    avl_t *root = NULL;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
        avl_insert(&root, array[i]);

    return (root);
}
