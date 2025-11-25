#include <stdio.h>
#include <stdlib.h>
typedef enum {not,and,or,True,False}logical;
typedef struct TreeNode{
    logical data;
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(TreeNode* left, logical data, int value, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->data = data;
    node->value = value;
    node->right = right;
    return node;
}

void post_order_eval(TreeNode* root){
    if (root) {
        post_order_eval(root->left);
        post_order_eval(root->right);
        switch(root->data) {
            case not: root->value = !root->right->value; break;
            case and: root->value = root->left->value && root->right->value; break;
            case or: root->value = root->left->value || root->right->value; break;
            case True: root->value = 1; break;
            case False: root->value = 0; break;
        }
    }
}

int main() {
    TreeNode* L = makeNode(NULL,True,1,NULL);
    TreeNode* K = makeNode(NULL,True,1,NULL);
    TreeNode* J = makeNode(NULL,True,1,NULL);
    TreeNode* I = makeNode(NULL,not,0,L);
    TreeNode* H = makeNode(NULL,not,0,K);
    TreeNode* G = makeNode(NULL,True,1,NULL);
    TreeNode* F = makeNode(NULL,True,1,NULL);
    TreeNode* E = makeNode(I,and,0,J);
    TreeNode* D = makeNode(G,and,0,H);
    TreeNode* C = makeNode(NULL,True,1,F);
    TreeNode* B = makeNode(D,or,0,E);
    TreeNode* A = makeNode(B,or,0,C);

    post_order_eval(A);
    printf("%d\n", A->value);

    
}