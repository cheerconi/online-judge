#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], ret;
vector<int> primes;
int gcd (int a, int b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}

void dfs (int i, int cur, int ma) {
    if (cur >= ret) return;
    if (i == primes.size()) {
        if (cur >= ma) ret = min(cur, ret);
        return;
    }
    dfs (i+1, cur, ma);
    dfs (i+1, cur*primes[i], ma);
}

int solve (int n) {
    int cur = 0;
    int ma = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) return -1;
        ma = max(ma, b[i]+1);
        if (b[i] == a[i]) continue;
        cur = gcd (cur, a[i]-b[i]);
    }
    if (cur == 0) return ma;
    if (cur < ma) return -1;
    for (LL i = 2; i*i <= cur; i++) {
        while (cur % i == 0) {
            primes.push_back(i);
            cur /= i;
        }
    }
    if (cur != 1) primes.push_back(cur);
    ret = INT_MAX;
    dfs(0, 1, ma);
    return ret;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << solve(n) << endl;


    return 0;
}