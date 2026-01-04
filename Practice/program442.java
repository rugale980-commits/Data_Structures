// Singly Linear Linked List 
/*---------------------------------------------------------------------------- */
class node
{
    public int Data;
    public node next;

    // Important
    public node(int no)
    {
        this.Data = no;
        this.next = null;
    }
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
    {
        node newn = null;

        // Chaged Code (varti Constructur lihila tithe delration varti kele)
        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }
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
    {
        node temp = null;
        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+ temp.Data +" | -> ");
            temp = temp.next;
        }

        System.out.println("null");
    }
    /*------------------------------------------------------------------------*/
    public int Count()
    {
        return this.iCount;
    }

}
/*---------------------------------------------------------------------------- */
class program441
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
        // IMP for Memory Deallocation
        obj = null;  
        System.gc();
    }
}
/*---------------------------------------------------------------------------- */
