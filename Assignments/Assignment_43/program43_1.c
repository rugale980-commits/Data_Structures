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
//  Function Name : DisplayPerfect
//  Description   : Used to return the Display Perfect Number of all element in linked list
//  Parameters    : first pointer
//  Return value  : int
//  Author        : Rahul Balasaheb Ugale
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void DisplayPerfect(PNODE Head)
{
    PNODE temp = Head;
    int iCnt = 0;
    int iSum = 0;

    while (temp != NULL)
    {
        iSum = 0;

        for (iCnt = 1; iCnt <= (temp->Data) / 2; iCnt++)
        {
            if ((temp->Data % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if (iSum == temp->Data)
        {
            printf("%d is Perfect Number\n", temp->Data);
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
    InsertFirst(&First, 6);
    InsertFirst(&First, 41);
    InsertFirst(&First, 17);
    InsertFirst(&First, 28);
    InsertFirst(&First, 11);

    DisplayPerfect(First);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |11|->|28|->|17|->|41|->|6|->|89|
//
//  output : 6      28
//
////////////////////////////////////////////////////////////////////////////////