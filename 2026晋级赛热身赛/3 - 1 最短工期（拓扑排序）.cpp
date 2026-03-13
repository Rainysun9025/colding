#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // 项目里程碑的数量（节点数）
    int m; // 任务的数量（边数）
    cin >> n >> m;

    // graph[u] 存储从节点 u 出发的所有任务，每个任务用 pair<int,int> 表示 (终点, 时长)
    vector<vector<pair<int, int>>> graph(n);
    
    // indeg[v] 表示节点 v 的入度，即有多少个任务以 v 为终点
    vector<int> indeg(n, 0);

    // 读入 m 个任务
    for (int i = 0; i < m; ++i) {
        int u;      // 任务起始里程碑
        int v;      // 任务结束里程碑
        int w;      // 任务工作时长
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); // 添加一条有向边
        indeg[v]++;                   // 终点入度加1
    }

    // dist[v] 表示从起点 0 到达里程碑 v 的最早可能时间（即最长路径长度）
    // 初始化为 -1 表示尚未到达
    vector<int> dist(n, -1);
    dist[0] = 0; // 起点里程碑 0 在时刻 0 已经完成

    queue<int> q; // 拓扑排序用的队列，存放当前入度为 0 的节点
    // 将所有入度为 0 的节点入队（包括起点 0 和可能出现的孤立节点）
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0; // 记录已经处理（从队列中弹出）的节点个数，用于检测环
    while (!q.empty()) {
        int u = q.front(); // 当前处理的节点 u
        q.pop();
        cnt++; // 已处理节点数加1

        // 使用传统 for 循环遍历节点 u 的所有出边（任务）
        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;  // 任务终点
            int w = graph[u][i].second; // 任务时长

            // 只有节点 u 是可达的，才能用它更新后继节点 v
            if (dist[u] != -1) {
                // 更新 v 的最早时间：取当前值 与 u 的时间加上任务时长 中的较大者
                dist[v] = max(dist[v], dist[u] + w);
            }
            // 将 v 的入度减1，因为已经处理了一条指向 v 的边
            indeg[v]--;
            // 如果 v 的入度变为 0，说明它的所有前驱都已处理完毕，可以入队
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // 判断结果：
    // 1. 如果处理的节点数不等于总节点数（cnt != n），说明存在环，无法完成拓扑排序
    // 2. 如果终点 n-1 的 dist 仍为 -1，说明从起点无法到达终点
    if (cnt != n || dist[n - 1] == -1) {
        cout << "Impossible" << endl;
    } else {
        // 否则输出终点最早完成时间
        cout << dist[n - 1] << endl;
    }

    return 0;
}
