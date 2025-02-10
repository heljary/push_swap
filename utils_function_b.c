#include "push_swap.h"

void free_stack(push_swap *head)
{
    push_swap *tmp;
    
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

void    insert_last(push_swap **head,int value)
{
    push_swap *newnode = malloc(sizeof(push_swap));
    

    if(!newnode)
        return;

    newnode -> next = NULL;
    newnode -> number = value;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    if (!head || !*head) 
        return;
    push_swap *current = *head;
    while (current -> next)
    {
        current = current -> next;
    }
    current -> next = newnode;
}

void    insert_first(push_swap **head,int value)
{
    push_swap *new;

    new = malloc(sizeof(push_swap));
    if(!new)
        return;
    
    new -> number = value;
    new -> next = *head;

    *head = new;

}