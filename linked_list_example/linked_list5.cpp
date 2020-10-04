//linked_list function
#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node *next;
}Node;

void Printf(Node * n);
Node* add(Node **pHead,int number);

int main(){
	Node *head=NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number!=-1){
			add(&head,number);
		}
	}while(number !=-1);
	Printf(head);
}

void Printf(Node * n){
	while(n!=NULL){
		printf("%d",n->data);
		n=n->next;
	}
}

Node* add(Node **pHead,int number){
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=number;
	p->next=NULL;  
	Node *last = *pHead;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}else{
		*pHead=p;
	}	
}
