/*75.given a linked list, swap using pointers every two nodes a->b->c->d->e should become b->a->d->c->e*/

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

struct Node* swap(Node* root){
	Node* node1 = root;
	while (root != NULL){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp = root->link;
		if (temp == NULL)
			return node1;
		int value = root->value;
		root->value = temp->value;
		temp->value = value;
		root = temp->link;
	}
}

void main(){
	Node* node1 = form_linked_list(12);
	Node* node2 = form_linked_list(34);
	Node* node3 = form_linked_list(56);
	Node* node4 = form_linked_list(78);
	Node* node5 = form_linked_list(90);
	node1->link = node2;
	node2->link = node3;
	node3->link = node4;
	node4->link = node5;
	node1 = swap(node1);
	display_linked_list(node1);
	_getch();
}