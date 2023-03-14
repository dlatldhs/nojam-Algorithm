# greedy( 그리디 ) 알고리즘


## 1.그리디 알고리즘
```c
#include <stdio.h>
int i,n,k,cnt,money[5]= {500,100,50,10};

int grid( int n )
{
	for ( i = 0 ; n != 0 ; i++ ) 
	{
		cnt += n / money[i];
		n = n % money[i];
		//printf("%d %d\n",cnt,n);
	}
	
	return cnt;
}

int main() {
	
	int sum=0;
	scanf("%d",&n);
	sum = grid(n);
	printf("%d",sum);
	
	return 0;
}
```

## 2. 큰 수의 법칙
```c
#include <stdio.h>
int n[3],max1,max2,i,l,m[10000];

int big_number( int m1, int m2 , int m , int k )
{
	int cnt=0,sum=0;
	for ( int i=0; i < m; i++ ) // m = 8 , 0 ~ 7
	{
		if ( 3 > cnt ) {
			sum += m1;
			cnt++;
			// printf("%d",cnt);
			// printf("%d\n",sum);
		} else {
			sum += m2;
			cnt = 0;
			// printf("%d\n",sum);
		}
	}
	
	return sum;
}

int main() {
	int result;
	scanf("%d %d %d",&n[0],&n[1],&n[2]);
	
	for ( i = 0; i < n[0] ; i++ )
	{
		scanf("%d",&m[i]);
	  // printf("%d",m[i]);
		if ( m[i] > max1 ) // 0 -> 2 -> 4 -> 5 -> 4x -> 6
		{
			max1 = m[i];
			// printf("%d\n",max1);
		}
	}
	
	for ( i = 0; i < n[0] ; i++ )
	{
		if ( max1 > m[i] && m[i] >max2 )
		{
			max2 = m[i];
		}
	}
	// printf("%d %d",max1,max2);
	result = big_number(max1,max2,n[1],n[2]);
	// printf("%d %d %d",n[0],n[1],n[2]);
	printf("%d",result);
	return 0;
}
```

## 3. 숫자 카드 게임
```c
#include <stdio.h>
int n , m ;
int ary[100][100];
int min_ary[100];
void set_card( int n , int m )
{
	int min=10000;
	
	for ( int i = 0 ; i < n ; i++ ) 
	{
		for ( int k = 0 ; k < m ; k++ )
		{
			scanf("%d",&ary[i][k]);
			// printf("%d",ary[i][k]);
			if ( min > ary[i][k] )
			{
				min_ary[i] = ary[i][k];
				min = ary[i][k];
				// printf("[ min_ary : %d ] ",min_ary[i]);
			}
			// printf("%d min: %d ",ary[i][k],min);
		}
		// printf("\n");
		min = 10000;
		// printf("\n");a
	}
	
	// printf("%d",min);
}

int find_card( void )
{
	int max = 0;
	for ( int i = 0 ; i < n ; i++ )
	{
		max = min_ary[i];
	}
	return max;
}

int main() {
	int result;
	scanf("%d %d",&n ,&m );
	
	set_card( n , m );
	result = find_card();
	printf("%d",result);
	// printf("%d %d",n,m);
	
	return 0;
}
```

## 4. 1이 될 때까지
```c
#include <stdio.h>
int n , k , cnt ;
int make_one( int n , int k )
{
	for ( int i = 0 ; n != 1 ; i++ )
	{
		n--;
		// printf("%d : %d ",i,n);
		
		if ( n == 1 )
		{
			return cnt;
		}
		
		else if ( n/k == 0 ) // n이 k로 나눠지지 않을 때
		{
			cnt++;
			// printf("NO\n");
			continue;
		} 
		
		else
		{
			n = n/k;
			// printf("%d : %d\n",i,n);
			cnt++;
		}
		// printf("%d",cnt); // 1 3 
	}
}

int main()
{
	
	int result;
	scanf("%d %d",&n,&k);
	
	result = make_one( n , k );
	printf("%d",result-1);
	
	return 0;
}
```
