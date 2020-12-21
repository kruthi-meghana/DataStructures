/*70.Find common ancestor ofany random tree*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node* createNodes(int num);
void commonAncestors(Node*, int, int);
bool findEle(Node*, int);

struct Node{
	int value;
	Node* left;
	Node* right;
};

int one[20], two[20]; int ind = 0;

struct Node* createNodes(int num){

	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->value = num;
	return node;
}

bool findEle(Node* root, int element){
	if (root == NULL)return false;
	if (root->value == element)return true;
	if (root->value < element)
		findEle(root->right, element);
	else
		findEle(root->left, element);
}

void find(int arr[20], int b[20], int ind, int ind1){
	for (int i = ind; i >= 0; i--){
		for (int j = ind1; j >= 0; j--){
			if (arr[i] == b[j]){
				printf("%d", arr[i]);
				return;
			}
		}
	}
}

/*	if (root){
if (root->value == ele)
return;
else{
one[ind++] = root->value;
commonAncestors(root->left, ele);
commonAncestors(root->right, ele);
if (root -> right == NULL)
one[--ind] = 0;
}
}
return;*/
void commonAncestors(Node* root, int ele, int ele1){
	if (root == NULL)return;
	if ((ele < root->value) && (ele1 > root->value) || (ele > root->value) && (ele1 < root->value)){
		printf("successful root is : %d \n", root->value);
		return;
	}
	if ((ele < root->value) && (ele1 < root->value))
		commonAncestors(root->left, ele, ele1);
	else
		commonAncestors(root->left, ele, ele1);
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

	int ele = 15, ele1 = 45;
	if (findEle(root, ele) && findEle(root, ele1))
		commonAncestors(root, ele, ele1);
	else
		printf("given nodes are not available");

	getchar();
}