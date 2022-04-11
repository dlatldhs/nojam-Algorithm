#include <stdio.h>
int n,k,i,l,p=10;
int n1[10];
char a[5][11];
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	k=0;
        scanf("%s %d",a[i],&k);
        if(k<p){
            p=k;
            l=i;
        }
        if(i==n-1){
        	printf("%s",a[l]);
		}
    }
    return 0;
}
