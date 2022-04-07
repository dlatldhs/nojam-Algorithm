
#include <stdio.h>
double sum,objects[1000],max;
int n,i;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&objects[i]);
		if( objects[i]>max){
			max = objects[i];
			//printf("max : %d\n",max);
		}
	}
	for(i=0;i<n;i++){
		//printf("objects[i] : %d",objects[i]);
		sum += ((objects[i]/max)*100);
		//printf("sum : %lf",sum);
	}
	printf("%lf",sum/n);
	return 0;
}
