#include "binary_trees.h"

/**
 * create_node - Creates a new queue node
 * @node: Pointer to the binary tree node
 * Return: Pointer to the new queue node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new = malloc(sizeof(levelorder_queue_t));

	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * free_queue - Frees a queue
 * @head: Pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Adds a new node to the end of the queue
 * @node: Pointer to the binary tree node
 * @head: Pointer to the head of the queue
 * @tail: Double pointer to the tail of the queue
 * @func: Pointer to a function (unused)
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
	  levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new = create_node(node);
	(void)func;

	if (new == NULL)
	{
		free_queue(head);
		return;
	}

	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Removes the first node from the queue
 * @head: Double pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	if (head == NULL || *head == NULL)
		return;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head)
	{
		func(head->node->n);

		if (head->node->left)
			push(head->node->left, head, &tail, func);
		if (head->node->right)
			push(head->node->right, head, &tail, func);

		pop(&head);
	}
	free_queue(head);
}

