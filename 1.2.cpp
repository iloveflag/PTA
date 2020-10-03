//01-复杂度2	Maximum Subsequence Sum 
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
			}else if(ThisSum==MaxSum){ //有0的情况 
			//当两个并列和对应相同i但是不同j，即尾是0，
			//这时考虑的哪个元素个数少就取哪个。
			//这样就不需要变化位置了 
				if(MaxSum==0){ //负数和0 
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
