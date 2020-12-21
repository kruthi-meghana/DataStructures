/*80.given a single linked list, remove all odd valued elements*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int value;
	Node* link;
};

struct Node* form_linked_list(int number);

struct Node* form_linked_list(int number){
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = number;
	root->link = NULL;
	return root;
}

void display_linked_list(Node* root){
	printf("Linked list :\n");
	while (root != NULL){
		printf("%d ", root->value);
		root = root->link;
		if (root != NULL)
			printf("->");
	}
}

struct Node* remove_odd_linked_list(Node* root){
	if (root == NULL)
		return NULL;
	if ((root->value) % 2 == 0){
		root->link = remove_odd_linked_list(root->link);
		return root;
	}
	else{
		return remove_odd_linked_list(root->link);
	}
}

void main(){
	Node* node1 = form_linked_list(121);
	Node* node2 = form_linked_list(32);
	Node* node3 = form_linked_list(90);
	Node* node4 = form_linked_list(76);
	Node* node5 = form_linked_list(23);
	Node* node6 = form_linked_list(10);
	Node* node7 = form_linked_list(108);
	Node* node8 = form_linked_list(66);
	node1->link = node2;
	node2->link = node3;
	node3->link = node4;
	node4->link = node5;
	node5->link = node6;
	node6->link = node7;
	node7->link = node8;
	node8->link = NULL;
	node1 = remove_odd_linked_list(node1);
	display_linked_list(node1);
	_getch();
}