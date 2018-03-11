#include <iostream>
#include <memory.h>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
int factor[MAXN], dp[MAXN];
vector<int> primes;
void make_table(int n) {
    memset(factor, -1, sizeof(factor));
    primes.push_back(2); primes.push_back(3);
    for (int i = 4; i <= n; i++) {
        for (int p : primes) {
            if ((LL)p*p > i) break;
            if (i % p == 0) {
                factor[i] = p;
                break;
            }
        }
        if (factor[i] == -1) primes.push_back(i);
    }
}

int main() {
    int n, val;
    cin >> n;
    make_table(n);
    for (int i = 1; i <= n; i++) {
        if (factor[i] == -1) {
            dp[i] = INT_MAX;
            continue;
        }
        int tmp = i;
        val = 0;
        while (factor[tmp] != -1) {
            tmp /= factor[tmp];
            val = max(val, factor[tmp]);
        }
        if (tmp != 1) {
            val = max(val, tmp);
        }
        dp[i] = i-val+1;
    }
    int ret = n;
    for (int i = n-val+1 ; i <= n; i++) {
        ret = min(ret, dp[i]);
    }
    cout << ret << endl;


    return 0;
}