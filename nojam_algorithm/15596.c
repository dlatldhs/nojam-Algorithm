long long sum(int *a, int n) {// a = ary n = ���� ����
	long long ans = 0;
    int i=0;
    for (i=0;i<n;i++){
        ans += a[i];
    }
    
	return ans;
}

