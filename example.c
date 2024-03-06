#include <stdio.h>
#include "linkedList.h"

int main(){
    //LinkedList: type is the type of a linked list
    LinkedList* l = CreateLinkedList(3, 1, 2, 3);
    printf("created linked list\n");
    PrintAllElements(l);
    //CreateLinkedList: is a variadic function 
    //CreateLinkedList: linkedlist(number of passed elements, ...elements)

    //AppendLinkedList: adds element to the end of linked list
    AppendLinkedList(l, 5);
    printf("appened element 5 to the list\n");
    PrintAllElements(l);
    //AppfrontLinkedList: adds element to the front of linked list
    AppfrontLinkedList(l, 6);
    printf("'appfronted' element 6 to the list\n");
    PrintAllElements(l);
    
    //PrintAllElements prints all the elements on to the stdout
    //PrintAllElements(l);

    //DeleteNode: deletes element from the list(using index)
    //returns deleted value(int)
    int v = DeleteNode(l, 3);
    printf("deleted element 3\n");
    PrintAllElements(l);

    //ExtendLinkedList: extends the linked 
    //its a variadic function: void(linked list, number of passed elements, ...elements)
    ExtendLinkedList(l, 2, 30, 20);
    printf("Added elements '30, 20' to list\n");
    PrintAllElements(l);

    //SwapElements: swaps the position of two elements 
    //void(linked_list, index1, index2)
    SwapElements(l, 2, 3);
    printf("swapped element 1 with 3(index)\n");
    PrintAllElements(l);

    //Frees all the elements in the linked list
    FreeLinkedList(l);
    //it is the user's responsibility to free the memory
   return 0;
}

