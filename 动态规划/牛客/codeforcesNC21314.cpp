#include <stdio.h>
 
// 定义题目结构
 
struct Problem {
 
    long long ma;  // 最大分数
 
    long long pm;  // 每分钟减少的分数
 
    long long re;  // 需要的时间
 
};
 
// 取最大值函数
 
long long max(long long a, long long b) {
 
    return a > b ? a : b;
 
}
 
int main() {
 
    int N, T;
 
    scanf("%d %d", &N, &T);
 
     
 
    struct Problem nc[55];
 
     
 
    // 读取输入
 
    for(int i = 0; i < N; i++) scanf("%lld", &nc[i].ma);
 
    for(int i = 0; i < N; i++) scanf("%lld", &nc[i].pm);
 
    for(int i = 0; i < N; i++) scanf("%lld", &nc[i].re);
 
     
 
    // 按优先级排序：pm/re 从大到小
 
    for(int i = 0; i < N-1; i++) {
 
        for(int j = 0; j < N-i-1; j++) {
 
            double ratio1 = nc[j].pm * 1.0 / nc[j].re;
 
            double ratio2 = nc[j+1].pm * 1.0 / nc[j+1].re;
 
            if(ratio1 < ratio2) {
 
                // 交换题目
 
                struct Problem temp = nc[j];
 
                nc[j] = nc[j+1];
 
                nc[j+1] = temp;
 
            }
 
        }
 
    }
 
     
 
    // dp数组，初始化为0
 
    long long dp[100005] = {0};
 
    long long ans = 0;
 
     
 
    // 01背包动态规划
 
    for(int i = 0; i < N; i++) {
 
        for(int j = T; j >= nc[i].re; j--) {
 
            // 状态转移
 
            long long new_score = dp[j - nc[i].re] + nc[i].ma - nc[i].pm * j;
 
            if(new_score > dp[j]) {
 
                dp[j] = new_score;
 
            }
 
            // 更新最大答案
 
            if(dp[j] > ans) {
 
                ans = dp[j];
 
            }
 
        }
 
    }
 
     
 
    printf("%lld\n", ans);
 
    return 0;
 
}
