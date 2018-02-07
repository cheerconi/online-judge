#include <iostream>
#include <unordered_map>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left + right) >> 1)
using namespace std;
typedef long long LL;
const int MAXV = 1e6 + 10;
const int MAXN = 3e5 + 10;
int fact[MAXV], dp[MAXV];
LL tree[MAXN<<2];
bool done[MAXN<<2];
void make_table() {
    for (LL i = 2; i < MAXV; i++) {
        if (fact[i] != 0) continue;
        for (LL j = i*i; j < MAXV; j += i) {
            if (fact[j] == 0) fact[j] = i;
        }
    }
    dp[1] = 1;
}
int update(int n) {
    if (dp[n] != 0) return dp[n];
    unordered_map<int, int> table;
    int cur = n;
    while (fact[cur] != 0) {
        table[fact[cur]]++;
        cur /= fact[cur];
    }
    if (cur != 1) table[cur]++;
    int ret = 1;
    for (auto it = table.begin(); it != table.end(); it++) {
        ret = ret * (it->second + 1);
    }
    return dp[n] = ret;
}
void build (int node, int left, int right) {
    if (left == right) {
        cin >> tree[node];
        if (tree[node] <= 2) done[node] = true;
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);
    tree[node] = tree[leftnode] + tree[rightnode];
    done[node] = done[leftnode] && done[rightnode];
}
void update(int node, int left, int right, int i, int j) {
    if (right < i || j < left || done[node]) return;
    if (left == right) {
        tree[node] = update(tree[node]);
        if (tree[node] <= 2) done[node] = true;
        return;
    }
    int mid = getmid;
    update(leftnode, left, mid, i, j);
    update(rightnode, mid+1, right, i, j);
    tree[node] = tree[leftnode] + tree[rightnode];
    done[node] = done[leftnode] && done[rightnode];
}

LL query(int node, int left, int right, int i, int j) {
    if (j < left || right < i) return 0;
    if (i <= left && right <= j) {
        return tree[node];
    }
    int mid = getmid;
    LL ret = query(leftnode, left, mid, i, j);
    ret += query(rightnode, mid+1, right, i, j);
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    int n, m, a, b, c;
    cin >> n >> m;
    build (1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        }
        else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}