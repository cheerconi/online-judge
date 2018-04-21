#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL dist[MAXN], val[MAXN], tmp1[MAXN], tmp2[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> dist[i] >> val[i];
    }
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        tot += val[i];
        tmp1[i] = max(0LL, tot - dist[i]);
        tmp2[i] = max(0LL, tot - 2 * dist[i]);
        if (i > 0) {
            tmp1[i] = max(tmp1[i - 1], tmp1[i]);
            tmp2[i] = max(tmp2[i - 1], tmp2[i]);
        }
    }
    LL ret = tmp1[n - 1], tmp;
    tot = 0;
    for (int i = n - 1; i >= 1; i--) {
        tot += val[i];
        tmp = max(tot - (c - dist[i]), 0LL);
        ret = max(ret, tmp + tmp2[i - 1]);
        tmp = max(tot - 2 * (c - dist[i]), 0LL);
        ret = max(ret, tmp + tmp1[i - 1]);
    }
    tot += val[0];
    ret = max(ret, tot - (c - dist[0]));
    cout << ret << endl;
    return 0;
}