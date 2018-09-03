#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
static const int MAXN = 10000 + 10;
struct Barn{
    int maxsub;
    int size;
    Barn() {
        maxsub = 0;
        size = 0;
    }
} barns[MAXN];
int val[MAXN<<1];
int pre[MAXN<<1];
int now[MAXN];
int m;
void add(int a, int b) {
    val[m] = b;
    pre[m] = now[a];
    now[a] = m;
    m++;
}
void dfs(int root, int fa) {
    int size = 1;
    int maxsub = 0;
    for (int pos = now[root]; pos != 0; pos = pre[pos]) {
        if (val[pos] == fa) continue;
        int son_id = val[pos];
        dfs(son_id, root);
        size += barns[son_id].size;
        maxsub = max(maxsub, barns[son_id].size);
    }
    barns[root].size = size;
    barns[root].maxsub = maxsub;
}
int main() {
//    freopen("test.txt", "r", stdin);
    memset(now, 0, sizeof(now));
    m = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int tmp = max(barns[i].maxsub, n - barns[i].size);
        if (tmp <= (n >> 1)) printf("%d\n", i);
    }


    return 0;
}