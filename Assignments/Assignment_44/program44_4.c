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
//  Function Name : Frequency
//  Description   : Used to search check whether Frequency of number
//  Parameters    : first pointer and Search Number
//  Return value  : Integer
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////

int Frequency(PNODE Head, int No)
{
    int Count = 0;

    while (Head != NULL)
    {
        if (Head->Data == No)
        {
            Count++;
        }
        Head = Head->Next;
    }
    return Count;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Main Entry point application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 5);
    InsertFirst(&First, 2);
    InsertFirst(&First, 3);
    InsertFirst(&First, 2);
    InsertFirst(&First, 1);

    iRet = Frequency(First, 2);

    printf("Frequency of 2 is : %d\n", iRet);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |1|->|2|->|3|->|2|->|5|
//
//  output : Frequency of 2 is : 2
//
////////////////////////////////////////////////////////////////////////////////