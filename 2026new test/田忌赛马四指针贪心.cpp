#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> tj(n), qw(n);
    for (int i = 0; i < n; ++i) cin >> tj[i];
    for (int i = 0; i < n; ++i) cin >> qw[i];
    sort(tj.begin(), tj.end());
    sort(qw.begin(), qw.end());
    int l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1, ans = 0;
    while (l1 <= r1) {
        if (tj[l1] > qw[l2]) {          // 最慢能赢最慢
            ++ans;
            ++l1; ++l2;
        } else if (tj[l1] < qw[l2]) {   // 最慢输给最快
            --ans;
            ++l1; --r2;
        } else {                         // 最慢相等
            if (tj[r1] > qw[r2]) {       // 最快能赢最快
                ++ans;
                --r1; --r2;
            } else {                     // 否则用最慢输给最快
                if (tj[l1] < qw[r2]) --ans;
                ++l1; --r2;
            }
        }
    }
    cout << ans * 200 << endl;
    return 0;
}