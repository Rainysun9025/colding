#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200005;
const ll INF = (1LL << 31) - 1;  // 最大可能位置 2^31-1

int T, N;
ll S[MAXN], E[MAXN], D[MAXN];

// 计算从 0 到位置 x（包含 x）的防具总数
ll count(ll x) {
    ll total = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] <= x) {                     // 该组起点在 x 之前
            ll last = min(E[i], x);          // 该组在 x 之前的最后一个防具位置
            total += (last - S[i]) / D[i] + 1; // 该组在 [S[i], last] 内的防具数量
        }
    }
    return total;
}

void solve() {
    // 先判断总防具数是否为奇数
    if (count(INF) % 2 == 0) {
        cout << "There's no weakness.\n";
        return;
    }

    // 二分查找第一个使前缀和为奇数的位置
    ll left = 0, right = INF;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (count(mid) % 2 == 1)
            right = mid;      // 奇数位置在 mid 或左边
        else
            left = mid + 1;    // 奇数位置在右边
    }

    ll pos = left;
    ll cnt = count(pos) - count(pos - 1);  // 该位置的防具数量
    cout << pos << " " << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> S[i] >> E[i] >> D[i];
        }
        solve();
    }
    return 0;
}
