#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char *name;
    struct Node *next;
};

void printList(struct Node *n)
{
    while (n != NULL){
        printf(" %s ", n->name);
        n = n->next;
    }
}

void push(struct Node** head_ref, char *new_name)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->name = new_name;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, char *new_name)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be null\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->name = new_name;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void append(struct Node** head_ref, char *new_name)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->name = new_name;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

int main (void)
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->name = "Chris";
    head->next  = second;

    second->name = "Melody";
    second->next = third;

    third->name = "Lucas";
    third->next = NULL;

    printList(head);
    printf("\n");

    push(&head, "Lucy");
    printList(head);
    printf("\n");

    insertAfter(head, "Andrew");
    printList(head);
    printf("\n");

    append(&head, "Amanda");
    printList(head);
    printf("\n");

    char lastName[20];
    while (1)
    {
        printf("Please enter a name (q to quit)\n");
        scanf("%s", lastName);
        char* tmpName = strdup(lastName);
        if (lastName[0] == 'q')
            break;
        else
            append(&head, tmpName);
    }
    printList(head);
    printf("\n");

    return 0;

}