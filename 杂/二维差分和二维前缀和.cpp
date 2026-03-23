#include <bits/stdc++.h>
using namespace std;

// 二维差分修改函数：对子矩阵 (x1,y1) 到 (x2,y2) 增加 val
void change(vector<vector<int>>& diff, int x1, int y1, int x2, int y2, int val) {
    int n = diff.size();
    int m = diff[0].size();
    diff[x1][y1] += val;
    if (x2 + 1 < n) diff[x2 + 1][y1] -= val;
    if (y2 + 1 < m) diff[x1][y2 + 1] -= val;
    if (x2 + 1 < n && y2 + 1 < m) diff[x2 + 1][y2 + 1] += val;
}

// 从二维差分数组还原出原数组
vector<vector<int>> restoreFromDiff(vector<vector<int>>& diff, int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    a[0][0] = diff[0][0];
    for (int i = 1; i < n; ++i) a[i][0] = a[i-1][0] + diff[i][0];
    for (int j = 1; j < m; ++j) a[0][j] = a[0][j-1] + diff[0][j];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + diff[i][j];
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    // 1. 构建二维差分数组 diff
   vector<vector<int>> diff(n, vector<int>(m));
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        diff[i][j] = arr[i][j] 
                   - (i ? arr[i-1][j] : 0) 
                   - (j ? arr[i][j-1] : 0) 
                   + (i && j ? arr[i-1][j-1] : 0);
    }
}
    // 2. 进行几次区间修改（示例：将 (1,1) 到 (2,2) 子矩阵加 5）
    change(diff, 1, 1, 2, 2, 5);

    // 3. 从修改后的 diff 还原出新数组
    vector<vector<int>> newArr = restoreFromDiff(diff, n, m);

    // 4. 输出结果（验证）
    cout << "Original array:\n";
    for (auto& row : arr) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "Modified array:\n";
    for (auto& row : newArr) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
