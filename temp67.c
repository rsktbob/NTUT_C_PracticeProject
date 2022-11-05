#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(nodep_t *p_top, int x) {
    nodep_t newNode=create(x);
    newNode->next=*p_top;
    *p_top=newNode;
}
void printStack(nodep_t top) {
    nodep_t current=top;
    printf("\n The list is: ");
    while(current!=NULL) {
        printf("%d, ",current->data);
        current=current->next;
    }
}
int main() {
    nodep_t top = NULL;
    push(&top, 5);
    push(&top, 8);
    printStack(top);
    return 0;
}