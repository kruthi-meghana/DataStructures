/*69.Find the max child count of the given binary tree(0 or 1 or 2).*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node* createNodes(int);
void child_count(Node*);
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

void child_count(Node* root){
	if (root == NULL)
		return;
	int childCount = 0;
	if (root->left != NULL)
		childCount += 1;
	if (root->right != NULL)
		childCount += 1;
	printf("%d is the child count of %d \n", childCount, root->value);

	child_count(root->left);
	child_count(root->right);
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
	child_count(root);
	_getch();
}
