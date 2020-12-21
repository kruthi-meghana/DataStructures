/*74. given a single linked list which has two digits in each node, convert that to a string (first node has msb). 
example 12->34->56->78 should output as "12345678"*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int value;
	Node* link;
};

struct Node* form_linked_list(int number);

char* convert_into_string(Node* root){
	char* converted_list = (char*)malloc(sizeof(char) * 20);
	int index = 0;
	while (root != NULL){
		int number = root->value;
		converted_list[index++] = number / 10 + '0';
		converted_list[index++] = number % 10 + '0';
		root = root->link;
	}
	converted_list[index] = '\0';
	return converted_list;
}

struct Node* form_linked_list(int number){
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = number;
	root->link = NULL;
	return root;
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
	printf("%s", convert_into_string(node1));
	_getch();
}