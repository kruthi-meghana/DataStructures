/*73.given a number convert that to single linked listeach digit as a node*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct Node{
	int value;
	Node* link;
};
void display_linked_list(Node*);
struct Node* form_linked_list(int number);
void display_linked_list(Node* root){
	printf("Linked list :\n");
	while (root != NULL){
		printf("%d ", root->value);
		root = root->link;
		if (root != NULL)
			printf("->");
	}
}
struct Node* form_linked_list(int number){
	Node* root = (Node*)malloc(sizeof(Node));
	root = NULL;
	while (number != 0){
		Node*  temp = (Node*)malloc(sizeof(Node));
		temp->value = number % 10;
		temp->link = root;
		root = temp;
		number /= 10;
	}
	return root;
}

void main(){
	int number;
	printf("Enter your number :");
	scanf("%d", &number);
	Node* root = form_linked_list(number);
	display_linked_list(root);
	_getch();
}
