#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int mask[16];          // 16 个操作对应的掩码
int dist[1 << 16];     // 到达每个状态的最少步数，-1 表示未访问
int pre[1 << 16];      // 前驱状态
int op[1 << 16];       // 从 pre 到达当前状态所用的操作编号（0~15）

// 预处理所有掩码
void initMask() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx = i * 4 + j;      // 当前操作对应的位索引
            int m = 0;
            // 第 i 行所有列
            for (int c = 0; c < 4; ++c) {
                int pos = i * 4 + c;
                m |= 1 << pos;
            }
            // 第 j 列所有行
            for (int r = 0; r < 4; ++r) {
                int pos = r * 4 + j;
                m |= 1 << pos;
            }
            mask[idx] = m;
        }
    }
}

int main() {
    initMask();

    // 读取初始状态并转换为整数（0 表示开，1 表示关）
    int start = 0;
    for (int i = 0; i < 4; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < 4; ++j) {
            if (line[j] == '+') {          // 关闭状态记为 1
                int pos = i * 4 + j;
                start |= 1 << pos;
            }
        }
    }

    // BFS 初始化
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 0) break;                  // 到达目标状态（全开）

        for (int i = 0; i < 16; ++i) {
            int v = u ^ mask[i];             // 应用操作 i
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pre[v] = u;
                op[v] = i;
                q.push(v);
            }
        }
    }

    // 回溯路径：从目标状态 0 倒推到起始状态
    vector<int> path;
    int cur = 0;
    while (cur != start) {
        path.push_back(op[cur]);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());       // 反转得到正确顺序

    // 输出结果
    cout << path.size() << endl;
    for (int idx : path) {
        int r = idx / 4 + 1;                  // 转换为 1-based 行号
        int c = idx % 4 + 1;                  // 转换为 1-based 列号
        cout << r << " " << c << endl;
    }

    return 0;
}
