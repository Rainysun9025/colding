#include <stdio.h>

// 全局变量：在整个程序中都能访问
int n;                    // 输入的n值
int selected[20];         // 存储当前已选择的数字
int cnt;                  // 记录当前已选择的数字个数

// 深度优先搜索函数
void dfs(int cur) {
    // 递归终止条件：已经考虑完1~n所有数字
    if (cur > n) {
        // 输出当前方案
        for (int i = 0; i < cnt; i++) {
            printf("%d ", selected[i]);
        }
        printf("\n");
        return;  // 结束当前递归分支
    }
    
    // 分支1：不选当前数字cur
    dfs(cur + 1);
    
    // 分支2：选当前数字cur
    selected[cnt++] = cur;  // 选择cur，加入数组
    dfs(cur + 1);           // 继续考虑下一个数字
    cnt--;                  // 回溯：撤销选择
}

int main() {
    // 读入n
    scanf("%d", &n);
    
    // 从数字1开始深度优先搜索
    dfs(1);
    
    return 0;
}
