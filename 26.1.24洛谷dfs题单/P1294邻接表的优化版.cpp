#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<bool> vis;
int ans = -1e9;   // 极小值，处理负权边

void dfs(int u, int sum) {
    ans = max(ans, sum);          // 每个节点都可作为终点
    for (int i = 0; i < (int)graph[u].size(); ++i) {
        int v = graph[u][i].first;
        int w = graph[u][i].second;
        if (!vis[v]) {
            vis[v] = true;
            dfs(v, sum + w);
            vis[v] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);   // 无向边，双向添加
    }

    vis.assign(n + 1, false);
    for (int start = 1; start <= n; ++start) {
        vis[start] = true;
        dfs(start, 0);
        vis[start] = false;
    }

    if (m == 0) ans = 0;   // 无边时路径长度为0
    cout << ans << endl;

    return 0;
}