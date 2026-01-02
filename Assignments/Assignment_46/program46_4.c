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
//  Function Name : ReplaceNegative
//  Description   : Used to search check whether Replace Negative Number
//  Parameters    : first pointer and Search Number
//  Return value  : Integer
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void ReplaceNegative(PPNODE Head)
{
    PNODE Temp = *Head;

    while (Temp != NULL)
    {
        if (Temp->Data < 0)
        {
            Temp->Data = -(Temp->Data);
        }
        Temp = Temp->Next;
    }
}
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Display to linked list
//  Parameters    : first pointer
//  Return value  : Void
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////
void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d|->", Head->Data);
        Head = Head->Next;
    }
    printf("NULL\n");
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
    InsertFirst(&First, -40);
    InsertFirst(&First, -9);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    ReplaceNegative(&First);

    Display(First);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List : |10|->|20|->|-9|->|-40|->|50|->NULL
//
//  output : |10|->|20|->|9|->|40|->|50|->NULL
//
////////////////////////////////////////////////////////////////////////////////