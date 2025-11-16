#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef char element;
typedef struct TreeNode{
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(TreeNode* left, element e, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = left;
    node->right = right;
    return node;
}

typedef struct{
    int top;
    TreeNode* stack[N];
}Stack;

void init(Stack* S) {
    S->top = -1;
}

void push(Stack* S, TreeNode* node) {
    S->top++;
    S->stack[S->top] = node;
}

TreeNode* pop(Stack* S) {
    if(S->top == -1)
        return NULL;
    else
        return S->stack[S->top--];
}

void iter_inorder(TreeNode* root) {
    Stack S;
    init(&S);
    for(;;) {
        for(;root;root=root->left)
            push(&S,root);
        root = pop(&S);
        if (!root)
            break;
        printf("[%c] ", root->data);
        root = root->right;
    }
}

void iter_preorder(TreeNode* root) {
    Stack S;
    init(&S);
    for(;;) {
        for(;root;root=root->left) {
            push(&S,root);
            printf("[%c] ", root->data);
        }
        root = pop(&S);
        if(!root)
            break;
        root = root->right;
    }
}

typedef struct{
    int front,rear;
    TreeNode* queue[N];
}Queue;

void initq(Queue* Q) {
    Q->front = Q->rear = 0;
}

void enqueue(Queue* Q, TreeNode* node) {
    Q->rear = (Q->rear+1)%N;
    Q->queue[Q->rear] = node;
}

TreeNode* dequeue(Queue* Q) {
    if (Q->front == Q->rear)
        return NULL;
    else {
        Q->front = (Q->front+1)%N;
        return Q->queue[Q->front];
    }
}

void iter_levelorder(TreeNode* root) {
    Queue Q;
    initq(&Q);
    enqueue(&Q, root);
    for(;;) {
        root = dequeue(&Q);
        if (!root)
            break;
        printf("[%c] ", root->data);
        if (root->left)
            enqueue(&Q, root->left);
        if (root->right)
            enqueue(&Q, root->right);
    }
}

/*void iter_postorder(TreeNode* root) {
    Stack S;
    init(&S);
    TreeNode* current = root;
    TreeNode* previous = NULL;
    while(current!=NULL || S.top!=-1) {
        if (current) {
            push(&S, current);
            current = current->left;
        }
        else {
            TreeNode* topNode = S.stack[S.top];
            if (!topNode->right) {
                printf("[%c] ", topNode->data);
                topNode = pop(&S);
                previous = topNode;
                current = NULL;
            }
            else
                current = topNode->right;
        }
    }
}*/

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

    iter_inorder(A); printf("\n");
    iter_preorder(A); printf("\n");
    //iter_postorder(A); printf("\n");
    iter_levelorder(A); printf("\n");

    return 0;
}