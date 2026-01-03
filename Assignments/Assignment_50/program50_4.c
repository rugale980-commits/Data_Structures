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
//  Date          : 01/01/2026
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
//  Function Name   :   DisplayAlternate
//  Description     :   Used to Display alternate nodes from list
//  Input           :   Head
//  Output          :   Nodes
//  Author          :   Rahul Balasaheb Ugale
//  Date            :   01/01/2026
//
////////////////////////////////////////////////////////////////////////////////

void DisplayAlternate(PNODE first)
{
    int pos = 1;

    while (first != NULL)
    {
        if (pos % 2 != 0)
        {
            printf("| %d |->", first->Data);
        }
        pos++;

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
    PNODE Head = NULL;

    InsertFirst(&Head, 512);
    InsertFirst(&Head, 42);
    InsertFirst(&Head, 20);
    InsertFirst(&Head, 222);
    InsertFirst(&Head, 111);

    Display(Head);

    DisplayAlternate(Head);

    printf("NULL\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : | 111 |->| 222 |->| -20 |->| 42 |->| -512 |->NULL
//
//  Input Linked output : | 111 |->| 20 |->| 512 |->NULL
//
////////////////////////////////////////////////////////////////////////////////