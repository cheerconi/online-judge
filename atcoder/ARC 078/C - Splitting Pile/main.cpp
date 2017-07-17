#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
LL sum[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i-1];
    }
    LL ret = LLONG_MAX;
    LL tmp;
    for (int i = 1; i < n; i++) {
        tmp = sum[n] - 2*sum[i];
        ret = min(ret, abs(tmp));
    }
    cout << ret << endl;

}