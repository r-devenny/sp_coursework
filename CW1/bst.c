#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
	int value;
	struct node_t *right;
	struct node_t *left;
} node_t;

node_t * search(node_t * node, int toFind);
node_t * createTree(int firstElem);
void destroyTree(node_t * node);
void insert(node_t * node, int elem);
void delete(node_t * node, int elem);

node_t * createTree(int firstElem){
	node_t *root = (node_t*)malloc(sizeof(node_t));

	if (root == NULL){
		return NULL;
	}

	root -> value = firstElem;
	root -> left = NULL;
	root -> right = NULL;

	return root;
}

node_t * search(node_t * node, int toFind){
	
	if (node == NULL || node -> value == toFind){
		return node;
	}else if (toFind < node->value){
		return search(node->left, toFind);
	}
	else{
		return search(node->right, toFind);
	}

}

void insert(node_t * node, int elem){

	while (true){
		if (elem < node -> value){
			// Traverse left subtree of node
			if (node -> left == NULL){
				//insert new node
				node->left = createTree(elem);
				break;
			}else{
				// Move left
				node = node->left;
			}
		} else if (elem > node->value){
			//Traverse right subtree
			if (node -> right == NULL){
				//insert new node
				node -> right = createTree(elem);
				break;
			}else{
				// Move right
				node = node -> right;
			}
		}
		
		else{
				//duplicate, break
				break;
		}
	}
}

void destroyTree(node_t * node){

	// Base Case - reached leaf
	if(node == NULL){
			return;
	}
	
	destroyTree(node->left);
	destroyTree(node->right);
	free(node);
}

node_t *find_min(node_t *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void delete(node_t *node, int elem) {
    node_t *parent = NULL;  // temp to track the parent node
    node_t *current = node;

    // Search for the node to delete and its parent
    while (current != NULL && current->value != elem) {
        parent = current;
        if (elem < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was not found, return
    if (current == NULL) {
        return;
    }

    // Node to be deleted is a leaf node
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            // If no parent, we are at the root
            free(current);
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    // Node has one child
    else if (current->left == NULL || current->right == NULL) {
        node_t *child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) {
            *node = *child;
            free(child);
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    // Node has two children
    else {
        node_t *successor = find_min(current->right);
        int successorValue = successor->value;
        delete(node, successorValue); // Recursively delete the successor
        current->value = successorValue;
    }
}




	






