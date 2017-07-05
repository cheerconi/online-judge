#include <iostream>
#include <memory.h>
using namespace std;
typedef long long LL;
static const int MAXN = 100000 + 10;
struct Edu{
    LL people;
    LL size;
} edus[MAXN];

int val[MAXN << 1];
int now[MAXN];
int pre[MAXN << 1];
int p;
void add(int a, int b){
    val[p] = b;
    pre[p] = now[a];
    now[a] = p;
    p++;
}
void dfs(int root, int fa) {
    LL size = edus[root].people;
    for (int pos = now[root]; pos != 0; pos = pre[pos]) {
        int son = val[pos];
        if (son == fa) continue;
        dfs(son, root);
        size += edus[son].size;
    }
    edus[root].size = size;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    int c = 0;
    while (scanf("%d%d", &n, &m) && n != 0) {
        c++;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &edus[i].people);
            edus[i].size = 0;
        }
        p = 1;
        memset(now, 0, sizeof(now));
        int a, b;
        for (int i = 2; i <= n; i++) {
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        dfs(1, 0);
        LL ret = edus[1].size;
        for (int i = 1; i <= n; i++) {
            LL tmp = edus[1].size - (edus[i].size << 1);
            if (tmp < 0) tmp = -tmp;
            if (tmp < ret) ret = tmp;
        }
        printf("Case %d: %lld\n", c, ret);
    }
    return 0;
}