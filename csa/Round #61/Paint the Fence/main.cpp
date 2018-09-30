#include <iostream>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
int cnt_info[MAXN<<2], name_info[MAXN<<2];
int ans[MAXN];

void update(int node, int left, int right, int a, int b, int nm, int val) {
    if (b < left || right < a) return;
    if (a <= left && right <= b) {
        cnt_info[node] += val;
        name_info[node] = nm;
        return;
    }
    int mid = getmid;
    if (name_info[node] != 0) {
        update(leftnode, left, mid, left, mid, name_info[node], cnt_info[node]);
        update(rightnode, mid+1, right, mid+1, right, name_info[node], cnt_info[node]);
        cnt_info[node] = 0;
        name_info[node] = 0;
    }
    update(leftnode, left, mid, a, b, nm, val);
    update(rightnode, mid+1, right, a, b, nm, val);
}
pii ret;
void find (int node, int left, int right, int a) {
    if (left == right) {
        ret.first = cnt_info[node];
        ret.second = name_info[node];
        return;
    }
    int mid = getmid;
    if (name_info[node] != 0) {
        update(leftnode, left, mid, left, mid, name_info[node], cnt_info[node]);
        update(rightnode, mid+1, right, mid+1, right, name_info[node], cnt_info[node]);
        cnt_info[node] = 0;
        name_info[node] = 0;
    }
    if (mid >= a) find(leftnode, left, mid, a);
    else find(rightnode, mid+1, right, a);
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        update(1, 1, n, a, b, i, 1);
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        find(1, 1, n, i);
        if (ret.first == 1) {
            ans[ret.second]++;
        }
        else if (ret.first == 0) tmp++;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]+tmp);
    }
    return 0;
}