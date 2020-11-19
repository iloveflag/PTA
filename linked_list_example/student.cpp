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
	printf("学号     姓名    分数\n"); 
	while(p!=NULL){
		printf("%d      ",p->number);
		printf("%s    ",p->name);
		printf("%d\n",p->store);
		p=p->next;
	}
}

LStudent add(LStudent *phead){ //尾插法 
	int number;
	char name[10];
	int store;
	LStudent tmp;
	LStudent p=(LStudent)malloc(sizeof(struct student));
	printf("学号:");
	scanf("%d",&number);
	
	for(tmp=*phead;tmp!=NULL;tmp=tmp->next){
		if(tmp->number==number){
			printf("学号重复！请重新输入\n");
			menu(0,phead);
		}
	}
	
	printf("姓名:");
	scanf("%s",name);
	printf("分数:"); 
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
	printf("删除学号为几的数据:");
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
		printf("无此学号！请重新输入\n");
		menu(0,phead);
	}
	
	if(pre1->number==number){ //删除第一条数据 
		if(pre2==NULL){ //就一条数据 
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
		printf("删除位置参数错误\n");
		menu(0,phead);
	}else{
		pre1->next=pre2->next;
		free(pre2);
		return true;
	} 
	
}
LStudent sort_number(LStudent *phead){ //链表排序 
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
LStudent sort_store(LStudent *phead){ //链表排序 
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
		printf("------------欢迎来到学生成绩管理系统------------\n"); 
		printf("---------------------1.插入---------------------\n"); 
		printf("---------------------2.查看---------------------\n");
		printf("---------------------3.删除---------------------\n");
		printf("---------------------4.清空---------------------\n");
		printf("------------------5.按照学号排序----------------\n");
		printf("------------------6.按照成绩排序----------------\n");
		printf("----------------------请选择:-------------------\n");
		scanf("%d",&action);
		if(action==1){
			add(phead);
		}else if(action==2){
			PrintL(*phead);
		}else if(action==3){
			if(del(phead)){
				printf("删除成功!\n");
			}
		}else if(action==4){
			*phead=NULL;
			printf("清空成功！\n");
		}else if(action==5){
			sort_number(phead);
		}else if(action==6){
			sort_store(phead);
		}else{
			code=1;
		}	
	}
}

