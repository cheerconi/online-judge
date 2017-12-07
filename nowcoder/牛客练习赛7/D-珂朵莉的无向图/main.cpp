#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 5000 + 10;
vector<int> edges[MAXN];
int vis[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int t, s, val, cnt;
    for (int k = 1; k <= q; k++) {
        scanf("%d%d", &t, &s);
        queue<int> q;
        cnt = 0;
        for (int i = 0; i < t; i++) {
            scanf("%d", &val);
            if (vis[val] < k) {
                q.push(val);
                cnt++;
                vis[val] = k;
            }
        }
        int d = 1;
        while (d <= s && !q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                val = q.front();
                q.pop();
                for (int son : edges[val]) {
                    if (vis[son] < k) {
                        vis[son] = k;
                        q.push(son);
                        cnt++;
                    }
                }
            }
            d++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}