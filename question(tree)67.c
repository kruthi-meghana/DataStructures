/*67.Given a tree determine if it is a standard binary search tree or not.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

struct Node* createNodes(int);
void traversal(Node*, int, int);
int flag = 0;

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


int traversal(Node* root){
	if (flag == -1)
		return -1;
	if (root == NULL)
		return NULL;
	int value = traversal(root->left);
	if (value != NULL){
		if (value > root->value){
			printf("Not a Binary search tree");
			flag = -1;
			return -1;
		}	
	}
	value = traversal(root->right);
	if (flag == -1)
		return -1;
	if (value != NULL){
		if (value < root->value){
			printf("Not a Binary search tree");
		}	
	}
	else
		return root->value;
	return value;
}

void main(){
	Node* n1 = createNodes(60);
	Node* n2 = createNodes(30);
	Node* n3 = createNodes(80);
	Node* n4 = createNodes(15);
	Node* n5 = createNodes(64);
	Node* n6 = createNodes(70);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	Node* root = n1;
	traversal(root);
	if (flag == 0)
		printf("It is a binary search tree");
	_getch();
}
