#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	  bst_t *new_node, *current;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL)
            return (NULL);
        *tree = new_node;
        return (new_node);
    }

    current = *tree;

    while (current != NULL)
    {
        if (value == current->n)
            return (NULL);

        if (value < current->n)
        {
            if (current->left == NULL)
            {
                new_node = binary_tree_node(current, value);
                if (new_node == NULL)
                    return (NULL);
                current->left = new_node;
                return (new_node);
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                new_node = binary_tree_node(current, value);
                if (new_node == NULL)
                    return (NULL);
                current->right = new_node;
                return (new_node);
            }
            else
            {
                current = current->right;
            }
        }
    }

    return (NULL);
}
