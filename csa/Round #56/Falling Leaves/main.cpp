#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
int ret[MAXN];


int main() {
//    freopen("test.txt", "r", stdin);
    int t, c, n;
    cin >> t >> c >> n;
    int x, y, z;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        LL val = 1LL*y*c - 1LL*x*z;
        if (val < 0) continue;
        LL p = 1LL * c * z;
        if (val % p != 0) continue;
        val = val / p;
        if (val < t) ret[val]++;

    }
    for (int i = 0; i < t; i++) {
        printf("%d\n", ret[i]);
    }

    return 0;
}