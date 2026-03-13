#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int s[100005];

int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for(int i = 1; i <= n; i++) s[i] = s[i] + s[i - 1];  // 计算前缀和
    
    int ans = -1e8;
    dq.push_back(0);
    
    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && dq.front() < i - m) dq.pop_front();  // 队头超出m范围则弹出
        ans = max(ans, s[i] - s[dq.front()]);  // 队头对应最小前缀和，计算当前最大子数组和
        while(!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();  // 维护单调递增队列
        dq.push_back(i);
    }
    
    printf("%d\n", ans);
    return 0;
}

