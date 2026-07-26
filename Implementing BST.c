#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Inorder traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}




int main() {
    struct Node* root = NULL;
    int choice, value;
    
    while (1) {
        printf("\n\n===== Binary Search Tree Operations =====\n");
        printf("1. Insert a node\n");
        printf("2. Display Tree (All Traversals)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
                
            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("\n----- Tree Traversals -----\n");
                    printf("Inorder Traversal:   ");
                    inorder(root);
                    printf("\nPreorder Traversal:  ");
                    preorder(root);
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
                
            case 3:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
