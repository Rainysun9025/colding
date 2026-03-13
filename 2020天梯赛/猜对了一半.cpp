#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10
#define MAX_M 100

int n, m;  // 运动员人数，观众人数
int found = 0;  // 是否找到解
int first_solution = 1;  // 是否为第一个解（用于控制输出格式）

// 存储观众预测的数据结构
// predictions[i][0][0]: 观众i的第一个预测的运动员编号
// predictions[i][0][1]: 观众i的第一个预测的名次
// predictions[i][1][0]: 观众i的第二个预测的运动员编号
// predictions[i][1][1]: 观众i的第二个预测的名次
int predictions[MAX_M][2][2];

// 运动员的实际名次，rank[运动员编号] = 名次
int rank[MAX_N + 1];

// 名次是否已被使用，used[名次] = 1表示该名次已被分配
int used[MAX_N + 1];

// 记录每个观众的两个预测是否已经确定
// determined[i][0]: 观众i的第一个预测是否已确定
// determined[i][1]: 观众i的第二个预测是否已确定
int determined[MAX_M][2];

// 记录每个观众已经猜对的数量
int correct_count[MAX_M];

// 检查当前部分分配是否违反观众条件
bool check_partial() {
    for (int i = 0; i < m; i++) {
        // 获取观众i的两个预测
        int athlete1 = predictions[i][0][0];
        int pred_rank1 = predictions[i][0][1];
        int athlete2 = predictions[i][1][0];
        int pred_rank2 = predictions[i][1][1];
        
        // 只有当两个运动员都分配了名次时，才能检查这个观众的条件
        if (rank[athlete1] != 0 && rank[athlete2] != 0) {
            int correct = 0;
            if (rank[athlete1] == pred_rank1) correct++;
            if (rank[athlete2] == pred_rank2) correct++;
            
            // 如果两个预测都确定了，但猜对的数量不是1，则违反条件
            if (correct != 1) {
                return false;
            }
        }
        // 如果一个或两个运动员还没有分配名次，无法判断，继续检查下一个观众
    }
    return true;
}

// 深度优先搜索函数
// idx: 当前正在分配名次的运动员编号
void dfs(int idx) {
    // 递归终止条件：所有运动员都已分配名次
    if (idx > n) {
        // 验证是否满足所有观众的条件
        for (int i = 0; i < m; i++) {
            int correct = 0;
            int athlete1 = predictions[i][0][0];
            int pred_rank1 = predictions[i][0][1];
            int athlete2 = predictions[i][1][0];
            int pred_rank2 = predictions[i][1][1];
            
            if (rank[athlete1] == pred_rank1) correct++;
            if (rank[athlete2] == pred_rank2) correct++;
            
            // 每个观众必须恰好猜对一个
            if (correct != 1) {
                return;  // 不满足条件，直接返回
            }
        }
        
        // 找到一个合法解
        found = 1;
        
        // 输出结果（按字典序）
        if (!first_solution) {
            printf("\n");  // 如果不是第一个解，先换行
        }
        first_solution = 0;
        
        for (int i = 1; i <= n; i++) {
            if (i > 1) printf(" ");
            printf("%d", rank[i]);
        }
        
        return;
    }
    
    // 尝试为当前运动员分配所有可能的名次
    for (int r = 1; r <= n; r++) {
        // 如果名次r还没有被使用
        if (!used[r]) {
            // 做选择：为运动员idx分配名次r
            rank[idx] = r;
            used[r] = 1;
            
            // 检查部分分配是否违反条件
            if (check_partial()) {
                // 继续为下一个运动员分配名次
                dfs(idx + 1);
            }
            
            // 回溯：撤销选择
            used[r] = 0;
            rank[idx] = 0;
        }
    }
}

int main() {
    // 输入运动员人数和观众人数
    scanf("%d %d", &n, &m);
    
    // 初始化
    for (int i = 1; i <= n; i++) {
        rank[i] = 0;  // 初始时运动员没有名次
        used[i] = 0;  // 初始时所有名次都未被使用
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            determined[i][j] = 0;
        }
        correct_count[i] = 0;
    }
    
    // 读取观众的预测
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        // 存储第一个预测
        predictions[i][0][0] = a;  // 运动员编号
        predictions[i][0][1] = b;  // 预测名次
        
        // 存储第二个预测
        predictions[i][1][0] = c;  // 运动员编号
        predictions[i][1][1] = d;  // 预测名次
    }
    
    // 从第1号运动员开始进行深度优先搜索
    dfs(1);
    
    // 如果没有找到任何解
    if (!found) {
        printf("None\n");
    }
    
    return 0;
}
