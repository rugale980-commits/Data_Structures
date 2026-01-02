// Singly Linear Linked List 
/*---------------------------------------------------------------------------- */
class node
{
    public int Data;
    public node next;
}
/*---------------------------------------------------------------------------- */
class SinglyLL
{
    public node first;
    public int iCount;
    /*------------------------------------------------------------------------*/
    public SinglyLL()
    {
        System.out.println("Object of SinglyLL get Created.");
        this.first = null;
        this.iCount = 0;
    }
    /*------------------------------------------------------------------------*/
    public void InsertFirst(int no)
    {}
    /*------------------------------------------------------------------------*/
    public void InsertLast(int no)
    {}
    /*------------------------------------------------------------------------*/
    public void InsertAtPos(int no,int pos)
    {}
    /*------------------------------------------------------------------------*/
    public void DeleteFirst(int no)
    {}
    /*------------------------------------------------------------------------*/
    public void DeleteLast(int no)
    {}
    /*------------------------------------------------------------------------*/
    public void DeleteAtPos(int no)
    {}
    /*------------------------------------------------------------------------*/
    public void Display()
    {}
    /*------------------------------------------------------------------------*/
    public int Count()
    {
        return this.iCount;
    }

}
/*---------------------------------------------------------------------------- */
class program439
{
    public static void main(String A[])
    {
        SinglyLL obj = null;
        int iRet = 0;

        obj = new SinglyLL();
        /*--------------------------------------------------------------------*/
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of Nodes are : " +iRet);
        /*--------------------------------------------------------------------*/
    }
}
/*---------------------------------------------------------------------------- */
