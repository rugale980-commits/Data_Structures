////////////////////////////////////////////////////////////////////////////////
// Genralised Data Structure Liabrary
////////////////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------
    type        Name of class for node              Name of class for Functionlity
-----------------------------------------------------------------------------------
Singly Linear      SinglyLLLnode                       SinglyLLL        Done
Singly Cirular     SinglyLLLnode                       SinglyCLL        Done
Doubly Linear      DoublyLLLnode                       DoublyLLL        Done
Doubly Cirular     DoublyCLLnode                       DoublyCLL
Stack              Stacknode                           Stack            Done
Queue              Queuenode                           Queue            Done
----------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//           ** Singly Linear LinkedList using Generic approach **
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
public:
    T Data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->Data = no;
        this->next = NULL;
    }
};
/*----------------------------------------------------------------------------*/
template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first;
    int iCount;

public:
    SinglyLLL();

    void InsertFirst(T);
    void InsertLast(T);

    void DeleteFirst();
    void DeleteLast();

    void Display();
    int Count();

    void InsertAtPos(T, int);
    void DeleteAtPos(int);
};
/*----------------------------------------------------------------------------*/
template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLL gets Created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at first position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if (this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at first position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Display node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for (iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << " | " << temp->Data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Count node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//         ** Singly  Circular LinkedList using Generic approach **
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyCLL
//  Description  : Generic (template-based) Singly Circular Linked List.
//                 The last node points back to the first node.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Rahul Balasaheb Ugale
//  Date         : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCLL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void Display();
    int Count();

    void DeleteAtPos(int pos);
    void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name : SinglyCLL
//  Description      : Initializes an empty Singly Circular Linked List.
//  Author           : Rahul Balasaheb Ugale
//  Date             : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout << "Object of SinglyLL gets Created.\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at first position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at first position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Display node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if (first == NULL && last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> *temp = first;

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    } while (temp != last->next);

    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Count node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;
    int i = 0;

    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = first;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int i = 0;

    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//           ** Doubly Linear LinkedList using Generic Approach **
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode *next;
    DoublyLLLnode *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};
/*----------------------------------------------------------------------------*/
template <class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};
/*----------------------------------------------------------------------------*/
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at first position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to insert node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at First position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {

        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at Last position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Delete node at position
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    if ((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Display node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout << "\nNULL<=>";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input         :   Data of node
//  OutPut        :   Nothing
//  Description   :   Used to Count node
//  Author        :   Rahul Balasaheb Ugale
//  Date          :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//                  << Stack using Generic approach >>
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
public:
    T data;
    Stacknode<T> *next;

    Stacknode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};
/*============================================================================*/
template <class T>
class Stack
{
private:
    Stacknode<T> *first;
    int iCount;

public:
    Stack();

    void push(T);
    T pop();
    T peep();

    void Display();
    int Count();
};
/*============================================================================*/
template <class T>
Stack<T>::Stack()
{
    cout << "Stack Get Created Succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}
/*============================================================================*/
template <class T>
void Stack<T>::push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}
/*============================================================================*/
template <class T>
T Stack<T>::pop()
{
    T iValue = 0;

    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    iValue = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return iValue;
}
/*============================================================================*/
template <class T>
T Stack<T>::peep()
{
    T Value = 0;

    if (this->first == NULL)
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}
/*============================================================================*/
template <class T>
void Stack<T>::Display()
{
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack is Empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}
/*============================================================================*/
template <class T>
int Stack<T>::Count()
{
    return this->iCount;
}
/*============================================================================*/

////////////////////////////// End of Libray ///////////////////////////////////

int main()
{
    /*------------------------------------------------------------------------*/
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;
    /*------------------------------------------------------------------------*/
    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";
    /*------------------------------------------------------------------------*/
    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";
    /*------------------------------------------------------------------------*/
    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";
    /*------------------------------------------------------------------------*/
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";
    /*------------------------------------------------------------------------*/
    obj->InsertAtPos(105, 4);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";
    /*------------------------------------------------------------------------*/
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout << "Number of Nodes are : " << iRet << "\n";

    delete obj;

    /*========================================================================*/
    DoublyLLL<char> *dobj = new DoublyLLL<char>();
    /*========================================================================*/
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/
    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/
    dobj->DeleteFirst();

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/
    dobj->DeleteLast();

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/
    dobj->InsertAtPos('$', 4);

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/
    dobj->DeleteAtPos(4);

    dobj->Display();

    cout << "Character of element are : " << dobj->Count() << "\n";
    /*========================================================================*/

    delete obj;

    ////////////////////////////////////////////////////////////////////////////
    Stack<char> *sobj = new Stack<char>();
    ////////////////////////////////////////////////////////////////////////////

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();
    cout << "Number of element in Stack are : " << sobj->Count() << "\n";

    cout << "Return value of peep is : " << sobj->peep() << "\n";

    sobj->Display();
    cout << "Number of element in Stack are : " << sobj->Count() << "\n";

    cout << "Poped element is : " << sobj->pop() << "\n";

    sobj->Display();
    cout << "Number of element in Stack are : " << sobj->Count() << "\n";

    cout << "Poped element is : " << sobj->pop() << "\n";

    sobj->Display();
    cout << "Number of element in Stack are : " << sobj->Count() << "\n";

    sobj->push('E');

    sobj->Display();
    cout << "Number of element in Stack are : " << sobj->Count() << "\n";

    delete sobj;
    ///////////////////////////////////////////////////////////////////////////

    /*========================================================================*/
    return 0;
}