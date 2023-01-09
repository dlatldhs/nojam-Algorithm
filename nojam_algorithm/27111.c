#include <stdio.h>
int n,i,k,l,j,a[200000],b,sum[200000],val;
int main() {
    scanf("%d",&n);
    for (i=0; i < n; i++ )
    {
        scanf("%d %d",&a[i],&b);
        printf("%d",a[i]);
        if ( sum[ a[i] ]%2 == 1 ) // 출입하는 사람의 번호의 배열안에 값이 1일 때
        {
            if ( (sum[ a[i] ]+b)%2 == 0 ) // 값이 1인곳에 값을 받은 값을 더해서 %2해서 값이 0이면
            {
                val++; // check
                sum[a[i]] = b; // 값 넣음 => 2
            }
            else if ( (sum[ a[i] ]+b)%2 == 1 )
            {
                sum[a[i]]--; // 값을 지워버림 => 0
            }
        }
        else if( sum[ a[i] ]%2 == 0 )
        {
            if ( (sum[ a[i] ]+b)%2 == 0 ) //
            {
                sum[a[i]]++;
                
            }
        }
    }
    
    
    return 0;
}
