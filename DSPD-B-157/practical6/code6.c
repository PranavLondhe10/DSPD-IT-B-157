#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void search(struct Node* root, int key) {
    if(root == NULL) {
        printf("NULL\n");
        return;
    }
    if(root->data == key) {
        printf("Found\n");
        return;
    }
    if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if(root == NULL)
        return NULL;
    if(key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if(key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            printf("Leaf node %d deleted.\n", key);
            return NULL;
        } else {
            printf("Node %d is not a leaf, cannot delete.\n", key);
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while(1) {
        printf("\n BST MENU \n");
        printf("1. Search Element\n");
        printf("2. Insert Element\n");
        printf("3. Delete Leaf Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &key);
                root = deleteLeaf(root, key);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}