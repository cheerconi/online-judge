#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int MAXN = 2e5 + 10;
int weight[MAXN], L[MAXN], R[MAXN], ind[MAXN];
int x[MAXN], k[MAXN], id[MAXN], tree2[MAXN];
LL dist[MAXN], tree1[MAXN], ret[MAXN];
vector<int> edges[MAXN];
int n, tot;

inline bool cmp1(int i, int j) {
    return dist[i] > dist[j];
}
inline bool cmp2(int i, int j) {
    return (dist[x[i]]+k[i]) > (dist[x[j]]+k[j]);
}
void dfs(int root, LL val) {
    L[root] = ++tot;
    dist[root] = val;
    for (int son : edges[root]) {
        dfs(son, val + weight[son]);
    }
    R[root] = tot;
}
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i, LL val) {
    while (i <= n) {
        tree1[i] += val;
        tree2[i] += 1;
        i += lowbit(i);
    }
}
pli find (int i) {
    pli ret = {0, 0};
    while (i > 0) {
        ret.first += tree1[i];
        ret.second += tree2[i];
        i -= lowbit(i);
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    int par;
    ind[1] = 1;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &par, &weight[i]);
        edges[par].push_back(i);
        ind[i] = i;
    }
    dfs(1, 0);
    sort(ind+1, ind+n+1, cmp1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &x[i], &k[i]);
        id[i] = i;
    }
    sort(id, id+q, cmp2);
    int p = 1;
    for (int i = 0; i < q; i++) {
        int cur = id[i];
        while (p <= n && dist[ind[p]] >= dist[x[cur]]+k[cur]) {
            add(L[ind[p]], dist[ind[p]]);
            p++;
        }
        auto tmp2 = find(R[x[cur]]);
        auto tmp1 = find(L[x[cur]]- 1);
        ret[cur] = (tmp2.first-tmp1.first) - dist[x[cur]] * (tmp2.second-tmp1.second);
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ret[i]);
    }
    return 0;
}