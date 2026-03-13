#include <bits/stdc++.h>
using namespace std;

int n;
int sticks[70];
bool used[70];
int len;
int num;

bool dfs(int completed, int current, int lastIndex) {
    if (completed == num) {
        return true;
    }
    
    if (current == len) {
        return dfs(completed + 1, 0, -1);
    }
    
    int lastFail = 0;
    
    for (int i = lastIndex + 1; i < n; i++) {
        if (!used[i] && current + sticks[i] <= len && sticks[i] != lastFail) {
            used[i] = true;
            if (dfs(completed, current + sticks[i], i)) {
                return true;
            }
            used[i] = false;
            lastFail = sticks[i];
            
            if (current == 0) {
                return false;
            }
            
            if (current + sticks[i] == len) {
                return false;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
        sum += sticks[i];
    }
    
    sort(sticks, sticks + n, greater<int>());
    
    for (len = sticks[0]; len <= sum; len++) {
        if (sum % len != 0) continue;
        
        num = sum / len;
        
        memset(used, 0, sizeof(used));
        
        if (dfs(0, 0, -1)) {
            cout << len << endl;
            break;
        }
    }
    
    return 0;
}
