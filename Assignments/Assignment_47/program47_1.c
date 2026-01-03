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
//  Function Name : DisplayReverse
//  Description   : Used to search check whether print list in reverse order
//  Parameters    : first pointer and Search Number
//  Return value  : Void
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void DisplayReverse(PPNODE Head)
{
    PNODE Temp = *Head;

    if (Temp == NULL)
    {
        return;
    }

    DisplayReverse(&(Temp->Next));

    printf("|%d|->", Temp->Data);
}
////////////////////////////////////////////////////////////////////////////////
//
//  Main Entry point application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 9);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    DisplayReverse(&First);

    printf("NULL\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : |10|->|20|->|-9|->|-40|->|50|->NULL
//
//  Input Linked output : |50|->|40|->|9|->|20|->|10|->NULL
//
////////////////////////////////////////////////////////////////////////////////