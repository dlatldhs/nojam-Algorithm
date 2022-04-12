#include <stdio.h>
int main(){
	int n=0;int back =0;int j=0;
	char ary[80]={};
	int i=0; int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
 		scanf("%s",ary);
//		printf("%s",ary);
//		printf("%c",ary[3]);
		for(j=0;ary[j];j++){
			if(ary[j] == 'O'){
				sum +=1+back++;
			}
			else{
				back=0;
			}
		}
		printf("%d\n",sum);
		back=0;
		sum =0;
	}
	
	return 0;
} 
