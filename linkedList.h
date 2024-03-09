#pragma once

typedef struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    size_t length;
}LinkedList;

Node* LL_CreateNode(int v);

Node* LL_AppendNodeToNode(Node* prevNode, int v);

Node* LL_GetElementFromNode(Node* h, int i);

Node* LL_GetElement(LinkedList* l, int i);

LinkedList* LL_CreateLinkedListNonVariadic(int v);

void LL_AppendLinkedList(LinkedList* l, int v);

void LL_AppfrontLinkedList(LinkedList* l, int v);

int LL_DeleteNode(LinkedList* l, int i);

void LL_PrintAllElements(LinkedList* l);

void LL_PrintLinkedList(LinkedList* l);

void LL_ExtendLinkedList(LinkedList* l, int count, ...);

LinkedList* LL_CreateLinkedList(int count, ...);

LinkedList* LL_CreateLinkedListFromNode(Node* head, Node* tail);

void LL_FreeLinkedList(LinkedList* l);

void LL_SwapElements(LinkedList* l, int i1, int i2);

int LL_IndexOfByValue(LinkedList* l, int v);

int LL_IndexOf(LinkedList* l, Node* n);

void LL_BubbleSort(LinkedList* l);

void LL_InsertAt(LinkedList* l, int index, int v);

LinkedList* LL_CreateView(LinkedList* l, int startI, int endI);

int LL_WeakSort(LinkedList* l, int pivotIndex);

int LL_WeakSortWithRange(LinkedList* l, int lowIndex, int highIndex);

void LL_QuickSortUnWrapped(LinkedList* l, int lowIndex, int highIndex);

void LL_QuickSort(LinkedList* l);

