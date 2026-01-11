////////////////////////////////////////////////////////////////////////////////
// Final code of Queue using Generic Approach in Double
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
        cout << "Queue is Empty\n";
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

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while (1)
    {
        cout << "-----------------------------------------------------------------\n";
        cout << "--------------Please Select the option---------------------------\n";
        cout << " 1  :  Insert new element into the queuq\n";
        cout << " 2  :  Remove new element into the queuq\n";
        cout << " 3  :  Display the elements of the queue\n";
        cout << " 4  :  Count the number of element from the queue\n";
        cout << " 0  :  Exit the Application\n";
        cout << "-----------------------------------------------------------------\n";
        cin >> iChoice;
        cout << "-----------------------------------------------------------------\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> Value;
            qobj->enqueue(Value);
            cout << "Element gets inserted succesfully\n";
            break;

        case 2:
            iRet = qobj->dequeue();
            if (iRet != -1)
            {
                cout << "Element removed from queue is : " << iRet << "\n";
            }
            break;
        case 3:
            cout << "Element of the queue are : \n";
            qobj->Display();
            break;
        case 4:
            iRet = qobj->Count();
            cout << "Number of elements in queue are : " << iRet << "\n";
            break;
        case 0:
            cout << "Thank you for using our Application\n";
            delete qobj;
            return 0;

        default:
            cout << "Plese enter valid option\n";

        } // End Switch

    } // End While

    return 0;

} // End Main