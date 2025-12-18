#include <stdio.h>

#pragma pack(1)
struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;

int main()
{
    // struct node obj;
    NODE obj;

    obj.Data = 11;
    obj.next = NULL;
    
    return 0;
}