//01-���Ӷ�2	Maximum Subsequence Sum 
#include <stdio.h>
#define MaxArray 100000 
void MaxSubseqSum(int k_array[],int k){
	int ThisSum,MaxSum=0;
	int i,j,Position_start,Position_stop;
	for(i=0;i<k;i++){
		ThisSum=0; 
		for(j=i;j<k;j++){
			ThisSum=ThisSum+k_array[j];
			if(ThisSum>MaxSum){
				MaxSum=ThisSum;
				Position_start=i;
				Position_stop=j;
			}else if(ThisSum==MaxSum){ //��0����� 
			//���������кͶ�Ӧ��ͬi���ǲ�ͬj����β��0��
			//��ʱ���ǵ��ĸ�Ԫ�ظ����پ�ȡ�ĸ���
			//�����Ͳ���Ҫ�仯λ���� 
				if(MaxSum==0){ //������0 
					Position_start=Position_stop=j;
				} 
			}
		} 
	} 
	printf("%d ",MaxSum);
	printf("%d ",k_array[Position_start]);
	printf("%d",k_array[Position_stop]);
} 
void NegativeNumbers(int k_array[],int k){
	int Negative=0; 
	for(int i=0;i<k;i++){
		if(k_array[i]<0){
			Negative=Negative+1; 
		} 
	} 
	if(Negative==k){
		printf("0 %d %d",k_array[0],k_array[k-1]); 
	}else{
		MaxSubseqSum(k_array,k); 
	} 	
}

int main(){
	int k; 
	int k_array[MaxArray]; 
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&k_array[i]); 
	} 
	NegativeNumbers(k_array,k); 
} 
