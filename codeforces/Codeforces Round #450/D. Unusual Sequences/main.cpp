#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
unordered_map<LL, LL> table;
vector<LL> primes;
LL solve(int y);

LL power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
LL val;
void dfs (LL y, int i, int cnt, LL cur) {
    if (y % cur != 0) return;
    if (i == primes.size()) {
        if (cur == 1) return;
        LL tmp = power(2, y/cur-1);
        if (cnt % 2 != 0) {
            tmp = mod - tmp;
        }
        val = (val + tmp) % mod;
        return;
    }
    dfs(y, i+1, cnt, cur);
    dfs(y, i+1, cnt+1, cur*primes[i]);
}
LL solve (int y) {
    if (table.find(y) != table.end()) return table[y];
    LL ret = power(2, y-1);
    val = 0;
    dfs(y, 0, 0, 1);
    ret = (ret + val) % mod;
    table[y] = ret;
    return ret;
}
int main() {
    LL x, y;
    cin >> x >> y;
    table[1] = 1;
    LL tmp = y;
    for (LL i = 2; i*i <= tmp; i++) {
        if (tmp % i == 0) {
            primes.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp != 1) primes.push_back(tmp);
    LL ret = 0;
    if (y % x == 0) ret = solve(y/x);
    cout << ret << endl;

    return 0;
}