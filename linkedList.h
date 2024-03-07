#pragma once

typedef struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    int length;
}LinkedList;

Node* CreateNode(int v);

Node* AppendNodeToNode(Node* prevNode, int v);

Node* GetElementFromNode(Node* h, int i);

Node* GetElement(LinkedList* l, int i);

LinkedList* CreateLinkedListNonVariadic(int v);

LinkedList* CreateLinkedList(int count, ...);

void AppendLinkedList(LinkedList* l, int v);

void AppfrontLinkedList(LinkedList* l, int v);

int DeleteNode(LinkedList* l, int i);

void PrintAllElements(LinkedList* l);

void ExtendLinkedList(LinkedList* l, int v, ...);

LinkedList* CreateLinkedList(int count, ...);

void FreeLinkedList(LinkedList* l);

void SwapElements(LinkedList* l, int i1, int i2);

void SwapElements(LinkedList* l, int i1, int i2);

int IndexOfByValue(LinkedList* l, int v);

int IndexOf(LinkedList* l, Node* n);

void BubbleSort(LinkedList* l);

