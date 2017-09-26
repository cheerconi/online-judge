#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL dp1[MAXN];
LL dp2[MAXN];
int nums[MAXN];
LL inf = 0x8000000000000000;
LL n, p, q, r;

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> p >> q >> r;
    dp1[0] = inf;
    dp2[n+1] = inf;
    for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
    for (int i = 1; i <= n; i++) {
        dp1[i] = p*nums[i];
        dp1[i] = max(dp1[i-1], dp1[i]);
    }
    for (int i = n; i >= 1; i--) {
        dp2[i] = r*nums[i];
        dp2[i] = max(dp2[i+1], dp2[i]);
    }
    LL ret = inf;
    for(int i = 1; i <= n; i++) {
        ret = max(ret, q*nums[i]+dp1[i]+dp2[i]);
    }
    cout << ret << endl;


    return 0;
}