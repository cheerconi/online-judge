#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL sum[MAXN], ret[MAXN], res[MAXN];
int v[MAXN], t[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        sum[i] = sum[i-1] + t[i];
    }
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(sum+i, sum+1+n, sum[i-1]+v[i]) - sum;
        if (p == n+1) {
            ret[i]++;
            continue;
        }
        if (sum[p] == sum[i-1]+v[i]) {
            ret[i]++;
            ret[p+1]--;
            continue;
        }
        ret[i]++;
        ret[p]--;
        res[p] += (sum[i-1]+v[i] - sum[p-1]);
    }
    for (int i = 1; i <= n; i++) {
        ret[i] += ret[i-1];
    }
    for (int i = 1; i <= n; i++) {
        ret[i] = ret[i]*t[i] + res[i];
        cout << ret[i];
        if (i == n) cout << '\n';
        else cout << ' ';
    }
    return 0;
}