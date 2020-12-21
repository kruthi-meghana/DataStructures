/*72.Given a binary search tree print in-order, pre-order, post-order traversals of the tree*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

struct Node* createNodes(int);
void inorderTraversal(Node*);
void preorderTraversal(Node*);
void postorderTraversal(Node*);

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

void inorderTraversal(Node* root){
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d \t", root->value);
	inorderTraversal(root->right);
	
}
void preorderTraversal(Node* root){
	if (root == NULL)
		return;
	printf("%d \t", root->value);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}
void postorderTraversal(Node* root){
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d \t", root->value);

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
	printf("Inorder traversal :\n");
	inorderTraversal(root);
	printf("\nPre-Order traversal :\n");
	preorderTraversal(root);
	printf("\nPost-Order traversal :\n");
	postorderTraversal(root);
	_getch();
}
