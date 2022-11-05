#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void printList(nodep_t p) {
    if(p==NULL) {
        printf("node 0");
        return;
    }
    while(p!=NULL) {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void insertfront(nodep_t *p,int data) {
    nodep_t newNode=create(data);
    newNode->next=*p;
    *p=newNode;
}

void insertback(nodep_t *p,int data) {
    node_t *newNode=create(data);
    if(*p==NULL) {
        *p=newNode;
        return;
    }
    nodep_t current=*p;
    while(current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
}

void insertfind(nodep_t *p,int k,int data) {
    nodep_t newNode;
    nodep_t current=*p;
    nodep_t after=(*p)->next;
    while(current!=NULL) {
        if(current->data==k) {
            newNode=create(data);
            newNode->next=after;
            current->next=newNode;
        }
        if(after==NULL) {
            return;
        }
        current=after;
        after=after->next;
    }
}

void deletefront(nodep_t *p) {
    if(*p==NULL) {
        return;
    }
    *p=(*p)->next;
}

void deleteback(nodep_t *p) {
    if(*p==NULL) {
        return;
    }
    if((*p)->next==NULL) {
        *p=NULL;
        return;
    }
    nodep_t current=*p;
    while(current->next->next!=NULL) {
        current=current->next;
    }
    current->next=NULL;
}

void deletefind(nodep_t *p,int k) {
    nodep_t current=*p;
    nodep_t before=NULL;
    while(current!=NULL) {
        if(current->data==k) {
            if(before==NULL) {
                *p=(*p)->next;
                current=*p;
                before=NULL;
                continue;
            }
            else {
                before->next=current->next;
            }
        }
        before=current;
        current=current->next;
    }
}

int main() {
    nodep_t node=NULL;
    insertback(&node,3);
    insertback(&node,6);
    insertback(&node,21);
    insertback(&node,18);
    insertfind(&node,3,18);
    printList(node);
}
