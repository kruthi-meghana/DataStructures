/*66.Fill up each node of tree with weight of the node's subtree.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node* createNodes(int num);
void postorder(Node * root, void(visit)(Node*));
void visit(Node* n);

struct Node{
	int value;
	Node* left;
	Node* right;
};

struct Node* createNodes(int num){

	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->value = num;
	return node;
}
void myPrint(Node* n){
	printf("%d \n", n->value);
}

void visit(Node* n){
	n->value = 1;
	if (n->left != NULL)
		n->value += (n->left)->value;
	if (n->right != NULL)
		n->right += (n->right)->value;
	myPrint(n);
}

void postorder(Node * root, void(visit)(Node*))
{
	if (root == NULL) return;

	postorder(root->left, visit);
	postorder(root->right, visit);
	visit(root);
}

void main(){
	Node* n10 = createNodes(10);
	Node* n20 = createNodes(20);
	Node* n30 = createNodes(30);
	Node* n40 = createNodes(40);
	Node* n50 = createNodes(50);

	n10->left = n20;
	n10->right = n40;
	n20->right = n30;
	n30->right = n50;
	Node* root = n10;
	postorder(root, visit);
	_getch();
}