// A simple C program to introduce 
// a linked list 
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next; 
}Node;

int main(){
	Node *head = NULL; //Node = struct _node
	Node *second=NULL;
	Node *third =NULL; 
	
	//malloc
	head=(Node *)malloc(sizeof(struct _node)); //(Node *)=(struct _node *)  necessary malloc
	second=(Node *)malloc(sizeof(struct _node));
	third=(Node *)malloc(sizeof(struct _node)); 
	
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	return 0; 
} 
