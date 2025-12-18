#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

// Call by value functions
void Display(PNODE first)
{
}

int Count(PNODE first)
{
    return 0;
}

// Call by Address functions
void InsertFirst(PPNODE first, int No)
{
}

void InsertLast(PPNODE first, int No)
{
}

void InsertAtPos(PPNODE first, int No,int pos)
{
}

int main()
{
    PNODE head = NULL;

    Display(head);

    Count(head);

    InsertFirst(&head, 11);
    InsertLast(&head,21);
    InsertAtPos(&head,51,5);

    return 0;
}