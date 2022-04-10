long long sum(int *a, int n) {// a = ary n = 정수 개수
	long long ans = 0;
    int i=0;
    for (i=0;i<n;i++){
        ans += a[i];
    }
    
	return ans;
}

