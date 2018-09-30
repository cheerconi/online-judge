#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, k;
LL dp[31];
int num[31];


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        if (a <= k) {
            for (int j = 30; j >= 0; j--) {
                int tmp1 = a >> (j+1);
                int tmp2 = k >> (j+1);
                if ((tmp1|tmp2)<= tmp2 && ((1<<j)&a) == 0) {
                    dp[j] += b;
                    num[j] |= a;
                }
            }
        }
    }
    LL ret = 0;
    for (int i = 0; i < 31; i++) {
        if (num[i] <= k) ret = max(ret, dp[i]);
    }
    cout << ret << endl;

    return 0;
}