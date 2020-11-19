//02-线性结构2 一元多项式的乘法与加法运算
#include <stdio.h>
#include <stdlib.h>
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1

//15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
//5 20 -4 4 -5 2 9 1 -2 0
//1	同类项合并时有抵消	格式错误 0	3 ms	256 KB
//2	系数和指数取上限，结果有零多项式	答案错误 0	2 ms	256 KB
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
			head=p; //头节点必须申请内存空间，=NULL无效 ,这里head指向第一个新加的节点 
			last=head; //先head赋值，后last指向 
		}
	}
	return head;
}
List multiplication(List L1,List L2){
	List head_L1=L1;
	List head_L2=L2;
	List last,head=NULL;
	last=head;
	while(L2!=NULL){ //先L2不动,L1移动 
		while(L1!=NULL){
			int flag=0;
			List rst=(List)malloc(sizeof(struct LNode));	
			rst->exp=(L1->exp)+(L2->exp);
			rst->ratio=(L1->ratio)*(L2->ratio);
			rst->next=NULL;
			if(last){
				//合并同类项 
				List Same=head; //从头开始找 
				while(Same){
					if(Same->exp==rst->exp){
						Same->ratio=Same->ratio+rst->ratio;
						flag=1;
						break;
					}
					Same=Same->next;
				} 
				if(flag==1){ //找到同类项L1后移，下一个循环 
					L1=L1->next;
					continue;
				}
				//结束
				while(last->next){
					last=last->next;
				}
				last->next=rst;
			}else{
				head=rst;
				last=head;
			}
			L1=L1->next;
		}
		L1=head_L1; //L1头节点复原 
		L2=L2->next;
	}
	return head;
}
List sum(List L1,List L2){ //多项式相加 
	List last,head=NULL;
	last=head;
	while(L1!=NULL && L2!=NULL){
		int flag=0;
		List rst=(List)malloc(sizeof(struct LNode)); 	//新加的节点内存要在while里面,不然他内存地址不变
		if((L1->exp)>(L2->exp)){
			rst->ratio=L1->ratio;
			rst->exp=L1->exp;
			rst->next=NULL;
			if(last){
				while(last->next){
					last=last->next;
				}
				last->next=rst;
			}else{
				head=rst;
				last=head;
			}
			L1=L1->next;
		}else if((L1->exp)<(L2->exp)){
			rst->ratio=L2->ratio;
			rst->exp=L2->exp;
			rst->next=NULL;
			if(last){
				while(last->next){
					last=last->next;
				}
				last->next=rst;
			}else{
				head=rst;
				last=head;
			}
			L2=L2->next;
		}else{
			rst->ratio=L1->ratio+L2->ratio;
			rst->exp=L1->exp;
			rst->next=NULL; 
			if(last){
				while(last->next){
					last=last->next;
				}
				last->next=rst;
			}else{
				head=rst;
				last=head;
			}
			L1=L1->next;
			L2=L2->next;	
		}
	}
	//last node attach
	if(L1!=NULL){
		List rst=(List)malloc(sizeof(struct LNode)); 
		rst->exp=L1->exp;
		rst->ratio=L1->ratio;
		rst->next=NULL;
		while(last->next){
			last=last->next;
		}
		last->next=rst;
	}
	if(L2!=NULL){
		List rst=(List)malloc(sizeof(struct LNode)); 
		rst->exp=L2->exp;
		rst->ratio=L2->ratio;
		rst->next=NULL;
		while(last->next){
			last=last->next;
		}
		last->next=rst;
	}


//相同指数，这里只有弱智的多个0.如 2 3 0 2 0
	List last1=head;
	List pos=NULL;
	int flag=0;
	while(last1!=NULL){
		if(last1->exp==0){
			flag=flag+1;
			if(flag==1){
				pos=last1; //第一次出现0的位置 
			}
			
		}
		last1=last1->next;
	} 
	if(flag>1){ //多个0结尾 
		List last2=pos->next; //第一次出现0的位置的下一个 
		while(last2!=NULL){
			pos->ratio=pos->ratio+last2->ratio; 
			last2=last2->next;
		}
		pos->next=NULL;
	}
	return head;
}
void print(List L){
	if(L->next==NULL && L->ratio==0){
		L->exp=0;
		printf("%d %d",L->ratio,L->exp); //只有一项且系数为0.输出0 0 
		exit(0); 
	}
	while(L!= NULL){
		if(L->ratio==0){	//系数为0不输出	
			L=L->next;
			continue;
		}
		printf("%d ",L->ratio);
		
		if(L->next==NULL){ //最后一个不加空格 
			printf("%d",L->exp);
		}else{
			printf("%d ",L->exp);
		}
		L=L->next;
	}
}
int main(){
	List L1,L2,head1,head2,head=NULL;
	head1=read(L1);
	head2=read(L2);
	//pass 输入有零多项式和常数多项式
	//如有一个是零多项式，那么结果多项式就是另一个不为零的多项式;
	//如果两个多项式都是零多项式，那么结果多项式也为零多项式。
	//0                 0
	//1 2 1             0
	if(head1==NULL && head2==NULL){
		printf("0 0\n");
		printf("0 0\n");
		exit(0);
	}else if(head1==NULL){ 
		printf("0 0\n");
		print(head2);
		exit(0);
	}else if(head2==NULL){  
		printf("0 0\n");
		print(head1);
		exit(0);		
	}
	head=multiplication(head1,head2); 
	print(head);
	printf("\n");
	head=sum(head1,head2);
	print(head);
}
