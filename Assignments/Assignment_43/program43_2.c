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
//  Function Name : DisplayPrime
//  Description   : Used to return the Display Prime Number of all element in linked list
//  Parameters    : first pointer
//  Return value  : int
//  Author        : Rahul Balasaheb Ugale
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void DisplayPrime(PNODE Head)
{
    PNODE temp = Head;
    int iCnt = 0;
    int iPrime = 0;

    while (temp != NULL)
    {
        iPrime = 0;

        for (iCnt = 1; iCnt <= (temp->Data) / 2; iCnt++)
        {
            if ((temp->Data % iCnt) == 0)
            {
                iPrime++;
            }
        }

        if (iPrime == 1)
        {
            printf("%d is Prime Number\n", temp->Data);
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
    PNODE First = NULL;

    InsertFirst(&First, 89);
    InsertFirst(&First, 22);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 20);
    InsertFirst(&First, 11);

    DisplayPrime(First);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |11|->|20|->|17|->|41|->|22|->|89|
//
//  output : 11 17  41  89
//
////////////////////////////////////////////////////////////////////////////////