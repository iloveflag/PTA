//linked_list function for best
#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node *next;
}Node;

typedef struct _list{
	Node* head;
	//Node* tail;
}List;

void Printf(List * pList);
void add(List* pList,int number);

int main(){
	List list;
	int number;
	list.head = NULL;
	do{
		scanf("%d",&number);
		if(number!=-1){
			add(&list,number);
		}
	}while(number !=-1);
	Printf(&list);
}

void Printf(List * pList){
	Node* p;
	for(p=pList->head;p;p=p->next){
		printf("%d\t",p->data);
	}
}

void add(List* pList,int number){ // &list == pList list.head==pList->head 
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=number;
	p->next=NULL;  
	Node *last = pList->head;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}else{
		pList->head=p;
	}	
}
