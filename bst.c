#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node_t;

void insert(node_t *head, int value);
void dfs_inorder(node_t *node);

int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->value = 6;
    head->left = NULL;
    head->right = NULL;

    insert(head, 3);
    insert(head, 7);

    dfs_inorder(head);

    return 0;
}

void dfs_inorder(node_t *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->left != NULL)
    {
        dfs_inorder(node->left);
    }

    printf("%d\n", node->value);

    if (node->left != NULL)
    {
        dfs_inorder(node->right);
    }
}

void insert(node_t *node, int value)
{
    if (node->value == 0)
    {
        node->value = value;
        return;
    }

    if (value <= node->value)
    {
        if (node->left != NULL)
        {
            insert(node->left, value);
            return;
        }
        node->left = (node_t *)malloc(sizeof(node_t));
        node->left->value = value;
        node->left->left = NULL;
        node->left->right = NULL;
        return;
    }
    else
    {

        if (node->right != NULL)
        {
            insert(node->right, value);
            return;
        }
        node->right = (node_t *)malloc(sizeof(node_t));
        node->right->value = value;
        node->right->left = NULL;
        node->right->right = NULL;
        return;
    }
}