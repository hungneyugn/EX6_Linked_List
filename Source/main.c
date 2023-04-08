#include<linkedlist.h>
int main()
{
    linkedList ls;
    linkedList_Init(&ls);
    pushBack(&ls,5);
    pushBack(&ls,7);
    pushBack(&ls,9);
    display(&ls);
    assign(&ls,10,2);
    display(&ls);
    getData(&ls,2);
    erase(&ls,3);
    display(&ls);
    pop_back(&ls);
    display(&ls);
    clear(&ls);
    display(&ls);
    return 0;
}