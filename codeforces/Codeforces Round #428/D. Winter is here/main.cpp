#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXV = 1000000 + 10;
const int MAXN = 200000  + 10;
const int mod = 1e9 + 7;
int n;
int cnt[MAXV];
int power[MAXN];
int dp[MAXV];

int main() {
//    freopen("test.txt", "r", stdin);
    int num, val = 0, card = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        val = max(val, num);
        int j = 1;
        for (; j*j < num; j++) {
            if (num % j == 0) {
                cnt[j]++;
                cnt[num/j]++;
                card = max(cnt[j], card);
                card = max(cnt[num/j], card);
            }
        }
        if (j*j == num) cnt[j]++;
        card = max(card, cnt[j]);
    }
    power[0] = 1;
    for (int i = 1; i < card; i++) {
        power[i] = 1LL * power[i-1] * 2 % mod;
    }
    for (int i = val; i > 1; i--) {
        if (cnt[i] == 0) continue;
        dp[i] = 1LL * cnt[i] *power[cnt[i]-1] % mod;
        for (int j = 2*i; j <= val; j += i) {
            dp[i] = (dp[i] - dp[j] + mod) % mod;
        }
    }
    LL ret = 0;
    for (int i = 2; i <= val; i++) {
        ret = (ret + 1LL * i * dp[i] ) % mod;
    }
    cout << ret << endl;

    return 0;
}