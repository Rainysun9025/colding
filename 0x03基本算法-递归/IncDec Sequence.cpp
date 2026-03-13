#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long long a, prev;
    scanf("%lld", &prev); // 读入a[1]
    
    long long pos_sum = 0, neg_sum = 0;
    
    // 计算差分并统计正负和
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &a);
        long long diff = a - prev;
        if (diff > 0) {
            pos_sum += diff;
        } else if (diff < 0) {
            neg_sum -= diff; // 注意：neg_sum是绝对值
        }
        prev = a;
    }
    
    // 计算最少操作次数
    long long ans1 = pos_sum > neg_sum ? pos_sum : neg_sum;
    
    // 计算最终结果种数
    long long delta = pos_sum - neg_sum;
    if (delta < 0) delta = -delta;
    long long ans2 = delta + 1;
    
    printf("%lld\n%lld\n", ans1, ans2);
    
    return 0;
}
