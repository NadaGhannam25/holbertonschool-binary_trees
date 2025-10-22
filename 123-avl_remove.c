#include "binary_trees.h"

/**
* avl_remove - Removes a node from an AVL tree and rebalances it.
* @root: Pointer to the root node of the tree
* @value: Value to remove from the tree
*
* Return: Pointer to the new root node after removal and rebalancing
*/
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *tmp;
int balance;

if (root == NULL)
return (NULL);

if (value < root->n)
root->left = avl_remove(root->left, value);
else if (value > root->n)
root->right = avl_remove(root->right, value);
else
{
/* Case 1 or 2: node with one or no child */
if (root->left == NULL)
{
tmp = root->right;
free(root);
return (tmp);
}
else if (root->right == NULL)
{
tmp = root->left;
free(root);
return (tmp);
}

/* Case 3: node with two children -> replace with successor */
tmp = root->right;
while (tmp->left != NULL)
tmp = tmp->left;
root->n = tmp->n;
root->right = avl_remove(root->right, tmp->n);
}

if (root == NULL)
return (NULL);

/* Rebalance the tree */
balance = binary_tree_balance(root);

if (balance > 1 && binary_tree_balance(root->left) >= 0)
return (binary_tree_rotate_right(root));

if (balance > 1 && binary_tree_balance(root->left) < 0)
{
root->left = binary_tree_rotate_left(root->left);
return (binary_tree_rotate_right(root));
}

if (balance < -1 && binary_tree_balance(root->right) <= 0)
return (binary_tree_rotate_left(root));

if (balance < -1 && binary_tree_balance(root->right) > 0)
{
root->right = binary_tree_rotate_right(root->right);
return (binary_tree_rotate_left(root));
}

return (root);
}

