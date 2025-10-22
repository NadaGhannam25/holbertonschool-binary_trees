#include "binary_trees.h"
#include <stdlib.h>

/**
* find_min - Finds the in-order successor of a node
* @node: pointer to the node
* Return: pointer to successor
*/
avl_t *find_min(avl_t *node)
{
while (node && node->left)
node = node->left;
return (node);
}

/**
* avl_remove - Remove a node from AVL tree and rebalance
* @root: pointer to root node
* @value: value to remove
* Return: pointer to new root
*/
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *tmp;
int balance;

if (!root)
return (NULL);

if (value < root->n)
root->left = avl_remove(root->left, value);
else if (value > root->n)
root->right = avl_remove(root->right, value);
else
{
if (!root->left || !root->right)
{
tmp = root->left ? root->left : root->right;
free(root);
return (tmp);
}
tmp = find_min(root->right);
root->n = tmp->n;
root->right = avl_remove(root->right, tmp->n);
}

/* لا تحاول إعادة التوازن إذا root أصبح NULL */
if (!root)
return (NULL);

balance = binary_tree_balance(root);

/* Left heavy */
if (balance > 1)
{
if (binary_tree_balance(root->left) >= 0)
return (binary_tree_rotate_right(root));
root->left = binary_tree_rotate_left(root->left);
return (binary_tree_rotate_right(root));
}

/* Right heavy */
if (balance < -1)
{
if (binary_tree_balance(root->right) <= 0)
return (binary_tree_rotate_left(root));
root->right = binary_tree_rotate_right(root->right);
return (binary_tree_rotate_left(root));
}

return (root);
}

