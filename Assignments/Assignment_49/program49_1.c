////////////////////////////////////////////////////////////////////////////////
//
//  Required header file
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int Data;
    struct node *Next;
};

/*------------------------------------------------------------------------------
        Old Name                    New Name
--------------------------------------------------------------------------------
        struct Node                 NODE
        struct Node *               PNODE
        struct Node **              PPNODE
--------------------------------------------------------------------------------*/

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Used to insert at first position of linked list
//  Parameters    : Address of first pointer and data of node
//  Return value  : void
//  Author        : Rahul Balasaheb Ugale
//  Date          : 31/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Next = NULL;
    newn->Data = no;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->Next = *Head;
        *Head = newn;
    }
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d |->", first->Data);
        first = first->Next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Difference
//  Description     :   Used to Display difference between Max and Min Element
//  Input           :   Head
//  Output          :   Integer
//  Author          :   Rahul Balasaheb Ugale
//  Date            :   31/12/2025
//
////////////////////////////////////////////////////////////////////////////////

int Difference(PNODE first)
{
    int iMax = 0;
    int iMin = 0;

    if (first == NULL)
    {
        return 0;
    }

    iMax = first->Data;
    iMin = first->Data;

    while (first != NULL)
    {
        if (iMax < first->Data)
        {
            iMax = first->Data;
        }

        if (iMin > first->Data)
        {
            iMin = first->Data;
        }

        first = first->Next;
    }

    return iMax - iMin;
}
////////////////////////////////////////////////////////////////////////////////
//
//  Main Entry point application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;
    PNODE Head = NULL;

    InsertFirst(&Head, 512);
    InsertFirst(&Head, 42);
    InsertFirst(&Head, 89);
    InsertFirst(&Head, 222);
    InsertFirst(&Head, 111);

    Display(Head);

    iRet = Difference(Head);
    printf("Difference is %d", iRet);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : | 111 |->| 222 |->| 89 |->| 42 |->| 512 |->NULL
//
//  Input Linked output : Difference is 470
//
////////////////////////////////////////////////////////////////////////////////