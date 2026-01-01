//  Singly Linear Linked List
/*----------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
/*----------------------------------------------------------------------------*/
struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
/*----------------------------------------------------------------------------*/
class SinglyLL
{
public:
    PNODE first;
    int iCount;

    SinglyLL()
    {
        cout << "Object of SinglyLL gets Created.\n";
        first = NULL;
        iCount = 0;
    }
    /*-------------------------------------------------------------------------*/
    void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->Data = no;
        newn->next = NULL;

        if (first == NULL) // @
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }

        iCount++;
    }
    /*-------------------------------------------------------------------------*/
    void InsertLast(int no)
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = no;
        newn->next = NULL;

        if (first == NULL) // LL is Empty
        {
            first = newn;
        }
        else // LL Contains One or More
        {
            (first)->next = newn;
            first = newn;
        }

        (first)->next = first;
    }
    /*-------------------------------------------------------------------------*/
    void InsertAtPos(int no, int pos)
    {
    }
    /*-------------------------------------------------------------------------*/
    void DeleteFirst()
    {
    }
    /*-------------------------------------------------------------------------*/
    void DeleteLast()
    {
    }
    /*-------------------------------------------------------------------------*/
    void DeleteAtPos(int pos)
    {
    }
    /*-------------------------------------------------------------------------*/
    void Display()
    {
        // Important (IMP)
        if (first == NULL) // LL is Empty
        {
            cout << "Linked List is Empty\n";
            return;
        }

        cout << " <=> ";

        do
        {
            printf(" | %d | <=> ", first->Data);
            first = first->next;
        } while (first != first->next);

        cout << "\n";
    }
    /*-------------------------------------------------------------------------*/
    int Count()
    {
        return iCount;
    }
    /*-------------------------------------------------------------------------*/
};
/*-----------------------------------------------------------------------------*/
int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout << "Number of Nodes are : " << iRet << "\n";

    return 0;
}
/*----------------------------------------------------------------------------*/