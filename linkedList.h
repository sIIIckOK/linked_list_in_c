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

LinkedList* CreateLinkedList(int v);

void AppendLinkedList(LinkedList* l, int v);

void AppfrontLinkedList(LinkedList* l, int v);
