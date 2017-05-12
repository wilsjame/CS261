#include <assert.h>
#include <stdlib.h>
#ifndef TYPE
#define TYPE int
#endif

int main(){

	return 0;

}

struct Node{
	TYPE value;
	struct Node *left;
	struct Node *right;
};

struct BinarySearchTree{
	struct Node *root;
	int size;
};

/* initialize */
void initBST(struct BinarySearchTree *tree){
	tree->size = 0;
	tree->root =  0;
}

/* internal add */
struct Node* _nodeAddBST(struct Node *current, TYPE newValue){
	
	if(current == 0){
		struct Node *returnMe = malloc(sizeof(struct Node));
		assert(returnMe != 0);

		returnMe->left = 0;
		returnMe->right = 0;
		returnMe->value = newValue;

		return returnMe;
	}
	else if(newValue < current->value){
		current->left = _nodeAddBST(current->left, newValue);
	}
	else{
		current->right = _nodeAddBST(current->right, newValue);
	}

	return current;

}

/* add */
void addBST(struct BinarySearchTree *tree, TYPE newValue){
	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}

/* size */
int sizeBST(struct BinarySearchTree *tree){

	return tree->size;

}

/* contains, return 1 if found and 0 otherwise */
int containsBST(struct BinarySearchTree *tree, TYPE d){
	assert(tree != 0);

	//create traverse
	struct Node *traverse;
	assert(traverse != 0);
	traverse = tree->root;

	while(traverse != 0){

		if(traverse->value == d){

			return 1;

		}
		else if(d > traverse->value){
			traverse = traverse->right;
		}
		else if(d < traverse->value){
			traverse = traverse->left;
		}

	}

	return 0;
}

/* internal left most */
TYPE _leftMostChild(struct Node *current){
	assert(current != 0);

	struct Node * holdLeft = current;
	assert(holdLeft != 0);

	while(holdLeft != 0){
		holdLeft = holdLeft->left;
	}

	return holdLeft->value;

}

/* internal remove left most */
struct Node* _removeLeftMostChild(struct Node *current){
	assert(current != 0);

	struct Node *returnMe;
	assert(returnMe != 0);

	if(current->left == 0){
		returnMe = current->right;
		free(current);

		return returnMe;

	}
	else{
		current->left = 
		_removeLeftMostChild(current->left);

		return current;

	}

}

/* internal remove */
struct Node* _nodeRemoveBST(struct Node *current, TYPE d){

	if(current->value == d){

		if(current->right == 0){

			return current->left;
		}
		else{
			current->value = _leftMostChild(current->right);
			current->right = _removeLeftMostChild(current->right);
		}

	}
	else if(d < current->value){
		current->left = _nodeRemoveBST(current->left, d);
	}
	else{
		current->right = _nodeRemoveBST(current->right, d);
	}

	return current;

}

/* remove */
void removeBST(struct BinarySearchTree *tree, TYPE d){

	if(containsBST(tree, d)){
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}

}
