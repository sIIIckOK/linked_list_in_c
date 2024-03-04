#include <stdio.h>
#include "linkedList.h"

int main(){
    //LinkedList: type is the type of a linked list
    LinkedList* l = CreateLinkedList(20);
    //AppendLinkedList: adds element to the end of linked list
    AppendLinkedList(l, 120);
    //AppfrontLinkedList: adds element to the front of linked list
    AppfrontLinkedList(l, 300);
                               
    //length: lists have length to easy loops
    for (int i = 0; i < l->length; i++){
        //Node: type is elements within linked lists
        Node* e = GetElement(l, i);//GetElement: gets element from a linked list
        printf("index: %d, value: %d\n", i, e->value);
    }
    return 0;
}

