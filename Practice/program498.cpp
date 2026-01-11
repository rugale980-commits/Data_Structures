////////////////////////////////////////////////////////////////////////////////
// Final code of Queue using Generic Approach in Integer
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
/*============================================================================*/
#pragma pack(1)
template <class T>
class Queuenode
{
public:
    int data;
    Queuenode<T> *next;

    Queuenode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};
/*============================================================================*/
template <class T>
class Queue
{
private:
    Queuenode<T> *first;
    Queuenode<T> *last;
    int iCount;

public:
    Queue();

    void enqueue(T);
    T dequeue();

    void Display();
    int Count();
};
/*============================================================================*/
template <class T>
Queue<T>::Queue()
{
    cout << "Queue Get Created Succesfully...\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
/*============================================================================*/
template <class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    Queuenode<T> *temp = NULL;

    newn = new Queuenode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->iCount++;
}
/*============================================================================*/
template <class T>
T Queue<T>::dequeue()
{
    T iValue = 0;

    Queuenode<T> *temp = this->first;

    if ((this->first == NULL) && (this->last == NULL))
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
void Queue<T>::Display()
{
    Queuenode<T> *temp = this->first;

    if ((this->first == NULL) && (this->last == NULL))
    {
        cout << "Queue is Empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "|  " << temp->data << "  | - ";
        temp = temp->next;
    }

    cout << "\n";
}
/*============================================================================*/
template <class T>
int Queue<T>::Count()
{
    return this->iCount;
}
/*============================================================================*/
int main()
{
    Queue<int> *qobj = new Queue<int>();

    qobj->enqueue(11);
    qobj->enqueue(21);
    qobj->enqueue(51);
    qobj->enqueue(101);

    qobj->Display();
    cout << "Number of element in Queue are : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";
    qobj->Display();
    cout << "Number of element in Queue are : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";
    qobj->Display();
    cout << "Number of element in Queue are : " << qobj->Count() << "\n";

    qobj->enqueue(121);
    qobj->Display();
    cout << "Number of element in Queue are : " << qobj->Count() << "\n";

    delete qobj;

    return 0;
}