//02-线性结构2 一元多项式的乘法与加法运算
//第一个节点为空的情况 数据插入 
#include <stdio.h>
#include <stdlib.h>
// 4 1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
typedef struct LNode{
	int ratio; //系数 
	int exp; //指数 
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
			last->next=p; //尾插法 
		}else{
			head->next=p; //头节点必须申请内存空间，=NULL无效 ,这里head指向第一个新加的节点 
			last=head; //先head赋值，后last指向 
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
