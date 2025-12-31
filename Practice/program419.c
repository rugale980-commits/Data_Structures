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
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}
/*----------------------------------------------------------------------------*/
void DeleteFirst(PPNODE first, PPNODE last)
{
    if ((*first == NULL) && (*last == NULL)) // LL is Empty
    {
        return;
    }
    else if (*first == *last) // LL Contains One Node
    {
        free(first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}
/*----------------------------------------------------------------------------*/
void DeleteLast(PPNODE first, PPNODE last)
{
    if ((*first == NULL) && (*last == NULL)) // LL is Empty
    {
        return;
    }
    else if (*first == *last) // LL Contains One Node
    {
        free(first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;
        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}
/*----------------------------------------------------------------------------*/
void Display(PNODE first, PNODE last)
{
    // Important (IMP)
    if ((first == NULL) && (last == NULL)) // LL is Empty
    {
        printf("Linked List is Empty\n");
        return;
    }

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

    if ((first == NULL) && (last == NULL)) // LL is Empty
    {
        return 0;
    }

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
    int iCount = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first, *last);

    if ((pos < 1) || (pos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for (iCnt = 0; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}
/*----------------------------------------------------------------------------*/
void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCount = 0;
    int iCnt = 0;

    PNODE temp = NULL;

    iCount = Count(*first, *last);

    if ((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if (pos == iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for (iCnt = 0; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}
/*----------------------------------------------------------------------------*/
int main()
{
    int iRet = 0;

    PNODE head = NULL;
    PNODE tail = NULL;
    /*-------------------------------------------------------------------------*/

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are Insert First : %d\n", iRet);
    /*-------------------------------------------------------------------------*/
    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are Insert Last : %d\n", iRet);
    /*-------------------------------------------------------------------------*/
    DeleteFirst(&head, &tail);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are Delete First : %d\n", iRet);
    /*-------------------------------------------------------------------------*/
    DeleteLast(&head, &tail);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are Delete Last : %d\n", iRet);
    /*-------------------------------------------------------------------------*/
    InsertAtPos(&head, &tail, 105, 3);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are InsertAtPos : %d\n", iRet);
    /*-------------------------------------------------------------------------*/
    DeleteAtPos(&head, &tail, 3);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are DeleteAtPos : %d\n", iRet);
    /*-------------------------------------------------------------------------*/

    return 0;
}
/*----------------------------------------------------------------------------*/