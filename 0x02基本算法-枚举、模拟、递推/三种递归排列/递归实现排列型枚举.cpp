#include <stdio.h>

int n;
int path[10];      // 存储当前排列
int used[10];      // 标记数字是否已使用

void dfs(int u) {
    if (u == n) {  // 已经填完n个位置
        for (int i = 0; i < n; i++) {
            printf("%d", path[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {        // 如果数字i还没用过
            path[u] = i;       // 将i放入当前位置
            used[i] = 1;       // 标记i已使用
            dfs(u + 1);        // 递归处理下一个位置
            used[i] = 0;       // 回溯，恢复现场
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);  // 从第0个位置开始
    return 0;
}
