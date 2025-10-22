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
 * level_order_insert - Inserts a node in the first available position
 * @root: Pointer to the root of the heap
 * @node: Node to insert
 *
 * Return: Pointer to inserted node
 */
heap_t *level_order_insert(heap_t *root, heap_t *node)
{
	heap_t **queue;
	heap_t *parent;
	size_t front = 0, back = 0;

	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	queue[back++] = root;

	while (front < back)
	{
		parent = queue[front++];
		if (!parent->left)
		{
			parent->left = node;
			node->parent = parent;
			free(queue);
			return (node);
		}
		else
			queue[back++] = parent->left;

		if (!parent->right)
		{
			parent->right = node;
			node->parent = parent;
			free(queue);
			return (node);
		}
		else
			queue[back++] = parent->right;
	}
	free(queue);
	return (NULL);
}

/**
 * heapify_up - Moves the node up to maintain Max Heap property
 * @node: Node to move up
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

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

	/* Insert node in level order */
	node = level_order_insert(*root, node);
	if (!node)
		return (NULL);

	/* Heapify up */
	heapify_up(node);

	return (node);
}

