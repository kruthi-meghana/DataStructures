/*78.sort a linked list of 0's,1's and 2's.*/


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
	Node* last_node = root;
	int count_of_zeros = 0, count_of_ones = 0, count_of_twos = 0;
	while (last_node != NULL){
		if (last_node->value == 0)
			count_of_zeros += 1;
		else if (last_node->value == 1)
			count_of_ones += 1;
		else if (last_node->value == 2)
			count_of_twos += 1;
		last_node = last_node->link;
	}
	last_node = root;
	while (root != NULL){
		if (count_of_zeros != 0){
			root->value = 0;
			count_of_zeros -= 1;
		}
		else if (count_of_ones != 0){
			root->value = 1;
			count_of_ones -= 1;
		}else if (count_of_twos != 0){
			root->value = 2;
			count_of_twos -= 1;
		}
		root = root->link;
	}
	return last_node;
}

void main(){
	Node* node1 = form_linked_list(2);
	Node* node2 = form_linked_list(0);
	Node* node3 = form_linked_list(2);
	Node* node4 = form_linked_list(2);
	Node* node5 = form_linked_list(0);
	Node* node6 = form_linked_list(1);
	Node* node7 = form_linked_list(1);
	Node* node8 = form_linked_list(0);
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