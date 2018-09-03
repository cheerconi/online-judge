#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN], state[MAXN];
vector<int> neg[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        neg[a].push_back(b);
        neg[b].push_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (nums[i] == 0) q.push(i);
    }
    vector<int> ret;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (state[cur] != nums[cur]) continue;
        ret.push_back(cur);
        state[cur]++;
        for (int nxt : neg[cur]) {
            state[nxt]++;
            if (state[nxt] == nums[nxt]) q.push(nxt);
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }
    return 0;
}