//02-���Խṹ2 һԪ����ʽ�ĳ˷���ӷ�����
//��һ���ڵ�Ϊ�յ���� ���ݲ��� 
#include <stdio.h>
#include <stdlib.h>
// 4 1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
typedef struct LNode{
	int ratio; //ϵ�� 
	int exp; //ָ�� 
	struct LNode *next;
}*List;

List read(List head){
	int n,ratio=0,exp=0;
	List last=head;
	scanf("%d",&n); 
	while(n--){	
		List p=(List)malloc(sizeof(struct LNode));
		scanf("%d",&ratio);
		scanf("%d",&exp);
		p->ratio=ratio;	
		p->exp=exp;
		p->next=NULL;
		if(last){
			while(last->next){
				last=last->next;
			}
			last->next=p; //β�巨 
		}else{
			head->next=p; //ͷ�ڵ���������ڴ�ռ䣬=NULL��Ч ,����headָ���һ���¼ӵĽڵ� 
			last=head; //��head��ֵ����lastָ�� 
		}
	}
	return head;
}
void print(List L){
	L=L->next;
	while(L!= NULL){
		printf("%d",L->ratio);
		printf("%d",L->exp);
		L=L->next;
	}
}
int main(){
	List L1,L2,L=NULL;
	//make empty node 
	L1=(List)malloc(sizeof(struct LNode));
	L1->next=NULL;
	L=read(L1);
	print(L);
}
