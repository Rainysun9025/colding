// 前缀和优化版本
#include <stdio.h>

int main() {
    long long n, q;
    scanf("%lld %lld", &n, &q);
    
    long long a[n];
    long long prefix[n+1];  // 前缀和数组
    
    prefix[0] = 0;
    for(long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        prefix[i+1] = prefix[i] + a[i];
    }
    
    for(long long i = 0; i < q; i++) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        // 直接使用前缀和计算区间和
        printf("%lld\n", prefix[r] - prefix[l-1]);
    }
    
    return 0;
}
