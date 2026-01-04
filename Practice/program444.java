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

        // Chaged Code
        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }
    /*------------------------------------------------------------------------*/
    public void InsertLast(int no)
    {
        node newn = null;
            node temp = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        this.iCount++;
    }
    /*------------------------------------------------------------------------*/
    public void InsertAtPos(int no,int pos)
    {}
    /*------------------------------------------------------------------------*/
    public void DeleteFirst(int no)
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == 1)
        {
            this.first = null;
        }
        else
        {
            this.first = first.next;
        }

        System.gc();
        this.iCount--;
    }
    /*------------------------------------------------------------------------*/
    public void DeleteLast(int no)
    {

    }
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
class program444
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
        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

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
