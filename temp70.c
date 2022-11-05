#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct node_s {
    char data;
    struct node_s *left, *right;
}tree_t;

typedef tree_t *btree;

int search(char in[], int start, int end, char data)
{
    for ( int i = start; i <= end; i++)
    {
        if (in[i] == data) return i;
    }
}

btree create_Tree_byPre(char in[], char pre[], int inStart, int inEnd, int *preIndex)
{

    if (inStart > inEnd) return NULL;
    btree newnode;
    newnode = (btree)malloc(sizeof(btree));
    newnode->data = pre[(*preIndex)++];
    newnode->left = newnode->right = NULL;
    if (inStart == inEnd) return newnode;
    int inIndex = search(in, inStart, inEnd, newnode->data);
    newnode->left = create_Tree_byPre(in, pre, inStart, inIndex - 1, preIndex);
    newnode->right = create_Tree_byPre(in, pre, inIndex + 1, inEnd, preIndex);
    return newnode;
}

btree create_Tree_byPost(char in[], char post[], int inStart, int inEnd, int *postIndex)
{
    if (inStart > inEnd) return NULL;
    btree newnode;
    newnode = (btree)malloc(sizeof(btree));
    newnode->data = post[(*postIndex)--];
    newnode->left = newnode->right = NULL;
    if (inStart == inEnd) return newnode;
    int inIndex = search(in, inStart, inEnd, newnode->data);
    newnode->right = create_Tree_byPost(in, post, inIndex + 1, inEnd, postIndex);
    newnode->left = create_Tree_byPost(in, post, inStart, inIndex - 1, postIndex);
    return newnode;
}

int height(btree root)
{
    if (root == NULL) return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight) return (lheight + 1);
        else return (rheight + 1);
    }
}

void printCurrentLevel(btree root, int level)
{
    if (root == NULL) return;
    if (level == 1) printf("%c", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(btree root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{

    char ch, judge[2], pre[SIZE], in[SIZE], post[SIZE];
    int preIndex = 0, postIndex = 0, inStart = 0, inEnd=0;
    int isPre = 0;
    btree root = NULL;
    for(int i=0; i<SIZE; i++)
    {
        pre[i] = '\0';
        in[i] = '\0';
        post[i] = '\0';
    }
    for(int i=0; i<2; i++)
    {
        judge[i] = '\0';
        scanf(" %c",&ch);
        judge[i] = ch;
        switch(ch)
        {
        case 'P':
            scanf("%s", pre);
            break;
        case 'I':
            scanf("%s", in);
            break;
        case 'O':
            scanf("%s", post);
            break;
        default:
            break;
        }
    }
    for(int i=0; i<2; i++)
    {
        if(judge[i] == 'P')
        {
            isPre = 1;
        }
    }
    inEnd = strlen(in) - 1;
    postIndex = strlen(in) - 1;
    if(isPre)
    {
        root = create_Tree_byPre(in, pre, inStart, inEnd, &preIndex);
    }
    else
    {
        root = create_Tree_byPost(in, post, inStart, inEnd, &postIndex);
    }
    printLevelOrder(root);
    return 0;
}