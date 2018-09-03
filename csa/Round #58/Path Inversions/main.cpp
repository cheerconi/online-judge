#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> edges[MAXN];
bool used[MAXN];
int sz[MAXN], cnt[MAXN];
int n, k;
LL ret;


void count(int root, int par) {
    sz[root] = 1;
    for (int son : edges[root]) {
        if (son == par || !used[son]) continue;
        count(son, root);
        sz[root] += sz[son];
    }
}

void dfs(int root, int par, int dist, int delta) {
    cnt[dist] += delta;
    for (int son : edges[root]) {
        if (son == par || !used[son]) continue;
        dfs(son, root, dist+1, delta);
    }
}
void dfs2(int root, int par, int dist) {
    if (dist > k) return;
    ret += cnt[k-dist];
    for (int son : edges[root]) {
        if (son == par || !used[son]) continue;
        dfs2(son, root, dist+1);
    }
}
int idx = 1;
void split(int cur) {
    count(cur, 0);
    int tot = sz[cur];
    if (tot == 1) {
        used[cur] = false;
        while (idx <= n && !used[idx]) idx++;
        if (idx <= n) split(idx);
        return;
    }
    bool done = false;
    int pp = -1;
    while (!done) {
        done = true;
        for (int son : edges[cur]) {
            if (!used[son] || son == pp) continue;
            if (sz[son]*2 > tot) {
                done = false;
                pp = cur;
                cur = son;
                break;
            }
        }
    }
    cnt[0] = 2;
    for (int son : edges[cur]) {
        if (!used[son]) continue;
        dfs(son, cur, 1, 1);
    }
    for (int son : edges[cur]) {
        if (!used[son]) continue;
        dfs(son, cur, 1, -1);
        dfs2(son, cur, 1);
        dfs(son, cur, 1, 1);
    }
    for (int son : edges[cur]) {
        if (!used[son]) continue;
        dfs(son, cur, 1, -1);
    }
    used[cur] = false;
    while (idx <= n && !used[idx]) idx++;
    if (idx <= n) split(idx);
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> k;
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    memset(used, true, sizeof(used));
    split(1);

    ret = ret / 2 % mod * ((1LL * k * (k+1) / 2) % mod) ;
    cout << ret % mod << endl;


    return 0;
}