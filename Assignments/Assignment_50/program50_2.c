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
//  Function Name   :   DisplayGreaterThanAvg
//  Description     :   Used to Display numbers greater than average
//  Input           :   Head
//  Output          :   Elements greater than average
//  Author          :   Rahul Balasaheb Ugale
//  Date            :   01/01/2026
//
////////////////////////////////////////////////////////////////////////////////

void DisplayGreaterThanAvg(PNODE first)
{
    int iSum = 0;
    int iAvg = 0;
    int iCount = 0;
    PNODE temp = NULL;

    if (first == NULL)
    {
        return;
    }

    temp = first;
    while (temp != NULL)
    {
        iSum += temp->Data;
        temp = temp->Next;
        iCount++;
    }

    iAvg = iSum / iCount;

    temp = first;
    while (temp != NULL)
    {
        if (temp->Data > iAvg)
        {
            printf("| %d |-> ", temp->Data);
        }
        temp = temp->Next;
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

    InsertFirst(&Head, -512);
    InsertFirst(&Head, 42);
    InsertFirst(&Head, -20);
    InsertFirst(&Head, 222);
    InsertFirst(&Head, 111);

    Display(Head);

    DisplayGreaterThanAvg(Head);

    printf("NULL\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : | 111 |->| 222 |->| -20 |->| 42 |->| -512 |->NULL
//
//  Input Linked output : | 111 |-> | 222 |-> | -20 |-> | 42 |-> NULL
//
////////////////////////////////////////////////////////////////////////////////