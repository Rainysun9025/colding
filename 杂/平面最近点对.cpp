#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200010;
const double INF = 1e20;

struct Point {
    double x, y;
} a[N], b[N];

// 按 x 坐标排序，若相等则按 y 排序
bool cmpx(const Point &p, const Point &q) {
    return p.x == q.x ? p.y < q.y : p.x < q.x;
}

// 按 y 坐标排序
bool cmpy(const Point &p, const Point &q) {
    return p.y < q.y;
}

// 计算两点间欧几里得距离
double dis(const Point &p, const Point &q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

// 分治求解区间 [l, r] 的最小点对距离
double solve(int l, int r) {
    if (l == r) return INF;                // 只有一个点，距离为无穷大
    if (l + 1 == r) return dis(a[l], a[r]); // 只有两个点，直接计算

    int m = (l + r) >> 1;
    double d = min(solve(l, m), solve(m + 1, r));

    // 收集带状区域内的点（横坐标与中线距离小于 d）
    int k = 0;
    for (int i = l; i <= r; ++i) {
        if (fabs(a[i].x - a[m].x) < d) {
            b[++k] = a[i];
        }
    }
    // 按 y 坐标排序
    sort(b + 1, b + k + 1, cmpy);

    // 检查带状区域内的点对
    for (int i = 1; i <= k; ++i) {
        // 只需检查后续 y 坐标差小于 d 的点
        for (int j = i + 1; j <= k && b[j].y - b[i].y < d; ++j) {
            d = min(d, dis(b[i], b[j]));
        }
    }
    return d;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1, cmpx);           // 预处理按 x 排序
    double ans = solve(1, n);
    printf("%.4lf\n", ans);
    return 0;
}
