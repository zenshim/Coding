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

int num_of_leaf(TreeNode* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;
    else {
        if (root->left && root->right)
            return num_of_leaf(root->left) + num_of_leaf(root->right);
        else if (root->left)
            return num_of_leaf(root->left);
        else
            return num_of_leaf(root->right);
    }
}

int height(TreeNode* root) {
    if (!root)
        return 0;
    else 
        return (1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right)));
}

TreeNode* swap_tree(TreeNode* root) {
    if (root) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        swap_tree(root->left);
        swap_tree(root->right);
    }
    return root;
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

    TreeNode* swaped = swap_tree(A);
    printf("num of leaf: %d\n", num_of_leaf(A));
    printf("height: %d\n", height(A));
    preorder(swaped);

    return 0;
}