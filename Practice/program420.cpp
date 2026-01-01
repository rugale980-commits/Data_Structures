//  Singly Linked List
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
};
/*----------------------------------------------------------------------------*/
int main()
{
    SinglyLL obj;

    return 0;
}
/*----------------------------------------------------------------------------*/