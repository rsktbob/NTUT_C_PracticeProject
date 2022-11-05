#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s* next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFromFront(nodep_t *p,int data) {
    nodep_t newNode=create(data);
    newNode->next=*p;
    *p=newNode;
}

void insertFromBack(nodep_t *p,int data) {
    nodep_t newNode=create(data);
    if(*p==NULL) {
        *p=newNode;
        return;
    }
    else {
        nodep_t current;
        current=*p;
        while(current->next!=NULL) {
            current=current->next;
        }
        current->next=newNode;
    }
}

void deleteFromBack(nodep_t *p) {
    if(*p==NULL) {
        return;
    }
    if((*p)->next==NULL) {
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
    current->next=NULL;
}

void add_node(nodep_t *p1,nodep_t *p2,nodep_t *p3,int *num1) {
    int k1=1;
    int k2=1;
    int k3;
    nodep_t current1,current2,node;
    current1=*p1;
    while(current1->next!=NULL) {
        current1=current1->next;
        k1++;
    }
    current2=*p2;
    while(current2->next!=NULL) {
        current2=current2->next;
        k2++;
    }
    *num1=k2;
    k3=k1+k2-1;
    for(int i=0;i<k3-k1;i++) {
        insertFromBack(p1,0);
    }
    for(int i=0;i<k3-k2;i++) {
        insertFromBack(p2,0);
    }
    for(int i=0;i<k3;i++) {
        insertFromBack(p3,0);
    }
}

void init(nodep_t *p1) {
    nodep_t current=*p1;
    while(current!=NULL) {
        current->data=0;
        current=current->next;
    }
}

void add(nodep_t p1,nodep_t p2,nodep_t *p3) {
    nodep_t current1=p1;
    nodep_t current2=p2;
    nodep_t current3=*p3;
    int sum;
    int carry=0;
    while(current1!=NULL) {
        current3->data=current1->data+current2->data;
        current1=current1->next;
        current2=current2->next;
        current3=current3->next;
    }
}

void sub(nodep_t p1,nodep_t p2,nodep_t *p3) {
    nodep_t current1=p1;
    nodep_t current2=p2;
    nodep_t current3=*p3;
    int sum;
    int carry=0;
    while(current1!=NULL) {
        current3->data=current1->data-current2->data;
        current1=current1->next;
        current2=current2->next;
        current3=current3->next;
    }
}

void mul(nodep_t p1,nodep_t p2,nodep_t *p3,int num1) {
    nodep_t current=p2;
    for(int i=0;i<num1;i++) {
        if(current->data>0){
            for(int j=0;j<current->data;j++) {
                add(p1,*p3,p3);
            }
        }
        else {
            for(int j=0;j<abs(current->data);j++) {
                sub(*p3,p1,p3);
            }
        }
        insertFromFront(&p1,0);
        deleteFromBack(&p1);
        current=current->next;
    }
}

void printList(nodep_t p) {
    nodep_t current;
    current=p;
    int key=0;
    int x1[20]={0};
    int x2=0;
    for(int i=0;current!=NULL;i++) {
        x1[i]=current->data;
        current=current->next;
        x2++;
    }
    for(int i=x2-1;i>=0;i--) {
        if(key==1 && x1[i]>0) {
            printf("+");                   
        }
        if(x1[i]!=0) {
            key=1;
            if(abs(x1[i])!=1) {
                if(i==0) {
                    printf("%d",x1[i]);
                }
                else if(i==1) {
                    printf("%dx",x1[i]);
                }
                else {
                    printf("%dx^%d",x1[i],i);
                }
            }
            else {
                if(x1[i]==-1 && i!=0) {
                    printf("-");
                }
                if(i==0) {
                    printf("%d",x1[i]);
                }
                else if(i==1) {
                    printf("x");
                }
                else {
                    printf("x^%d",i);
                }
            }
        }
    }
    if(key==0) {
        printf("%d",0);
    }
    printf("\n");
}

int main() {
    nodep_t node1=NULL;
    nodep_t node2=NULL;
    nodep_t node3=NULL;
    char x1[80]={};
    char x2[80]={};
    char *k1;
    int num1=0;
    gets(x1);
    gets(x2);
    k1=strtok(x1, " ");
    while(k1!=NULL) {
        insertFromFront(&node1,atoi(k1));
        k1=strtok(NULL, " ");
    }
    k1=strtok(x2, " ");
    while(k1!=NULL) {
        insertFromFront(&node2,atoi(k1));
        k1=strtok(NULL," ");
    }
    add_node(&node1,&node2,&node3,&num1);
    add(node1,node2,&node3);
    printList(node3);
    sub(node1,node2,&node3);
    printList(node3);
    init(&node3);
    mul(node1,node2,&node3,num1);
    printList(node3);
}