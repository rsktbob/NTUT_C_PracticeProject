#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t * nodep_t;

int hcf(int x1,int x2) {
    int x3=x1;
    while(x3!=0) {
        x3=x2%x1;
        x2=x1;
        x1=x3;
    }
    return x2;
}

nodep_t create(int data) {
    nodep_t newnode=(nodep_t) malloc(sizeof(node_t));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void add_front(int data,nodep_t *root) {
    nodep_t newnode=create(data);
    newnode->next=*root;
    *root=newnode;
}

void add_back(int data,nodep_t *root) {
    nodep_t newnode=create(data);
    if(*root==NULL) {
        *root=newnode;
        return;
    }
    nodep_t current=*root;
    while(current->next!=NULL) {
        current=current->next;
    }
    current->next=newnode;
}

void remove_front(nodep_t *root) {
    if(*root==NULL) {
        return;
    }
    *root=(*root)->next;
}

void remove_back(nodep_t *root) {
    if(*root==NULL || (*root)->next==NULL) {
        return;
    }
    nodep_t current=*root;
    while(current->next->next!=NULL) {
        current=current->next;
    }
    current->next=NULL;
}

void insert_node(int data,int node,nodep_t *root) {
    nodep_t current=*root;
    while(current!=NULL) {
        if(current->data==node) {
            nodep_t newnode=create(data);
            newnode->next=current->next;
            current->next=newnode;
        }
        current=current->next;
    }
}

void delete_node(int node,nodep_t *root) {
    while((*root)!=NULL) {
        if((*root)->data==node) {
            *root=(*root)->next;
        }
        else {
            break;
        }
    }
    if(*root==NULL) {
        return;
    }
    nodep_t current=*root;
    while(current->next!=NULL) {
        if(current->next->data==node) {
            current->next=current->next->next;
        }
        current=current->next; 
    }
}

void print_node(nodep_t root) {
    if(root==NULL) {
        printf("%s\n","no nodes");
        return;
    }
    nodep_t current=root;
    while(current!=NULL) {
        printf("%d\n",current->data);
        current=current->next;  
    }
}

int main() {
    int x1;
    int x2;
    char *x3[20]={};
    char k1[20]="sdqweqwft";
    char k2[20]="eqadaswet";
    char k3[20]="dfadsast";
    nodep_t root=NULL;
    x3[0]=&k1[0];
    x3[1]=&k2[0];
    x3[2]=&k3[0];
    strcpy(x3[0],"sdfsadft");
    printf("%s\n",k1);
    printf("%s\n",x3[1]);
    printf("%s\n",x3[2]);
}