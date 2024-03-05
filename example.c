#include <stdio.h>
#include "linkedList.h"

int main(){
    //LinkedList: type is the type of a linked list
    LinkedList* l = CreateLinkedList(3, 1, 2, 3);
    //CreateLinkedList: is a variadic function
    //CreateLinkedList(number of elements, ...elements)

    //AppendLinkedList: adds element to the end of linked list
    AppendLinkedList(l, 5);
    //AppfrontLinkedList: adds element to the front of linked list
    AppfrontLinkedList(l, 6);
    
    //PrintAllElements prints all the elements on to the stdout
    PrintAllElements(l);

    //DeleteNode: deletes element from the list(using index)
    //returns deleted value(int)
    int v = DeleteNode(l, 3);

    PrintAllElements(l);
    return 0;
}

