#include <stdio.h>

#pragma pack(1)
struct node
{
    int Data;
    struct node *next;
};

int main()
{
    struct node obj;

    printf("%ld\n", sizeof(obj));

    return 0;
}