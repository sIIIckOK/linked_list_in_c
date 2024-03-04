#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

Node* CreateNode(int v){
    Node* pn = (Node*)malloc(sizeof(Node));
    pn->value = v;
    pn->prev= NULL;
    pn->next = NULL;
    return pn;
}

Node* AppendNodeToNode(Node* prevNode, int v){
    Node* pn = CreateNode(v);
    pn->value = v;
    prevNode->next = pn; 
    pn->prev = prevNode;
    return pn;
}

Node* GetElementFromNode(Node* h, int i){ 
    Node* nextNode = h; 
    while(i > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: element out of bounds");
        }
        nextNode = nextNode->next;
        i--;    
    }
    return nextNode;
}

Node* GetElement(LinkedList* l, int i){
    Node* nextNode = l->head; 
    while(i > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: element out of bounds");
        }
        nextNode = nextNode->next;
        i--;    
    }
    return nextNode;
}

LinkedList* CreateLinkedList(int v){
    Node* n = CreateNode(v);
    LinkedList* l = malloc(sizeof(LinkedList));
    l->head = n;
    l->tail = n;
    l->length = 1;
    return l;
}

void AppendLinkedList(LinkedList* l, int v){
    Node* t = l->tail;
    Node* newNode = CreateNode(v);
    t->next = newNode;
    newNode->prev = t;    
    l->tail = newNode;
    l->length++;
}

void AppfrontLinkedList(LinkedList* l, int v){
    Node* h = l->head;
    Node* newNode = CreateNode(v);
    h->prev = newNode;
    newNode->next = h;    
    l->head = newNode;
    l->length++;
}

Node* CreateNode(int v){
    Node* pn = (Node*)malloc(sizeof(Node));
    pn->value = v;
    pn->prev= NULL;
    pn->next = NULL;
    return pn;
}

Node* AppendNodeToNode(Node* prevNode, int v){
    Node* pn = CreateNode(v);
    pn->value = v;
    prevNode->next = pn; 
    pn->prev = prevNode;
    return pn;
}

Node* GetElementFromNode(Node* h, int i){ 
    Node* nextNode = h; 
    while(i > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: element out of bounds");
        }
        nextNode = nextNode->next;
        i--;    
    }
    return nextNode;
}

Node* GetElement(LinkedList* l, int i){
    Node* nextNode = l->head; 
    while(i > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: element out of bounds");
        }
        nextNode = nextNode->next;
        i--;    
    }
    return nextNode;
}

LinkedList* CreateLinkedList(int v){
    Node* n = CreateNode(v);
    LinkedList* l = malloc(sizeof(LinkedList));
    l->head = n;
    l->tail = n;
    l->length = 1;
    return l;
}

void AppendLinkedList(LinkedList* l, int v){
    Node* t = l->tail;
    Node* newNode = CreateNode(v);
    t->next = newNode;
    newNode->prev = t;    
    l->tail = newNode;
    l->length++;
}

void AppfrontLinkedList(LinkedList* l, int v){
    Node* h = l->head;
    Node* newNode = CreateNode(v);
    h->prev = newNode;
    newNode->next = h;    
    l->head = newNode;
    l->length++;
}
