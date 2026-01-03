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
//  Function Name : CountDigits
//  Description   : Used to search check whether Count Digits of each node
//  Parameters    : first pointer
//  Return value  : Void
//  Author        : Rahul Balasaheb Ugale
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////

void CountDigits(PPNODE Head)
{
    PNODE Temp = *Head;
    int Count = 0, No = 0;

    while (Temp != NULL)
    {
        No = Temp->Data;
        Count = 0;

        if (No == 0)
        {
            Count = 1;
        }

        while (No != 0)
        {
            Count++;
            No = No / 10;
        }

        printf("Digits in %d : %d\n", Temp->Data, Count);

        Temp = Temp->Next;
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

    InsertFirst(&First, 512);
    InsertFirst(&First, 42);
    InsertFirst(&First, 89);
    InsertFirst(&First, 222);
    InsertFirst(&First, 111);

    CountDigits(&First);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Testcases succesfully handle by the application
//
//  Input Linked List   : |10|->|20|->|-9|->|-40|->|50|->NULL
//
//  Input Linked output : Digits in 111 : 3
//                        Digits in 222 : 3
//                        Digits in 89  : 2
//                        Digits in 42  : 2
//                        Digits in 512 : 3
//
////////////////////////////////////////////////////////////////////////////////