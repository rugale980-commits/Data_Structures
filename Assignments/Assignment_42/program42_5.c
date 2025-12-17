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
//  Function Name : Minimum
//  Description   : Used to return the Minimum Number of all element in linked list
//  Parameters    : first pointer
//  Return value  : int
//  Author        : Rahul Balasaheb Ugale
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////

int Minimum(PNODE Head, int no)
{
    PNODE temp = Head;
    int iMin = Head->Data;

    while (temp != NULL)
    {
        if (iMin > (temp->Data))
        {
            iMin = temp->Data;
        }

        temp = temp->Next;
    }
    return iMin;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Main Entry point application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;

    PNODE First = NULL;

    InsertFirst(&First, 5);
    InsertFirst(&First, 111);
    InsertFirst(&First, 51);
    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    iRet = Minimum(First, 51);

    printf("Minimum Number of element is : %d\n", iRet);

    return 0;
}