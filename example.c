#include <stdio.h>
#include "linkedList.h"

int main(){
    //LinkedList: type is the type of a linked list
    LinkedList* l = CreateLinkedList(3, 5, 3, 8);
    printf("created linked list\n");
    PrintLinkedList(l);
    //CreateLinkedList: is a variadic function 
    //CreateLinkedList: linkedlist(number of passed elements, ...elements)

    //AppendLinkedList: adds element to the end of linked list
    AppendLinkedList(l, 5);
    printf("appened element 5 to the list\n");
    PrintLinkedList(l);
    //AppfrontLinkedList: adds element to the front of linked list
    AppfrontLinkedList(l, 6);
    printf("'appfronted' element 6 to the list\n");
    PrintLinkedList(l);
    
    //PrintAllElements prints all the elements on to the stdout
    printf("PrintLinkedList looks like this: ");
    PrintLinkedList(l);
    //Use PrintAllElements for more detailed look
    printf("PrintAllElements looks like this: \n");
    PrintAllElements(l);

    //DeleteNode: deletes element from the list(using index)
    //returns deleted value(int)
    int v = DeleteNode(l, 3);
    printf("deleted element of index 3\n");
    PrintLinkedList(l);

    //ExtendLinkedList: extends the linked 
    //its a variadic function: void(linked list, number of passed elements, ...elements)
    ExtendLinkedList(l, 2, 11, 0);
    printf("Added elements '11, 0' to list\n");
    PrintLinkedList(l);

    //SwapElements: swaps the position of two elements 
    //void(linked_list, index1, index2)
    SwapElements(l, 1, 3);
    printf("swapped element 1 with 3(index)\n");
    PrintLinkedList(l);

    //IndexOf: returns index of the element from node ptr
    //IndexOfValue: returns index of the first element of the given value
    Node* tempN = GetElement(l, 2);
    int tempI = IndexOf(l, tempN);
    printf("Index of the given node is: %d\n", tempI);

    //Sorting
    //BubbleSort: takes in a list and sorts it in ascending order O(N^2)
    LinkedList* tempL = l;
    BubbleSort(l);
    printf("bubbleSort\n: ");
    PrintLinkedList(l);
    //QuickSort: takes in a list and sorts it in ascendint order 
    //worstcase: O(N^2); bestcase: O(NlogN)
    l = tempL;
    QuickSort(l);
    printf("QuickSort\n: ");
    PrintLinkedList(l);

    //Frees all the elements in the linked list
    FreeLinkedList(l);
    //it is the user's responsibility to free the memory
   return 0;
}

