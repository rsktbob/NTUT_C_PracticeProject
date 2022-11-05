#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void enqueue(nodep_t *p_head, nodep_t *p_tail, int data) {
    nodep_t newNode=create(data);
    if(*p_head == NULL) {
        *p_head=*p_tail=create(data);
        return;
    }
    (*p_tail)->next=newNode;
}

int dequeue(nodep_t *p_head) {
    if(*p_head==NULL) {
        return 0
    }
    int x1=(*p_head)->data;
    (*p_head)=(*p_head)->next;
    return x1;
}
int main() {
    int x;
    nodep_t tail = NULL, head=NULL;
    enqueue(&head, &tail,5);
    enqueue(&head, &tail,8);
    x = dequeue(&head);
    printf("%d\n", x);
    return 0;
}