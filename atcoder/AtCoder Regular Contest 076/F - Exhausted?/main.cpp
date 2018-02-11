#include <iostream>
#include <algorithm>
#include <climits>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 2e5 + 10;
int tree[MAXN<<2], info[MAXN<<2], n;
pii items[MAXN];
void build (int node, int left, int right, int m) {
    if (left == right) {
        tree[node] = left - m;
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid, m);
    build (rightnode, mid+1, right, m);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}
void push(int node, int left, int right) {
    if (info[node] == 0) return;
    int mid = getmid;
    tree[leftnode] += info[node];
    tree[rightnode] += info[node];
    info[leftnode] += info[node];
    info[rightnode] += info[node];
    info[node] = 0;
}
void update(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return;
    if (i <= left && right <= j) {
        info[node]++;
        tree[node]++;
        return;
    }
    push(node, left, right);
    int mid = getmid;
    update(leftnode, left, mid, i, j);
    update(rightnode, mid+1, right, i, j);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}
int query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return INT_MIN;
    if (i <= left && right <= j) {
        return tree[node];
    }
    push(node, left, right);
    int mid = getmid;
    return max(query(leftnode, left, mid, i, j), query(rightnode, mid+1, right, i, j));
}

bool cmp(pii a, pii b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tot, m, a, b;
    cin >> tot >> m;
    n = m+1;
    for (int i = 0; i < tot; i++) {
        cin >> a >> b;
        items[i] = {a, b};
    }
    sort(items, items+tot, cmp);
    int ret = max(tot - m, 0);
    build (1, 1, m+1, m+1);
    for (int i = 0; i < tot; i++) {
        update(1, 1, m+1, items[i].first+1, items[i].second);
        int tmp = query(1, 1, m+1, items[i].first+1, m+1);
        ret = max(ret, tmp-items[i].first);
    }
    cout << ret << endl;

    return 0;
}