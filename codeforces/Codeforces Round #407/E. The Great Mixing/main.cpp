#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
const int MAXN = 2e6 + 10;
bool vis[MAXN];
int bias = 1e6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, val;
    cin >> n >> k;
    unordered_set<int> table;
    for (int i = 0; i < k; i++) {
        cin >> val;
        table.insert(val - n);
    }
    int ret = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        ret++;
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();
            for (int delta : table) {
                if (cur+delta == 0) {
                    cout << ret << endl;
                    return 0;
                }
                if (cur+delta+bias < 0 || cur+delta+bias >= MAXN) continue;
                if (vis[cur+delta + bias]) continue;
                vis[cur+delta + bias] = true;
                q.push(cur+delta);
            }
        }
        if (ret > 2000) break;
    }
    cout << -1 << endl;
    return 0;
}