#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    list<int> L{1};
    vector<list<int>::iterator> pos(n + 1);  // 用vector代替unordered_map
    pos[1] = L.begin();
    
    // 插入操作
    for(int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        
        if(p == 0) {
            pos[i] = L.insert(pos[k], i);
        } else {
            auto it = next(pos[k]);
            pos[i] = L.insert(it, i);
        }
    }
    
    // 删除操作
    int m;
    cin >> m;
    vector<bool> deleted(n + 1, false);
    
    while(m--) {
        int x;
        cin >> x;
        if(x >= 1 && x <= n && !deleted[x]) {
            L.erase(pos[x]);
            deleted[x] = true;
        }
    }
    
    // 输出
    for(int num : L) {
        cout << num << " ";
    }
    
    return 0;
}
