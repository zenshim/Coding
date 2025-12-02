#include <stdio.h>
#include <stdlib.h>
#define t true
#define f false
typedef char element;
typedef struct ThreadNode{
    element data;
    struct ThreadNode* left;
    struct ThreadNode* right;
    int left_thread;
    int right_thread;
}ThreadNode;

ThreadNode* makeNode(int lthread, ThreadNode* left, element data, ThreadNode* right, int rthread) {
    ThreadNode* node = (ThreadNode*)malloc(sizeof(ThreadNode));
    node->data = data;
    node->left = left; node->right = right;
    node->left_thread = lthread; node->right_thread = rthread;
    return node;
}

ThreadNode* inorder_successor(ThreadNode* T) {
    ThreadNode* temp = T->right;
    if(!T->right_thread) {
        while(!temp->left_thread)
            temp = temp->left;
    }
    return temp;
}

void tinorder(ThreadNode* T) {
    ThreadNode* temp = T;
    for(;;) {
        temp = insucc(temp);
        if (temp == T)
            break;
        printf("[%c] ", temp->data);
    }
}


int main() {
    ThreadNode *root,*A,*B,*C,*D,*E,*F,*G,*H,*I;
    I = makeNode(t,D,'I',B,t);
    H = makeNode(t,root,'H',D,t);
    G = makeNode(t,C,'G',C,root);
    F = makeNode(t,A,'F',C,t);
    E = makeNode(t,B,'E',A,t);
    D = makeNode(f,H,'D',I,f);
    C = makeNode(f,F,'C',G,f);
    B = makeNode(f,D,'B',E,f);
    A = makeNode(f,B,'A',C,f);
    root = makeNode(f,A,'-',root,f);


}