#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "linkedList.h"

Node* LL_CreateNode(int v){
    Node* pn = (Node*)malloc(sizeof(Node));
    pn->value = v;
    pn->prev = NULL;
    pn->next = NULL;
    return pn;
}

Node* LL_AppendNodeToNode(Node* prevNode, int v){
    Node* pn = LL_CreateNode(v);
    pn->value = v;
    prevNode->next = pn; 
    pn->prev = prevNode;
    return pn;
}

Node* LL_GetElementFromNode(Node* h, int i){
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

Node* LL_GetElement(LinkedList* l, int i){
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

LinkedList* LL_CreateLinkedListNonVariadic(int v){
    Node* n = LL_CreateNode(v);
    LinkedList* l = malloc(sizeof(LinkedList));
    l->head = n;
    l->tail = n;
    l->length = 1;
    return l;
}

void LL_AppendLinkedList(LinkedList* l, int v){
    Node* t = l->tail;
    Node* newNode = LL_CreateNode(v);
    t->next = newNode;
    newNode->prev = t;    
    l->tail = newNode;
    l->length++;
}
void LL_AppfrontLinkedList(LinkedList* l, int v){
    Node* h = l->head;
    Node* newNode = LL_CreateNode(v);
    h->prev = newNode;
    newNode->next = h;    
    l->head = newNode;
    l->length++;
}

int LL_DeleteNode(LinkedList* l, int i){
    Node* n = LL_GetElement(l, i);
    int popValue = n->value;
    Node* nextN = n->next;
    Node* prevN = n->prev;
    nextN->prev = prevN;
    prevN->next = nextN;
    free(n);
    l->length--;
    return popValue;
}

void LL_PrintAllElements(LinkedList* l){
    printf("---------------\n");
    for (int i = 0; i < l->length; i++){
        Node* n = LL_GetElement(l, i);
        if (n == NULL){
            printf("[ERROR]: in PrintAllElements error while accessing element, index: %d\n", i);
            return;
        }
        int v = n->value;
        printf("index: %d value: %d\n", i, v);
    }
    printf("---------------\n");
}

void LL_PrintLinkedList(LinkedList* l){
    int len = l->length;
    printf("[ ");
    for (int i = 0; i < len; i++){
        Node* n = LL_GetElement(l, i);
        printf("%d ", n->value);
    } 
    printf("]\n");
}

void LL_ExtendLinkedList(LinkedList* l, int count, ...){
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        int a = va_arg(args, int);
        LL_AppendLinkedList(l, a);
    }
    va_end(args);
}

LinkedList* LL_CreateLinkedList(int count, ...){
    LinkedList* l = malloc(sizeof(LinkedList));
    l->length = 1;
    va_list args;
    va_start(args, count);
    int first = va_arg(args, int);
    Node* n = LL_CreateNode(first);
    l->head = n;
    for(int i = 0; i < count-1; i++){
        int rest = va_arg(args, int);
        Node* temp = LL_AppendNodeToNode(n, rest);
        n = temp;
        l->length++;
    }
    l->tail = n;
    va_end(args);
    return l;
}

LinkedList* LL_CreateLinkedListFromNode(Node* head, Node* tail){
    int len= 0;
    Node* n = head;
    while(1){
        len++; 
        if (n->next == tail || n->next == NULL){
            break;
        }
        n = n->next;
    }
    LinkedList* l = malloc(sizeof(LinkedList));
    l->length = len;
    l->head = head;
    l->tail = tail;
    return l;
}

void LL_FreeLinkedList(LinkedList* l){
    int length = l->length;
    for (int i = 0; i < length; i++){
        Node* n = LL_GetElement(l, i);
        free(n);
    }
    free(l);
}

void LL_SwapElements(LinkedList* l, int i1, int i2){
    if (i1 == i2) return;
    Node* n1 = LL_GetElement(l, i1);
    Node* n2 = LL_GetElement(l, i2);

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

int LL_IndexOfByValue(LinkedList* l, int v){
    int len = l->length;
    for (int i = 0; i < l->length; i++){
        Node* e = LL_GetElement(l, i);
        if (e->value==v){
            return i;
        }
    }
    return -1;
}

int LL_IndexOf(LinkedList* l, Node* n){
    for (int i = 0; i < l->length; i++){
        Node* e = LL_GetElement(l, i);
        if (e->next == n){
            return i+1;
        }
    }
    return -1;
}

void LL_BubbleSort(LinkedList* l){
    for (int j = 0; j < l->length-1; j++){
        for (int i = 0; i < l->length-1; i++){
            Node* e = LL_GetElement(l, i);
            Node* eNext = LL_GetElement(l, i+1);
            if (e->value > eNext->value){
                LL_SwapElements(l, i, i+1);
            }
        }
    }
}

void LL_InsertAt(LinkedList* l, int index, int v){
    Node* n = LL_CreateNode(v);

    if (index < l->length){
        Node* nextN = LL_GetElement(l, index);        
        n->next = nextN;
        nextN->prev = n;
    }
    if (index > 0){
        Node* prevN = LL_GetElement(l, index-1);        
        n->prev = prevN;
        prevN->next = n;
    }
    l->length++;
}

LinkedList* LL_CreateView(LinkedList* l, int startI, int endI){
    LinkedList* newL = malloc(sizeof(LinkedList));
    newL->head = LL_GetElement(l, startI);
    newL->tail = LL_GetElement(l, endI);
    newL->length = endI-startI;
    return newL;
}

int LL_WeakSort(LinkedList* l, int pivotIndex){
    int len = l->length;
    Node* p = LL_GetElement(l, pivotIndex);

    int markerI = pivotIndex;
    Node* marker = LL_GetElement(l, pivotIndex);

    bool trigger = true;
    for(int i = 0; i < len-1; i++){
        Node* currN = LL_GetElement(l, i);
        if (p->value < currN->value && trigger == true){
            markerI = i;
            marker = LL_GetElement(l, markerI);
            trigger = false; 
        }
        if (p->value > currN->value && trigger == false){
            LL_SwapElements(l, markerI, i);
            markerI++;
            marker = LL_GetElement(l, markerI);
        }
    }
    LL_SwapElements(l, markerI, pivotIndex);
    return markerI;
}

int LL_WeakSortWithRange(LinkedList* l, int lo, int hi){
    int swapI = lo;
    LL_SwapElements(l, lo+((hi-lo)/2), hi);
    int pivotI = hi;
    Node* pivotN = LL_GetElement(l, pivotI);
    for (int i = lo; i < hi; i++){
        Node* curN = LL_GetElement(l, i);
        if (curN->value <= pivotN->value){
            LL_SwapElements(l, i, swapI);
            swapI++;
        } 
    }
    LL_SwapElements(l, swapI, pivotI);
    return swapI;
}

void LL_QuickSortUnWrapped(LinkedList* l, int lo, int hi){
    if (hi-lo <= 0){
        return;
    }
    int newP = LL_WeakSortWithRange(l, lo, hi); 
    LL_QuickSortUnWrapped(l, lo, newP-1);
    LL_QuickSortUnWrapped(l, newP+1, hi);
}

void LL_QuickSort(LinkedList* l){
    int lo = 0;
    int hi = l->length-1;
    LL_QuickSortUnWrapped(l, lo, hi);
}

