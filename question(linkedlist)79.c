/*79.given an unsorted single linked list, sort the linked list without using extra array or linked list*/

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

struct Node* sort_linked_list(Node* root){
	Node* last_node;
	Node* node1 = root;
	while (root != NULL){
		last_node = root->link;
		while (last_node != NULL){
			if (root->value > last_node->value){
				int swap = root->value;
				root->value  = last_node->value;
				last_node->value = swap;
			}
			last_node = last_node->link;
		}
		root = root->link;
	}
	return node1;
}

void main(){
	Node* node1 = form_linked_list(12);
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
	node1 = sort_linked_list(node1);
	display_linked_list(node1);
	_getch();
}