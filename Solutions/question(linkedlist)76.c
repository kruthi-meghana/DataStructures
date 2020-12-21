/*76.given a single linked list, remove every Kth node in the linked list. 
example: 1->2->3->4->5 and K 2, output is 1->3->5*/

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

struct Node* remove_Kth_node(Node* root, int kth_value,int count){
	if (root == NULL)
		return root;
	if (count == kth_value){
		return remove_Kth_node(root->link, kth_value,1);
	}
	else{
		root->link = remove_Kth_node(root->link, kth_value,++count);
		return root;
	}
}

void main(){
	Node* node1 = form_linked_list(12);
	Node* node2 = form_linked_list(34);
	Node* node3 = form_linked_list(56);
	Node* node4 = form_linked_list(78);
	Node* node5 = form_linked_list(90);
	Node* node6 = form_linked_list(89);
	Node* node7 = form_linked_list(90);
	Node* node8 = form_linked_list(90);
	node1->link = node2;
	node2->link = node3;
	node3->link = node4;
	node4->link = node5;
	node5->link = node6;
	node6->link = node7;
	node7->link = node8;
	node8->link = NULL;
	node1 = remove_Kth_node(node1,2,1);
	display_linked_list(node1);
	_getch();
}