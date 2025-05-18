#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int host_id;
    struct TreeNode* children[10];
    int child_count;
} TreeNode;
TreeNode* createNode(int host_id) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->host_id = host_id;
    newNode->child_count = 0;
    for (int i = 0; i < 10; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}
void addChild(TreeNode* parent, TreeNode* child) {
    if (parent->child_count < 10) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Warning: Maximum children reached for host %d\n", parent->host_id);
    }
}
void printTree(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("Host %d\n", root->host_id);
    for (int i = 0; i < root->child_count; i++) {
        printTree(root->children[i], level + 1);
    }
}
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->child_count; i++) {
        freeTree(root->children[i]);
    }
    free(root);
}
int main() {
    TreeNode* root = createNode(0);
    addChild(root, createNode(1));
    addChild(root, createNode(2));
    addChild(root->children[0], createNode(3));
    addChild(root->children[0], createNode(4));
    addChild(root->children[1], createNode(5));
    addChild(root->children[0]->children[0], createNode(6));
    printf("Broadcast Tree:\n");
    printTree(root, 0);
    freeTree(root);
    return 0;
}
