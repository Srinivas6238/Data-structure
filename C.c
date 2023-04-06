#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *root = NULL;

node *create_node(char *name) {
    node *new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, char *name) {
    if (root == NULL) {
        root = create_node(name);
    }
    else if (strcmp(name, root->name) < 0) {
        root->left = insert_node(root->left, name);
    }
    else {
        root->right = insert_node(root->right, name);
    }
    return root;
}

node *delete_node(node *root, char *name) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        root->left = delete_node(root->left, name);
    }
    else if (strcmp(name, root->name) > 0) {
        root->right = delete_node(root->right, name);
    }
    else {
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        strcpy(root->name, temp->name);
        root->right = delete_node(root->right, temp->name);
    }
    return root;
}

node *search_node(node *root, char *name) {
    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search_node(root->left, name);
    }
    return search_node(root->right, name);
}

void traverse(node *root, int mode) {
    if (root == NULL) {
        return;
    }
    if (mode == 1) {
        printf("%s\n", root->name);
    }
    traverse(root->left, mode);
    if (mode == 2) {
        printf("%s\n", root->name);
    }
    traverse(root->right, mode);
    if (mode == 3) {
        printf("%s\n", root->name);
    }
}

void print_tree(node *root, int level) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%s\n", root->name);
    print_tree(root->left, level + 1);
}

int main() {
    int choice;
    char name[50];
    node *temp;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Print Tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                scanf("%s", name);
                root = insert_node(root, name);
                printf("%s inserted.\n", name);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                temp = search_node(root, name);
                if (temp != NULL) {
                    root = delete_node(root, name);
                    printf("%s deleted.\n", name);
                }
                else {
                    printf("%s not found.\n", name);
                }
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                temp = search_node(root, name);
                if (temp != NULL) {
                    printf("%s found.\n", name);
                }
                else {
                    printf("%s not found.\n", name);
                }
                break;
            case 4:
                printf("1. Pre-order\n");
                printf("2. In-order\n");
                printf("3. Post-order\n");
                printf("Enter traversal mode: ");
                scanf("%d", &choice);
                traverse(root, choice);
                break;
            case 5:
                printf("Directory Structure:\n");
                print_tree(root, 0);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        
        }
}
    return 0;

}
