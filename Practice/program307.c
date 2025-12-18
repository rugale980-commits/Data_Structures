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
    struct node *head = NULL;
    NODE obj;

    head = &obj;

    head->Data = 11;
    head->next = NULL;

    return 0;
}