#include "binary_trees.h"
#include <stdlib.h>

/* Forward declaration */
static avl_t *avl_remove_node(avl_t *root, int value);
static avl_t *min_value_node(avl_t *node);

/**
* min_value_node - Find the node with the minimum value in a tree
* @node: Pointer to the tree
* Return: Pointer to the node with the minimum value
*/
static avl_t *min_value_node(avl_t *node)
{
avl_t *current;

current = node;
while (current && current->left)
current = current->left;
return current;
}

/**
* avl_remove_node - Remove a node from the tree recursively
* @root: Pointer to the root node
* @value: Value to remove
* Return: Pointer to the new root after removal
*/
static avl_t *avl_remove_node(avl_t *root, int value)
{
avl_t *temp;
int balance;

temp = NULL;

if (!root)
return NULL;

if (value < root->n)
root->left = avl_remove_node(root->left, value);
else if (value > root->n)
root->right = avl_remove_node(root->right, value);
else
{
/* Node found */
if (!root->left || !root->right)
{
temp = root->left ? root->left : root->right;
if (!temp)
{
temp = root;
root = NULL;
}
else
{
*root = *temp;
}
free(temp);
}
else
{
temp = min_value_node(root->right);
root->n = temp->n;
root->right = avl_remove_node(root->right, temp->n);
}
}

if (!root)
return root;

/* Rebalance */
balance = binary_tree_balance(root);

/* Left Left */
if (balance > 1 && binary_tree_balance(root->left) >= 0)
return binary_tree_rotate_right(root);

/* Left Right */
if (balance > 1 && binary_tree_balance(root->left) < 0)
{
root->left = binary_tree_rotate_left(root->left);
return binary_tree_rotate_right(root);
}

/* Right Right */
if (balance < -1 && binary_tree_balance(root->right) <= 0)
return binary_tree_rotate_left(root);

/* Right Left */
if (balance < -1 && binary_tree_balance(root->right) > 0)
{
root->right = binary_tree_rotate_right(root->right);
return binary_tree_rotate_left(root);
}

return root;
}

/**
* avl_remove - Removes a node from an AVL tree
* @root: Pointer to the root node of the tree
* @value: Value to remove
* Return: Pointer to the new root after removal and rebalancing
*/
avl_t *avl_remove(avl_t *root, int value)
{
return avl_remove_node(root, value);
}

