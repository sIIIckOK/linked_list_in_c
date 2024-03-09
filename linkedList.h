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

Node* CreateNode(int v);

Node* AppendNodeToNode(Node* prevNode, int v);

Node* GetElementFromNode(Node* h, int i);

Node* GetElement(LinkedList* l, int i);

LinkedList* CreateLinkedListNonVariadic(int v);

void AppendLinkedList(LinkedList* l, int v);

void AppfrontLinkedList(LinkedList* l, int v);

int DeleteNode(LinkedList* l, int i);

void PrintAllElements(LinkedList* l);

void PrintLinkedList(LinkedList* l);

void ExtendLinkedList(LinkedList* l, int count, ...);

LinkedList* CreateLinkedList(int count, ...);

LinkedList* CreateLinkedListFromNode(Node* head, Node* tail);

void FreeLinkedList(LinkedList* l);

void SwapElements(LinkedList* l, int i1, int i2);

int IndexOfByValue(LinkedList* l, int v);

int IndexOf(LinkedList* l, Node* n);

void BubbleSort(LinkedList* l);

void InsertAt(LinkedList* l, int index, int v);

LinkedList* CreateView(LinkedList* l, int startI, int endI);

int WeakSort(LinkedList* l, int pivotIndex);

int WeakSortWithRange(LinkedList* l, int lowIndex, int highIndex);

void QuickSortUnWrapped(LinkedList* l, int lowIndex, int highIndex);

void QuickSort(LinkedList* l);

