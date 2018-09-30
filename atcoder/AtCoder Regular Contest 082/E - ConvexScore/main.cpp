#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 200 + 10;
const int mod = 998244353;
pii points[MAXN];
int n;
bool check(int a, int b, int c) {
    int x1 = points[a].first - points[b].first;
    int x2 = points[a].first - points[c].first;
    int y1 = points[a].second - points[b].second;
    int y2 = points[a].second - points[c].second;
    return x1*y2==x2*y1;
}
LL power(LL base, int n) {
    LL ret = 1;
    while (n) {
        if (n & 1 == 1) {
            ret *= base;
            ret %= mod;
        }
        base *= base;
        base %= mod;
        n >>= 1;
    }
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }
    LL ret = power(2, n);
    ret = ret - 1 - n - n*(n-1)/2;
    if (ret < 0) ret += mod;
    vector<pii> used;
    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            bool flag = true;
            for (pii item : used) {
                if (check(item.first, item.second, i) && check(item.first, item.second, j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) used.push_back({i,j});
            else continue;
            int cnt = 2;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (check(i,j,k)) cnt++;
            }
            LL tmp = power(2, cnt) - 1 - cnt - cnt*(cnt-1)/2;
            if (tmp < 0) tmp += mod;
            ret -= tmp;
            if (ret < 0) ret += mod;
        }
    }
    ret = ret % mod;
    cout << ret << endl;
    return 0;
}