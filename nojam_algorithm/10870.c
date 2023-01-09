# 피보나치 숭려
```c:10870.c
#include <stdio.h>

int fibonachi(int n) {
    if (n >= 2){
        return fibonachi(n-1) + fibonachi(n-2);
    }
    else if ( n == 1 ) return 1;
    else return 0;
}

int main () {
    int n;
    scanf("%d",&n);
    printf("%d\n",fibonachi(n));
}
```
