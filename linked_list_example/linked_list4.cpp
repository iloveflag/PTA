#include <stdio.h>
#include <stdlib.h> 
typedef struct Node * List;
struct Node{
	int data;
	List next;
}; 
int main(){
	List L=(List)malloc(sizeof(struct Node));
	L->data=10;
	L->next=NULL;
	printf("%d",L->data);
}
