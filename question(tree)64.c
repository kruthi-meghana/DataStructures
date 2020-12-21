/*64.Given a tree fill up each of its nodes with balance values.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Node* createNodes(int num);

int inorder(Node * root);


struct Node{
	int value;
	Node* left;
	Node* right;
};

int inorder(Node * root){
	if (root == NULL) return -1;
	int hLeft = inorder(root->left);
	int hRight = inorder(root->right);
	printf("balance of : node %d is :", root->value);
	root->value = hLeft - hRight;
	printf("%d\n", root->value);
	return 1 + (hLeft > hRight ? hLeft : hRight);
}

struct Node* createNodes(int num){

	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->value = num;
	return node;
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
	root->value = inorder(root);
	_getch();
}