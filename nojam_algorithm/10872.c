#include <stdio.h>
int main(){
	int n=0,i=0,sum=1;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		sum = sum * i;
	}
	printf("%d",sum);
	
	return 0;
} 
