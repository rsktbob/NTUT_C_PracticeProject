#include <stdio.h>
#include <stdlib.h>

typedef struct node_s { 
    int data; 
    struct node_s *next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) { 
    nodep_t newNode; 
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next=NULL;
    return newNode; 
}

void printList(nodep_t p) {
    if(p==NULL) {
        printf("None any node\n");
        return;
    } 
    nodep_t current = p;
    while(current!=NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void insertFromBack(nodep_t *p, int data) {
    nodep_t newNode,current;
    newNode = create(data);
    current = *p;
    if(*p==NULL){
        *p=newNode;
        return;
    }
    while (current->next!=NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertFromFind(nodep_t *p,int k,int data) {
    nodep_t newNode,current,after;
    newNode= create(data);
    if(*p==NULL) {
        return;
    }
    if((*p)->data && (*p)->next==NULL) {
        (*p)->next=newNode;
        return;
    }
    current=*p;
    after=current->next;
    while(after!=NULL) {
        if(current->data!=k) {
            current=after;
            after=after->next;
        }
        else {
            current->next = newNode;
            if(after!=NULL) {
                newNode->next=after;
                current=after;
                after=after->next;
                newNode= create(data);
            }
            else {
                return;
            }
        }
    }
    if(current->data==k) {
        current->next=create(data);
    }
}

void delateFromFront(nodep_t *p) {
    if(*p==NULL) {
        return;
    }
    *p=(*p)->next;
}

void delateFromBack(nodep_t *p) {
    if(*p==NULL) {
        return;
    }
    else if((*p)->next==NULL) {
        *p=NULL;
        return;
    }
    nodep_t current,after;
    current=*p;
    after=(*p)->next;
    while(after->next!=NULL) {
        current=after;
        after=after->next;
    }
    current->next=after->next;
}

void delateFromFind(nodep_t *p, int data) {
    nodep_t current,previous;
    int key=0;
    current=*p;
    previous=NULL;
    if(current==NULL) {
        return;
    }
    while(current!=NULL) {
        if(current->data==data) {
            if(previous==NULL) {
                *p=current->next;
                key=1;
            }
            else {
                previous->next = current->next;
            }
        }
        if(key==1) {
            previous=NULL;
        }
        else {
            previous=current;
        }
        current=current->next;
        key=0;
    }
}


int main() {
    nodep_t node=NULL;
    int x1;
    int x2;
    int p1;
    int data;
    scanf("%d",&x1);
    for(int i=0;i<x1;i++) {
        scanf("%d",&data);
        insertFromBack(&node,data);
    }
    while(1) {
        scanf("%d",&x2);
        switch(x2) {
            case 1:
                scanf("%d",&data);
                insertFromBack(&node,data);
                break;
            case 2:
                scanf("%d",&p1);
                scanf("%d",&data);
                insertFromFind(&node,p1,data);
                break;
            case 3:
                scanf("%d",&data);
                delateFromFind(&node,data);
                break;
            case 4:
                delateFromFront(&node);
                break;
            case 5:
                delateFromBack(&node);
                break;
            case 6:
                printList(node);
                exit(0);
        }
    }
}
