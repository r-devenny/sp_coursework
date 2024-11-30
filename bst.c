#include <stdlib.h>

typedef struct {
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
	}
	
	if (toFind < node->value){
		return search(node->left, toFind);
	}
	else{
		return search(node->right, toFind);
	}

}







