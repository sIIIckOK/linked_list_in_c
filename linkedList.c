#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
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

LinkedList* CreateLinkedListNonVariadic(int v){
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

int DeleteNode(LinkedList* l, int i){
    Node* n = GetElement(l, i);
    int popValue = n->value;
    Node* nextN = n->next;
    Node* prevN = n->prev;
    nextN->prev = prevN;
    prevN->next = nextN;
    free(n);
    l->length--;
    return popValue;
}

void PrintAllElements(LinkedList* l){
    printf("---------------\n");
    for (int i = 0; i < l->length; i++){
        Node* n = GetElement(l, i);
        int v = n->value;
        printf("index: %d value: %d\n", i, v);
    }
    printf("---------------\n");
}

void ExtendLinkedList(LinkedList* l, int count, ...){
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        int a = va_arg(args, int);
        AppendLinkedList(l, a);
    }
    va_end(args);
}

LinkedList* CreateLinkedList(int count, ...){
    LinkedList* l = malloc(sizeof(LinkedList));
    l->length = 1;
    va_list args;
    va_start(args, count);
    int first = va_arg(args, int);
    Node* n = CreateNode(first);
    l->head = n;
    for(int i = 0; i < count-1; i++){
        int rest = va_arg(args, int);
        Node* temp = AppendNodeToNode(n, rest);
        n = temp;
        l->length++;
    }
    l->tail = n;
    va_end(args);
    return l;
}

