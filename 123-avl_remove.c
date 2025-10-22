#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the in-order successor
 */
avl_t *find_min(avl_t *node)
{
    while (node && node->left)
        node = node->left;
    return (node);
}

/**
 * avl_remove - Remove a node from AVL tree and rebalance
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
        // Node found
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

    // Update balance
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

