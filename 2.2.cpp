//02-���Խṹ2 һԪ����ʽ�ĳ˷���ӷ�����
#include <stdio.h>
#include <stdlib.h>
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1

//15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
//5 20 -4 4 -5 2 9 1 -2 0
//1	ͬ����ϲ�ʱ�е���	��ʽ���� 0	3 ms	256 KB
//2	ϵ����ָ��ȡ���ޣ�����������ʽ	�𰸴��� 0	2 ms	256 KB
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
			head=p; //ͷ�ڵ���������ڴ�ռ䣬=NULL��Ч ,����headָ���һ���¼ӵĽڵ� 
			last=head; //��head��ֵ����lastָ�� 
		}
	}
	return head;
}
List multiplication(List L1,List L2){
	List head_L1=L1;
	List head_L2=L2;
	List last,head=NULL;
	last=head;
	while(L2!=NULL){ //��L2����,L1�ƶ� 
		while(L1!=NULL){
			int flag=0;
			List rst=(List)malloc(sizeof(struct LNode));	
			rst->exp=(L1->exp)+(L2->exp);
			rst->ratio=(L1->ratio)*(L2->ratio);
			rst->next=NULL;
			if(last){
				//�ϲ�ͬ���� 
				List Same=head; //��ͷ��ʼ�� 
				while(Same){
					if(Same->exp==rst->exp){
						Same->ratio=Same->ratio+rst->ratio;
						flag=1;
						break;
					}
					Same=Same->next;
				} 
				if(flag==1){ //�ҵ�ͬ����L1���ƣ���һ��ѭ�� 
					L1=L1->next;
					continue;
				}
				//����
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
		L1=head_L1; //L1ͷ�ڵ㸴ԭ 
		L2=L2->next;
	}
	return head;
}
List sum(List L1,List L2){ //����ʽ��� 
	List last,head=NULL;
	last=head;
	while(L1!=NULL && L2!=NULL){
		int flag=0;
		List rst=(List)malloc(sizeof(struct LNode)); 	//�¼ӵĽڵ��ڴ�Ҫ��while����,��Ȼ���ڴ��ַ����
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


//��ָͬ��������ֻ�����ǵĶ��0.�� 2 3 0 2 0
	List last1=head;
	List pos=NULL;
	int flag=0;
	while(last1!=NULL){
		if(last1->exp==0){
			flag=flag+1;
			if(flag==1){
				pos=last1; //��һ�γ���0��λ�� 
			}
			
		}
		last1=last1->next;
	} 
	if(flag>1){ //���0��β 
		List last2=pos->next; //��һ�γ���0��λ�õ���һ�� 
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
		printf("%d %d",L->ratio,L->exp); //ֻ��һ����ϵ��Ϊ0.���0 0 
		exit(0); 
	}
	while(L!= NULL){
		if(L->ratio==0){	//ϵ��Ϊ0�����	
			L=L->next;
			continue;
		}
		printf("%d ",L->ratio);
		
		if(L->next==NULL){ //���һ�����ӿո� 
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
	//pass �����������ʽ�ͳ�������ʽ
	//����һ���������ʽ����ô�������ʽ������һ����Ϊ��Ķ���ʽ;
	//�����������ʽ���������ʽ����ô�������ʽҲΪ�����ʽ��
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
