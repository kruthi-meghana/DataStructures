/*68.Delete all nodes of a given tree.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node* createNodes(int);
void postOrder(Node*);
void visit(Node*);

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

void visit(Node* root){
	free(root);
}

void postOrder(Node* root, void(*visit)(Node*)){
	if (root == NULL)return;

	postOrder(root->left, visit);
	postOrder(root->right, visit);
	visit(root);
}

void main(){
	Node* n1 = createNodes(60);
	Node* n2 = createNodes(30);
	Node* n3 = createNodes(80);
	Node* n4 = createNodes(15);
	Node* n5 = createNodes(45);
	Node* n6 = createNodes(70);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	Node* root = n1;
	int arr[2] = { 0 };
	postOrder(root, visit);
	printf("Successfully deleted all nodes");
	_getch();
}
