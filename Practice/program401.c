// Doublly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Data;
    struct node *next;
    struct node *prev; // $
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
/*-----------------------------------------------------------------------------*/
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL; // $

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn; // $
        *first = newn;
    }
}
/*-----------------------------------------------------------------------------*/
void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL; // $

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while (temp->next != NULL) // Type 2
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp; // $
    }
}
/*-----------------------------------------------------------------------------*/
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if (*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
        (*first)->prev = NULL; // $
    }
}
/*-----------------------------------------------------------------------------*/
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if (*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while (temp->next->next != NULL) // type 3
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}
/*-----------------------------------------------------------------------------*/
void Display(PNODE first)
{
    printf("\nNULL <=> ");
    while (first != NULL)
    {
        printf("| %d | <=> ", first->Data);
        first = first->next;
    }
    printf("NULL\n");
}
/*-----------------------------------------------------------------------------*/
int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}
/*-----------------------------------------------------------------------------*/
void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int icnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    // Filter
    if ((pos < 1) || (pos > iSize + 1))
    {
        printf("Ivalid Position\n");
        return;
    }

    if (pos == 1)
    {
        InsertFirst(first, no);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for (icnt = 1; icnt < pos - 1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
    }
}
/*-----------------------------------------------------------------------------*/
void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int icnt = 0;

    PNODE temp = NULL;

    iSize = Count(*first);

    // Filter
    if ((pos < 1) || (pos > iSize))
    {
        printf("Ivalid Position\n");
        return;
    }

    if (pos == 1)
    {
        DeleteFirst(first);
    }
    else if (pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for (icnt = 1; icnt < pos - 1; icnt++)
        {
            temp = temp->next;
        }
    }
}
/*-----------------------------------------------------------------------------*/
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    /*------------------------------------------------------------------------**/
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are InsertFirst : %d\n", iRet);
    /*------------------------------------------------------------------------**/
    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are InsertLast : %d\n", iRet);
    /*------------------------------------------------------------------------**/
    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are DeleteFirst : %d\n", iRet);
    /*------------------------------------------------------------------------**/
    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are DeleteLast : %d\n", iRet);
    /*------------------------------------------------------------------------**/
    InsertAtPos(&head, 10, 4);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are Insert At Position : %d\n", iRet);
    /*------------------------------------------------------------------------**/
    DeleteAtPos(&head, 4);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are Delete At Position : %d\n", iRet);
    /*------------------------------------------------------------------------**/

    return 0;
}