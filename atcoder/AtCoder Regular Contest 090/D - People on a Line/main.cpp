#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
int par[MAXN], L[MAXN<<1], R[MAXN<<1], D[MAXN<<1];
int lft[MAXN], rght[MAXN], dist[MAXN];
bool vis[MAXN<<1], tmp[MAXN];
vector<int> vs[MAXN];
int find (int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i] >> D[i];
        add (L[i], R[i]);
        vs[L[i]].push_back(i);
        vs[R[i]].push_back(i);

    }
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        int p = find(i);
        if (tmp[p]) continue;
        tmp[p] = true;
        for (int item : vs[p]) {
            if (vis[item]) continue;
            q.push(item);
            vis[item] = true;
        }
    }
    while (!q.empty()) {
        int i = q.front(); q.pop();
        int p = find(L[i]);
        if (L[i] == p) dist[L[i]] = 0;
        if (R[i] == p) dist[R[i]] = 0;
        if (dist[L[i]] != INT_MAX && dist[R[i]] != INT_MAX) {
            if (dist[R[i]]-dist[L[i]] != D[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        else if (dist[L[i]] != INT_MAX) {
            dist[R[i]] = dist[L[i]] + D[i];
        }
        else if (dist[R[i]] != INT_MAX) {
            dist[L[i]] = dist[R[i]] - D[i];
        }
        lft[p] = min(lft[p], dist[L[i]]);
        rght[p] = max(rght[p], dist[R[i]]);
        if (rght[p]-lft[p] > 1e9) {
            cout << "No" << endl;
            return 0;
        }
        if (!tmp[L[i]]) {
            tmp[L[i]] = true;
            for (int item : vs[L[i]]) {
                if (!vis[item]) {
                    vis[item] = true;
                    q.push(item);
                }
            }
        }
        if (!tmp[R[i]]) {
            tmp[R[i]] = true;
            for (int item : vs[R[i]]) {
                if (!vis[item]) {
                    vis[item] = true;
                    q.push(item);
                }
            }
        }

    }
    cout << "Yes" << endl;
    return 0;
}