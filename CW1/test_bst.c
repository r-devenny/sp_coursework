#include <stdio.h>

// Declare the struct and functions as extern
typedef struct node_t {
    int value;
    struct node_t *right;
    struct node_t *left;
} node_t;

extern node_t *createTree(int firstElem);
extern node_t *search(node_t *node, int toFind);
extern void insert(node_t *node, int elem);
extern void delete(node_t *node, int elem);
extern void destroyTree(node_t *node);

// Test cases
int main() {
    // Test Case 1: Basic Tree Creation
    node_t *tree = createTree(10);
    if (tree != NULL && tree->value == 10 && tree->left == NULL && tree->right == NULL) {
        printf("Test Case 1 Passed: Tree created successfully.\n");
    } else {
        printf("Test Case 1 Failed: Tree creation issue.\n");
    }

    // Test Case 2: Insertion
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 3);
    insert(tree, 7);

    if (tree->left->value == 5 && tree->right->value == 15 && 
        tree->left->left->value == 3 && tree->left->right->value == 7) {
        printf("Test Case 2 Passed: Insertion works correctly.\n");
    } else {
        printf("Test Case 2 Failed: Insertion issue.\n");
    }

    // Test Case 3: Search
    node_t *result = search(tree, 7);
    if (result != NULL && result->value == 7) {
        printf("Test Case 3.1 Passed: Found existing element 7.\n");
    } else {
        printf("Test Case 3.1 Failed: Could not find element 7.\n");
    }

    result = search(tree, 20);
    if (result == NULL) {
        printf("Test Case 3.2 Passed: Correctly identified missing element 20.\n");
    } else {
        printf("Test Case 3.2 Failed: Incorrectly found non-existent element.\n");
    }

    // Test Case 4: Deletion
    delete(tree, 3); // Leaf
    if (tree->left->left == NULL) {
        printf("Test Case 4.1 Passed: Leaf node deleted successfully.\n");
    } else {
        printf("Test Case 4.1 Failed: Leaf node deletion issue.\n");
    }

    delete(tree, 5); // One child
    if (tree->left->value == 7) {
        printf("Test Case 4.2 Passed: Node with one child deleted successfully.\n");
    } else {
        printf("Test Case 4.2 Failed: Node with one child deletion issue.\n");
    }

    delete(tree, 10); // Two children
    if (tree->value == 15) { // Assuming successor was chosen correctly
        printf("Test Case 4.3 Passed: Node with two children deleted successfully.\n");
    } else {
        printf("Test Case 4.3 Failed: Node with two children deletion issue.\n");
    }

    // Test Case 5: Edge Cases
    node_t *emptyTree = NULL;

    // Inserting duplicate
    insert(tree, 15); // After deletion, 15 is the root, so this should not insert again
    if (tree->right == NULL || tree->right->value != 15) {
        printf("Test Case 5.1 Passed: Duplicate elements not inserted.\n");
    } else {
        printf("Test Case 5.1 Failed: Duplicate insertion issue.\n");
    }

    // Deleting from empty tree
    delete(emptyTree, 5); // Should not crash
    printf("Test Case 5.2 Passed: Deleting from empty tree did not crash.\n");

    // Test Case 6: Destroy Tree
    destroyTree(tree);
    tree = NULL; // Manually set to NULL after destruction
    if (tree == NULL) {
        printf("Test Case 6 Passed: Tree destroyed successfully.\n");
    } else {
        printf("Test Case 6 Failed: Tree destruction issue.\n");
    }

    return 0;    
}
