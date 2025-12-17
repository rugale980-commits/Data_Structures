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
//  Function Name : SecMaximum
//  Description   : Used to return the Second Maximum Number of all element in linked list
//  Parameters    : first pointer
//  Return value  : int
//  Author        : Rahul Balasaheb Ugale
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////

int SecMaximum(PNODE Head)
{
    PNODE temp = Head;
    int iMax = 0;
    int iSecMax = 0;

    while (temp != NULL)
    {
        if ((temp->Data) > iMax)
        {
            iSecMax = iMax;
            iMax = temp->Data;
        }
        else if ((temp->Data > iSecMax) && (temp->Data < iMax))
        {
            iSecMax = temp->Data;
        }

        temp = temp->Next;
    }

    return iSecMax;
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

    InsertFirst(&First, 240);
    InsertFirst(&First, 320);
    InsertFirst(&First, 230);
    InsertFirst(&First, 110);

    iRet = SecMaximum(First);

    printf("second Maximum Number is : %d", iRet);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |110|->|230|->|320|->|240|
//
//  output : second Maximum Number is : 240
//
////////////////////////////////////////////////////////////////////////////////