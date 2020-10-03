#include <stdio.h>
#include <stdlib.h>
typedef struct LNode *List;
struct LNode{
	int data;
	int date;
};


int main(){
	List L = (List)malloc(sizeof(struct LNode)); 
	L->data=80;
	L->date=90;
	printf("%d %d",L->data,L->date);
}
