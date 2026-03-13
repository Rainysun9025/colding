#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> G[MAXN];
int vis[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {    // 修正：m 条边
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        vis[i] = 1;
        q.push({i, 0});
        int cnt = 1; // 包含自身

        while (!q.empty()) {
            int u = q.front().first;   // 传统方式
            int d = q.front().second;
            q.pop();
            if (d >= 6) continue;
            for (int v : G[u]) {
                if (!vis[v]) {          // 修正：未访问才处理
                    vis[v] = 1;
                    cnt++;
                    q.push({v, d + 1});
                }
            }
        }
        printf("%d: %.2f%%\n", i, cnt * 100.0 / n);
    }
    return 0;
}
