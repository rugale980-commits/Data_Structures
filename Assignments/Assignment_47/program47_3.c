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
//  Function Name   :   SumDigits
//  Description     :   Used to find sum of digits in the elements
//  Input           :   Head
//  Output          :   Sum of each element
//  Author          :   Rahul Balasaheb Ugale
//  Date            :   31/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void SumDigits(PNODE first)
{
    while (first != NULL)
    {
        int iSum = 0;
        int iDigit = 0;

        while (first->Data != 0)
        {
            iDigit = first->Data % 10;
            iSum = iSum + iDigit;
            first->Data /= 10;
        }
        printf("| %d |->", iSum);
        first = first->Next;
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//  Main Entry point application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 512);
    InsertFirst(&First, 42);
    InsertFirst(&First, 89);
    InsertFirst(&First, 222);
    InsertFirst(&First, 111);

    Display(First);

    SumDigits(First);

    printf("NULL\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : | 111 |->| 222 |->| 89 |->| 42 |->| 512 |->NULL
//
//  Input Linked output : | 3 |->| 6 |->| 17 |->| 6 |->| 8 |->NULL
//
////////////////////////////////////////////////////////////////////////////////