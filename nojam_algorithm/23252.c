#include <stdio.h>
int n,i;
long long int A,B,C;
int main(){
	scanf("%d",&n);//입력 받음
	for(i=0;i<n;i++){//입력받은 횟수만큼 함
		scanf("%lld %lld %lld",&A,&B,&C);//long long
		
		if(A>=C && !((A-C)&1)){// a=1 c=3 =4 
			if(B&1){// 공간 2 차지 하는 b 1개일때 
				if((A&&C)||A-C>=2){//b를 채워줌 3 2 1 
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
			else{//b가 2개면 걍 없는거랑 마찬가지 안될꺼면 위에서 이미 걸러짐
				printf("Yes\n");
			}
		}
		else{
			printf("No\n");
		}
	}
	return 0;
	
}