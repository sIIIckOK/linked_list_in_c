#include <stdio.h>
#include "linkedList.h"

int main(){
    //LinkedList: type is the type of a linked list
    LinkedList* l = LL_CreateLinkedList(3, 5, 3, 8);
    printf("created linked list\n");
    LL_PrintLinkedList(l);
    //CreateLinkedList: is a variadic function 
    //CreateLinkedList: linkedlist(number of passed elements, ...elements)

    //AppendLinkedList: adds element to the end of linked list
    LL_AppendLinkedList(l, 5);
    printf("appened element 5 to the list\n");
    LL_PrintLinkedList(l);
    //AppfrontLinkedList: adds element to the front of linked list
    LL_AppfrontLinkedList(l, 6);
    printf("'appfronted' element 6 to the list\n");
    LL_PrintLinkedList(l);
    
    //PrintAllElements prints all the elements on to the stdout
    printf("PrintLinkedList looks like this: ");
    LL_PrintLinkedList(l);
    //Use PrintAllElements for more detailed look
    printf("PrintAllElements looks like this: \n");
    LL_PrintAllElements(l);

    //DeleteNode: deletes element from the list(using index)
    //returns deleted value(int)
    int v = LL_DeleteNode(l, 3);
    printf("deleted element of index 3\n");
    LL_PrintLinkedList(l);

    //ExtendLinkedList: extends the linked 
    //its a variadic function: void(linked list, number of passed elements, ...elements)
    LL_ExtendLinkedList(l, 2, 11, 0);
    printf("Added elements '11, 0' to list\n");
    LL_PrintLinkedList(l);

    //SwapElements: swaps the position of two elements 
    //void(linked_list, index1, index2)
    LL_SwapElements(l, 1, 3);
    printf("swapped element 1 with 3(index)\n");
    LL_PrintLinkedList(l);

    //IndexOf: returns index of the element from node ptr
    //IndexOfValue: returns index of the first element of the given value
    Node* tempN = LL_GetElement(l, 2);
    int tempI = LL_IndexOf(l, tempN);
    printf("Index of the given node is: %d\n", tempI);

    //Sorting
    //BubbleSort: takes in a list and sorts it in ascending order O(N^2)
    LinkedList* tempL = l;
    LL_BubbleSort(l);
    printf("bubbleSort: \n");
    LL_PrintLinkedList(l);
    //QuickSort: takes in a list and sorts it in ascendint order 
    //worstcase: O(N^2); bestcase: O(NlogN)
    l = tempL;
    LL_QuickSort(l);
    printf("QuickSort: \n");
    LL_PrintLinkedList(l);
