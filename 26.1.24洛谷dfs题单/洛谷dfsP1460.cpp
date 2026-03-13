#include <stdio.h>
#include <string.h>

int n, g;
int need[30];
int feed[20][30];
int best_count = 20;  // 最优解的饲料数量
int best_choice[20];  // 最优解的饲料编号
int current_count = 0;  // 当前选择的饲料数量
int current_choice[20];  // 当前选择的饲料编号

// 检查是否满足需求
int check_satisfy(int *have) {
    for (int i = 0; i < n; i++) {
        if (have[i] < need[i]) {
            return 0;
        }
    }
    return 1;
}

void dfs(int idx, int *have) {
    // 剪枝：如果当前选择的饲料数量已经大于等于最优解，直接返回
    if (current_count >= best_count) {
        return;
    }
    
    // 如果已经考虑了所有饲料（使用 >= 更安全）
    if (idx >= g) {
        if (check_satisfy(have)) {
            // 如果找到更优解（饲料数量更少）
            if (current_count < best_count) {
                best_count = current_count;
                for (int i = 0; i < current_count; i++) {
                    best_choice[i] = current_choice[i];
                }
            }
        }
        return;
    }
    
    // 选择当前饲料
    for (int i = 0; i < n; i++) {
        have[i] += feed[idx][i];
    }
    current_choice[current_count] = idx + 1;  // 饲料编号从1开始
    current_count++;
    
    // 递归搜索选择当前饲料的情况
    dfs(idx + 1, have);
    
    // 回溯：不选当前饲料
    current_count--;
    for (int i = 0; i < n; i++) {
        have[i] -= feed[idx][i];
    }
    
    // 递归搜索不选当前饲料的情况
    dfs(idx + 1, have);
}

int main() {
    scanf("%d", &n);
    int have[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &need[i]);
        have[i] = 0;
    }
    
    scanf("%d", &g);
    
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &feed[i][j]);
        }
    }
    
    dfs(0, have);
    
    // 输出结果
    printf("%d", best_count);
    for (int i = 0; i < best_count; i++) {
        printf(" %d", best_choice[i]);
    }
    printf("\n");
    
    return 0;
}
