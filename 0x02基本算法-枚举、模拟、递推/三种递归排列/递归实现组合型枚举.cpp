#include <stdio.h>

int n, m;
int combination[30];  // 存储当前组合

// 递归生成组合
void dfs(int start, int depth) {
    // 如果已经选了m个数，输出当前组合
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            printf("%d", combination[i]);
            if (i < m - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    
    // 从start开始选择数字，确保组合是升序且不重复
    for (int i = start; i <= n; i++) {
        combination[depth] = i;  // 选择当前数字
        dfs(i + 1, depth + 1);   // 递归选择下一个数字
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    // 从第一个位置开始递归生成组合
    dfs(1, 0);
    
    return 0;
}
