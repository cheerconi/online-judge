#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 5e3 + 10;
int times[MAXN][2];
vector<int> edges[MAXN];
vector<int> hold[MAXN];
int n, m;
void solve() {
    times[1][0] = 0;
    queue<pii> q;
    q.push({1, 0});
    int tmp, val, son;
    while (!q.empty()) {
        int cur = q.front().first;
        int phase = q.front().second;
        q.pop();
        for (int i = 0; i < edges[cur].size(); i++) {
            son = edges[cur][i];
            val = hold[cur][i];
            if (val <= times[cur][phase]) {
                tmp = times[cur][phase] + 1;
            }
            else {
                tmp = val + 1 + (val - times[cur][phase]) % 2;
            }
            if (times[son][1-phase] > tmp) {
                times[son][1-phase] = tmp;
                q.push({son ,1-phase});
            }
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        times[i][0] = times[i][1] = INT_MAX;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back(b);
        edges[b].push_back(a);
        hold[a].push_back(c);
        hold[b].push_back(c);
    }
    solve();
    int ret = min(times[n][0], times[n][1]);
    if (ret == INT_MAX) cout << -1 << endl;
    else cout << ret << endl;
    return 0;
}