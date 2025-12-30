//  singly Circular Linked List
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
#pragma pack(1)
struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
/*----------------------------------------------------------------------------*/
void InsrtFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;

    if ((*first == NULL) && (*last == NULL)) // @
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

    (*last)->next = *first; // @
}
/*----------------------------------------------------------------------------*/
void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;

    if ((*first == NULL) && (*last == NULL)) // @
    {
        *first = newn;
        *last = newn;
    }
    else
    {
    }

    (*last)->next = *first; // @
}
/*----------------------------------------------------------------------------*/
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
}
/*----------------------------------------------------------------------------*/
void DeleteFirst(PPNODE first, PPNODE last)
{
}
/*----------------------------------------------------------------------------*/
void DeleteLast(PPNODE first, PPNODE last)
{
}
/*----------------------------------------------------------------------------*/
void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
}
/*----------------------------------------------------------------------------*/
void Display(PNODE first, PNODE last)
{
}
/*----------------------------------------------------------------------------*/
int Count(PNODE first, PNODE last)
{
}
/*----------------------------------------------------------------------------*/
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    /*------------------------------------------------------------------------*/
    InsrtFirst(&head, &tail, 51);
    InsrtFirst(&head, &tail, 21);
    InsrtFirst(&head, &tail, 11);
    /*------------------------------------------------------------------------*/

    return 0;
}
/*----------------------------------------------------------------------------*/