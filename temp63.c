#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char name[20];
    int age;
    int year;
    int month;
    int day;
    struct node_s *next;
} node_t;

typedef node_t * nodep_t;


nodep_t create(char *name, int age, int year, int month, int day) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->year = year;
    newNode->month = month;
    newNode->day = day;
    newNode->next = NULL;
    return newNode;
}

void push(nodep_t *p,char *name, int age, int year, int month, int day) {
    nodep_t newNode;
    newNode = create(name,age,year,month,day);
    newNode->next = *p;
    *p = newNode;
}

void pop(nodep_t *p) {
    nodep_t current=*p;
    if(*p==NULL) {
        return;
    }
    *p=(*p)->next;
}

int main() {
    nodep_t node=NULL;
    int x1;
    int x2;
    char name[20]={};
    int age;
    int year;
    int month;
    int day;
    while(1) {
        scanf("%d",&x1);
        switch(x1) {
            case 1:
                scanf("%s %d %d %d %d",name,&age,&year,&month,&day);
                push(&node,name,age,year,month,day);
                break;
            case 2:
                scanf("%d",&x2);
                if(node==NULL) {
                    printf("The Stack is empty\n");
                    break;
                }
                if(x2==1) {
                    printf("%s\n",node->name);
                }
                else if(x2==2) {
                    printf("%d\n",node->age);
                }
                else if(x2==3) {
                    printf("%d_%d_%d\n",node->year,node->month,node->day);
                }
                pop(&node);
                break;
            case 3:
                if(node==NULL) {
                    printf("The Stack is empty\n");
                    break;
                }
                while(1) {
                    printf("%s %d %d_%d_%d\n",node->name,node->age,node->year,node->month,node->day);
                    pop(&node);
                    if(node==NULL) {
                        break;
                    }
                }
                break;
            case 4:
                if(node==NULL) {
                    printf("The Stack is empty\n");
                    break;
                }
                nodep_t current=node;
                while(current!=NULL) {
                    printf("%s %d %d_%d_%d\n",current->name,current->age,current->year,current->month,current->day);
                    current=current->next;
                }
                break;
            case 5:
                if(node==NULL) {
                    printf("%d\n",0);
                    exit(0);
                }
                for(int i=1; ;i++) {
                    pop(&node);
                    if(node==NULL) {
                        printf("%d\n",i);
                        exit(0);
                    }
                }    
        }
    }
}