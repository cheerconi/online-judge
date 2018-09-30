#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 800 + 10;
int a[MAXN], b[MAXN];

int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        sort(a, a+n);
        sort(b, b+n, greater<int>());
        LL ret = 0;
        for (int i = 0; i < n; i++) ret += (LL)a[i]*b[i];
        printf("Case #%d: %lld\n", t, ret);
    }
    return 0;
}