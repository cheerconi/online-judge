#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
typedef long long LL;
using namespace std;
const int MAXN = 100000 + 10;

int fa[MAXN];
int vis[MAXN];
LL a[3];
unordered_map<LL, int> s;
int goup(int start, int deep) {
    if (vis[start] != 0) {
        return vis[start] + deep;
    }
    vis[start] = deep+1;
    if (start == 1) return 0;
    return goup(fa[start], deep+1);
}


int count() {
    LL tmp1 = (a[0] << 31) | a[1];
    LL tmp2 = (a[0] << 31) | a[2];
    LL tmp3 = (a[1] << 31) | a[2];
    if (s.find(tmp1) == s.end()) {
        memset(vis, 0, sizeof(vis));
        goup(a[0], 0);
        s[tmp1] = goup(a[1], 0);
    }
    if (s.find(tmp2) == s.end()) {
        memset(vis, 0, sizeof(vis));
        goup(a[0], 0);
        s[tmp2] = goup(a[2], 0);
    }
    if (s.find(tmp3) == s.end()) {
        memset(vis, 0, sizeof(vis));
        goup(a[1], 0);
        s[tmp3] = goup(a[2], 0);
    }
    int ret = max(s[tmp1]+s[tmp2]-s[tmp3]+1, s[tmp3]+s[tmp1]-s[tmp2]);
    ret = max(ret, s[tmp2]+s[tmp3]-s[tmp1]);
    return (ret+1)/2;



}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2]);
        sort(a, a+3);
        printf("%d\n", count());

    }


    return 0;
}