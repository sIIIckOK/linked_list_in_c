#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "linkedList.h"

Node* CreateNode(int v){
    Node* pn = (Node*)malloc(sizeof(Node));
    pn->value = v;
    pn->prev = NULL;
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
    int tempI = i;
    while(tempI > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: in GetElementFromNode element out of bounds, index: %d\n", i);
        }
        nextNode = nextNode->next;
        tempI--;    
    }
    return nextNode;
}

Node* GetElement(LinkedList* l, int i){
    Node* nextNode = l->head; 
    int tempI = i;
    while(tempI > 0){
        if (nextNode-> next == NULL){
            printf("[ERROR]: in GetElement element out of bounds, index: %d\n", i);
            return NULL;
        }
        nextNode = nextNode->next;
        tempI--;    
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
        if (n == NULL){
            printf("[ERROR]: in PrintAllElements error while accessing element, index: %d\n", i);
            return;
        }
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

void FreeLinkedList(LinkedList* l){
    int length = l->length;
    for (int i = 0; i < length; i++){
        Node* n = GetElement(l, i);
        free(n);
    }
    free(l);
}

void SwapElements(LinkedList* l, int i1, int i2){
    if (i1 == i2) return;
    Node* n1 = GetElement(l, i1);
    Node* n2 = GetElement(l, i2);

    if (n1 == l->head){
        n2->prev->next = n1;
        l->head = n2;
        n1->prev = n2->prev;
        n2->prev = NULL;
    } else if (n2 == l->head){
        n1->prev->next = n2;
        l->head = n1;
        n2->prev = n1->prev;
        n1->prev = NULL;
    } else {
        n1->prev->next = n2;
        n2->prev->next = n1;
        Node* tempPrev = n1->prev;
        n1->prev = n2->prev;
        n2->prev = tempPrev;
    }

    if (n1 == l->tail){
        n2->next->prev = n1;
        l->tail = n2;
        n1->next = n2->next;
        n2->next = NULL;
    } else if (n2 == l->tail){
        n1->next->prev = n2;
        l->tail = n1;
        n2->next = n1->next;
        n1->next = NULL;
    } else {
        n1->next->prev = n2;
        n2->next->prev = n1;
        Node* tempNext = n1->next;
        n1->next = n2->next;
        n2->next = tempNext;
    }

}

int IndexOfByValue(LinkedList* l, int v){
    int len = l->length;
    for (int i = 0; i < l->length; i++){
        Node* e = GetElement(l, i);
        if (e->value==v){
            return i;
        }
    }
    return -1;
}

int IndexOf(LinkedList* l, Node* n){
    for (int i = 0; i < l->length; i++){
        Node* e = GetElement(l, i);
        if (e->next == n){
            return i+1;
        }
    }
    return -1;
}


void BubbleSort(LinkedList* l){
    for (int j = 0; j < l->length-1; j++){
        for (int i = 0; i < l->length-1; i++){
            Node* e = GetElement(l, i);
            Node* eNext = GetElement(l, i+1);
            if (e->value > eNext->value){
                SwapElements(l, i, i+1);
            }
        }
    }
}


int main(){
    LinkedList* l = CreateLinkedList(4, 1, 7, 4, 2);
    PrintAllElements(l);
    BubbleSort(l);
    PrintAllElements(l);
}



