#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void add_node(nodep_t *node,int k) {
    nodep_t newNode=create(k);
    if(*node==NULL) {
        *node=newNode;
        return;
    }
    nodep_t current=*node;
    while(current->left!=NULL || current->right!=NULL) {
        if(current->data>k) {
            if(current->left==NULL) {
                break;
            }
            current=current->left;
        }
        else {
            if(current->right==NULL) {
                break;
            }
            current=current->right;
        }
    }
    if(current->data>k) {
        current->left=newNode;
    }
    else {
        current->right=newNode;
    }
}

void delete_node(nodep_t *node,int k) {
    nodep_t current1=*node;
    nodep_t current2;
    nodep_t back1=*node;
    nodep_t back2=NULL;
    if(*node==NULL) {
        return;
    }
    if((*node)->left==NULL && (*node)->right==NULL && (*node)->data==k) {
        *node==NULL;
        return;
    }
    while(current1->left!=NULL || current1->right!=NULL) {
        if(current1->data>k) {
            if(current1->left==NULL) {
                break;
            }
            back1=current1;
            current1=current1->left;
        }
        else if(current1->data==k) {
            break;
        }
        else {
            if(current1->right==NULL) {
                break;
            }
            back1=current1;
            current1=current1->right;
        }
    }
    if(current1->data!=k) {
        return;
    }
    current2=current1;
    back2=current2;
    if(current2->left!=NULL) {
        current2=current2->left;
        while(current2->right!=NULL) {
            back2=current2;
            current2=current2->right;
        }
        current1->data=current2->data;
        back2->left=NULL;
    }
    else if(current2->right!=NULL) {
        current2=current2->right;
        while(current2->left!=NULL) {
            back2=current2;
            current2=current2->left;
        }
        current1->data=current2->data;
        back2->right=NULL;
    }
    else if(current2->left==NULL && current2->right==NULL) {
        if(current1==back1->left) {
            back1->left=NULL;
        }
        else {
            back1->right=NULL;
        }
    }
}

void preorder(nodep_t node) {
    if(node!=NULL) {
        printf("%d\n",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {
    nodep_t node=NULL;
    add_node(&node,3);
    add_node(&node,2);
    add_node(&node,45);
    add_node(&node,6);
    add_node(&node,21);
    add_node(&node,18);
    delete_node(&node,18);
    preorder(node);
}