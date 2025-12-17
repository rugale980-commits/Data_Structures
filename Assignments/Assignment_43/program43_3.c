////////////////////////////////////////////////////////////////////////////////
//
//  Required header file
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

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
//  Date          : 17/12/2025
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
//  Function Name : AdditionEven
//  Description   : Used to return the Addition Even Number of all element in linked list
//  Parameters    : first pointer
//  Return value  : int
//  Author        : Rahul Balasaheb Ugale
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////

int AdditionEven(PNODE Head)
{
    PNODE temp = Head;
    int iSum = 0;

    while (temp != NULL)
    {
        if ((temp->Data) % 2 == 0)
        {
            iSum = iSum + temp->Data;
        }

        temp = temp->Next;
    }

    return iSum;
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

    InsertFirst(&First, 41);
    InsertFirst(&First, 32);
    InsertFirst(&First, 20);
    InsertFirst(&First, 11);

    iRet = AdditionEven(First);

    printf("Addition is All Even Number is : %d", iRet);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |11|->|20|->|17|->|41|->|22|->|89|
//
//  output : Addition is All Even Number is : 52
//
////////////////////////////////////////////////////////////////////////////////