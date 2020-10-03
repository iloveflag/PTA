//01-复杂度1 最大子列和问题
#include <stdio.h>
#define MaxArray 100000 
int MaxSubseqSum(int k_array[],int k){
	int ThisSum,MaxSum=0;
	int i,j;
	for(i=0;i<k;i++){
		ThisSum=0; 
		for(j=i;j<k;j++){
			ThisSum=ThisSum+k_array[j];
			if(ThisSum>MaxSum){
				MaxSum=ThisSum; 
			} 
		} 
	} 
	printf("%d",MaxSum); 
} 
int NegativeNumbers(int k_array[],int k){
	int Negative=0; 
	for(int i=0;i<k;i++){
		if(k_array[i]<0){
			Negative=Negative+1; 
		} 
	} 
	if(Negative==k){
		printf("0"); 
	}else{
		MaxSubseqSum(k_array,k); 
	} 	
}

main(){
	int k; 
	int k_array[MaxArray]; 
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&k_array[i]); 
	} 
	NegativeNumbers(k_array,k); 
} 
