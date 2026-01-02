////////////////////////////////////////////////////////////////////////////////
//
//  Required header file
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

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
//  Date          : 30/12/2025
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

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayOdd
//  Description   : Used to search check whether Display Odd Numbers
//  Parameters    : first pointer and Search Number
//  Return value  : Integer
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void DisplayOdd(PNODE Head)
{
    while (Head != NULL)
    {
        if (Head->Data % 2 != 0)
        {
            printf("Odd number is : %d\n", Head->Data);
        }
        Head = Head->Next;
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

    InsertFirst(&First, 5);
    InsertFirst(&First, 4);
    InsertFirst(&First, 3);
    InsertFirst(&First, 2);
    InsertFirst(&First, 1);

    DisplayOdd(First);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |1|->|2|->|3|->|4|->|5|
//
//  output : Odd number is : 1
//           Odd number is : 3
//           Odd number is : 5
//
////////////////////////////////////////////////////////////////////////////////