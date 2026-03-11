#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
////////////////////////////////////BINARY SEARCH TREE/////////////////////////

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void Insert(PPNODE first , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild =NULL;
    newn->rchild = NULL;


    if(*first == NULL)   //if tree is empty
    {
        *first = newn;
    }
    else                 //if tree contains atleast one node
    {
        temp = *first;

        while(1)
        {
            if(no > temp->data)    //if element is greater
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }

                temp = temp->rchild;
            }
            else if(no < temp->data)   //if element is smaller
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
                
            }
            else if(no == temp->data)   //if element is identical
            {
                printf("Unable to insert : as element is duplicate\n");
                free(newn);
                break;  //while la lagen
            }
            
        }
    }

}

////////////////////    INORDER TRAVERSAL DISPLAY (LDR) //////////////////////////////

void Inorder(PNODE first)
{

    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\n",first->data);
        Inorder(first->rchild);
    }

}

////////////////////    PREORDER TRAVERSAL DISPLAY (DLR) //////////////////////////////

void Preorder(PNODE first)
{

    if(first != NULL)
    {
        printf("%d\n",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }

}

////////////////////    POSTORDER TRAVERSAL DISPLAY (LRD) //////////////////////////////

void Postorder(PNODE first)
{

    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\n",first->data);
    }

}
//////////////////// SEARCH FUNCTION ////////////////////////////////

bool Search(PNODE first , int no)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(no > first->data)
        {
            first->rchild;
        }
        else if(no < first->data)
        {
            first->lchild;
        }
        else if(no == first->data)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}
int main()
{
    PNODE head = NULL;
    bool  bRet = false;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);
    Insert(&head,67);


    printf("Inorder traversal : \n");
    Inorder(head);

    bRet = Search(head,67);

    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present\n");

    }

    return 0;
}