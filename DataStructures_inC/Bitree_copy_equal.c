#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct TreeNode{
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(TreeNode* left, element data, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->data = data;
    node->right = right;
    return node;
}

TreeNode* copy(TreeNode* root) {
    TreeNode* temp;
    if (root) {
        temp = (TreeNode*)malloc(sizeof(TreeNode));
        temp->data = root->data;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
        return temp;
    }
    else
        return NULL;
}

int equal(TreeNode* A, TreeNode* B) {
    return ((!A && !B) || (A && B && (A->data == B->data) && equal(A->right, B->right) && equal(A->left, B->left)));
}

void preorder(TreeNode* root) {
    if (root) {
        printf("[%c] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    TreeNode* I = makeNode(NULL,'I',NULL);
    TreeNode* H = makeNode(I,'H',NULL);
    TreeNode* G = makeNode(NULL,'G',NULL);
    TreeNode* F = makeNode(NULL,'F',H);
    TreeNode* E = makeNode(NULL,'E',NULL);
    TreeNode* D = makeNode(NULL,'D',G);
    TreeNode* C = makeNode(E,'C',F);
    TreeNode* B = makeNode(C,'B',D);
    TreeNode* A = makeNode(B,'A',NULL);

    TreeNode* Z = copy(A);
    preorder(A); printf("\n");
    preorder(Z); printf("\n");

    printf("equal: %d", equal(A,Z));
}

