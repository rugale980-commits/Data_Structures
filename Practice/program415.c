//  Doubly Circular Linked List
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
#pragma pack(1)
struct node
{
    int Data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
/*----------------------------------------------------------------------------*/
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*first == NULL) && (*last == NULL)) // LL is Empty
    {
        *first = newn;
        *last = newn;
    }
    else // LL Contains One or More
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}
/*----------------------------------------------------------------------------*/
void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*first == NULL) && (*last == NULL)) // LL is Empty
    {
        *first = newn;
        *last = newn;
    }
    else // LL Contains One or More
    {
    }

    (*last)->next = *first;
    (*first)->prev = *last;
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
void Display(PNODE first, PNODE last)
{
    printf(" <=> ");
    do
    {
        printf(" | %d | <=> ", first->Data);
        first = first->next;
    } while (first != last->next);

    printf("\n");
}
/*----------------------------------------------------------------------------*/
int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);

    return iCount;
}
/*----------------------------------------------------------------------------*/
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
}
/*----------------------------------------------------------------------------*/
void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
}
/*----------------------------------------------------------------------------*/

// Segmentation Fault due to Display and Count

int main()
{
    int iRet = 0;

    PNODE head = NULL;
    PNODE tail = NULL;
    /*-------------------------------------------------------------------------*/
    /*
        InsertFirst(&head, &tail, 51);
        InsertFirst(&head, &tail, 21);
        InsertFirst(&head, &tail, 11);
    */
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n", iRet);
    /*-------------------------------------------------------------------------*/

    return 0;
}
/*----------------------------------------------------------------------------*/