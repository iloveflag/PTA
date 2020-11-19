#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct student* LStudent;
struct student{
	int number;
	char name[10];
	int store;
	LStudent next;
}; 

void PrintL(LStudent p);
LStudent add(LStudent *phead);
bool del(LStudent *phead);
LStudent sort_number(LStudent *phead);
LStudent sort_store(LStudent *phead);
void menu(int code,LStudent *phead);

int main(){
	LStudent head=NULL;
	int code=0;
	menu(code,&head);
}

void PrintL(LStudent p){
	printf("ѧ��     ����    ����\n"); 
	while(p!=NULL){
		printf("%d      ",p->number);
		printf("%s    ",p->name);
		printf("%d\n",p->store);
		p=p->next;
	}
}

LStudent add(LStudent *phead){ //β�巨 
	int number;
	char name[10];
	int store;
	LStudent tmp;
	LStudent p=(LStudent)malloc(sizeof(struct student));
	printf("ѧ��:");
	scanf("%d",&number);
	
	for(tmp=*phead;tmp!=NULL;tmp=tmp->next){
		if(tmp->number==number){
			printf("ѧ���ظ�������������\n");
			menu(0,phead);
		}
	}
	
	printf("����:");
	scanf("%s",name);
	printf("����:"); 
	scanf("%d",&store);
	p->number=number;
	strcpy(p->name,name);
	p->store=store;
	p->next=NULL;
	LStudent last=*phead;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}else{
		*phead=p;
	}		
}
bool del(LStudent *phead){
	int number;
	printf("ɾ��ѧ��Ϊ��������:");
	scanf("%d",&number);
	LStudent tmp,pre1,pre2;
	pre1=*phead;
	pre2=pre1->next;
	
	int flag=1; 
	for(tmp=*phead;tmp!=NULL;tmp=tmp->next){
		if(tmp->number==number){
			flag=0;
		}
	}
	if(flag){
		printf("�޴�ѧ�ţ�����������\n");
		menu(0,phead);
	}
	
	if(pre1->number==number){ //ɾ����һ������ 
		if(pre2==NULL){ //��һ������ 
			*phead=NULL;
		}else{
			*phead=pre2;
			free(pre1);
		}
		return true; 
	}
	while(pre2->number!=number){
		pre1=pre2;
		pre2=pre1->next;
	}
	if(pre1 ==NULL||pre2==NULL){
		printf("ɾ��λ�ò�������\n");
		menu(0,phead);
	}else{
		pre1->next=pre2->next;
		free(pre2);
		return true;
	} 
	
}
LStudent sort_number(LStudent *phead){ //�������� 
	LStudent tmp,tail;
	tail=NULL;
	tmp=*phead;
	while(tmp!=tail){
		while(tmp->next!=tail){
			if(tmp->number>tmp->next->number){
				int tmp_number=tmp->number;
				char tmp_name[10];
				strcpy(tmp_name,tmp->name);
				int tmp_store=tmp->store;
				
				tmp->number=tmp->next->number;
				tmp->next->number=tmp_number;
				
				strcpy(tmp->name,tmp->next->name);
				strcpy(tmp->next->name,tmp_name);
				
				tmp->store=tmp->next->store;
				tmp->next->store=tmp_store;
			}
			tmp=tmp->next;			
		}
		tail=tmp;
		tmp=*phead;
	} 
}
LStudent sort_store(LStudent *phead){ //�������� 
	LStudent tmp,tail;
	tail=NULL;
	tmp=*phead;
	while(tmp!=tail){
		while(tmp->next!=tail){
			if(tmp->store<
			tmp->next->store){
				int tmp_number=tmp->number;
				char tmp_name[10];
				strcpy(tmp_name,tmp->name);
				int tmp_store=tmp->store;
				
				tmp->number=tmp->next->number;
				tmp->next->number=tmp_number;
				
				strcpy(tmp->name,tmp->next->name);
				strcpy(tmp->next->name,tmp_name);
				
				tmp->store=tmp->next->store;
				tmp->next->store=tmp_store;
			}
			tmp=tmp->next;			
		}
		tail=tmp;
		tmp=*phead;
	} 
}
void menu(int code,LStudent *phead){
	int action;
	while(code==0){
		printf("------------��ӭ����ѧ���ɼ�����ϵͳ------------\n"); 
		printf("---------------------1.����---------------------\n"); 
		printf("---------------------2.�鿴---------------------\n");
		printf("---------------------3.ɾ��---------------------\n");
		printf("---------------------4.���---------------------\n");
		printf("------------------5.����ѧ������----------------\n");
		printf("------------------6.���ճɼ�����----------------\n");
		printf("----------------------��ѡ��:-------------------\n");
		scanf("%d",&action);
		if(action==1){
			add(phead);
		}else if(action==2){
			PrintL(*phead);
		}else if(action==3){
			if(del(phead)){
				printf("ɾ���ɹ�!\n");
			}
		}else if(action==4){
			*phead=NULL;
			printf("��ճɹ���\n");
		}else if(action==5){
			sort_number(phead);
		}else if(action==6){
			sort_store(phead);
		}else{
			code=1;
		}	
	}
}

