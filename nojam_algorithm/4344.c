#include <stdio.h>
int m,n,i,j,k,l,sum;
double ratio,average;
int main(){
	scanf("%d",&m);
	for(l=0;l<m;l++){
		scanf("%d",&n);
		int studentAry[1000]={};
		
		for(i=0;i<n;i++){
			scanf("%d",&studentAry[i]);
			sum += studentAry[i];
			//printf("sum = %d\n",sum);
		}
		average = (sum/n);// 나중에 안되면 평균값을 double로 
		//printf("average = %d\n",average);
		for(i=0;i<n;i++){
			if(studentAry[i] > average){
				ratio++;
			}
		}
		printf("%.3lf%%\n",((ratio/n)*100));
		//printf("%d %d %d ",ratio,n);
		ratio =0; average =0; sum =0;
	}
}