#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
int distt[MAXN], dists[MAXN];
vector<int> edges[MAXN];

void solve (int dist[], int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : edges[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, s, t, a, b;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    memset(dists, -1, sizeof(dists));
    memset(distt, -1, sizeof(distt));
    solve (dists, s);
    solve (distt, t);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int tmp = dists[i] + 1 + distt[j];
            tmp = min(tmp, dists[j] + 1 + distt[i]);
            if (tmp >= dists[t]) cnt++;
        }
    }
    cnt -= m;
    cout << cnt << endl;


    return 0;
}