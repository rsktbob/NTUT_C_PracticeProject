#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s* left;
    struct node_s* right;
} node_t;

typedef node_t* nodep_t;

nodep_t create(int data) {
    nodep_t newnode =(nodep_t)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}

void create_tree(int data,nodep_t *root) {
    nodep_t newnode =(nodep_t)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(*root == NULL) {
        *root = newnode;
        return;
    }
    nodep_t current,back;
    current = *root;
    while(current != NULL) {
        back=current;
        if(current->data>data) {
            current=current->left;
        }
        else {
            current=current->right;
        }
    }
    if(back->data>data) {
        back->left=newnode;
    }
    else {
        back->right=newnode;
    }
}

void preorder(nodep_t root) {
    if(root != NULL) {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(nodep_t root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

void postorder(nodep_t root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}

int main() {
    int x1;
    nodep_t root=NULL;
    for(int i=0;i<6;i++) {
        scanf("%d",&x1);
        create_tree(x1,&root);
    }
    preorder(root);
}