#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_t;

void print_list(node_t *head);
void push(node_t *head, int value);
void insert_head(node_t **head, int value);
int pop(node_t **head);
int remove_last(node_t *head);
int remove_by_index(node_t **head, int index);

int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->value = 1;
    head->next = NULL;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->value = 2;
    head->next->next = NULL;

    push(head, 3);
    printf("popped: %d\n\n", pop(&head));
    return 0;
}

void print_list(node_t *head)
{
    node_t *current = head;

    printf("Values in the list:\n");
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void push(node_t *head, int value)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;
}

void insert_head(node_t **head, int value)
{
    node_t *new_head = (node_t *)malloc(sizeof(node_t));
    new_head->value = value;
    new_head->next = *head;
    *head = new_head;
}

int pop(node_t **head)
{
    if (*head == NULL)
    {
        return -1;
    }

    int value = (*head)->value;
    node_t *new_head = (*head)->next;
    free(*head);
    *head = new_head;

    return value;
}

int remove_last(node_t *head)
{
    if (head->next == NULL)
    {
        return pop(&head);
    }

    node_t *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    int value = current->next->value;
    free(current->next);
    current->next = NULL;

    return value;
}

int remove_by_index(node_t **head, int index)
{
    node_t *current = *head;

    if (index == 0)
    {
        return pop(head);
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL)
    {
        return -1;
    }

    node_t *node_to_remove = current->next;
    int value = node_to_remove->value;
    current->next = node_to_remove->next;
    free(node_to_remove);

    return value;
}
