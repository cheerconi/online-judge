#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> pLL;
const LL base = 1e7;
const LL inf = 1e16;
int da[] = {1, -1, 0, 0, 1, 1, -1, -1};
int db[] = {0, 0, -1, 1, -1, 1, 1, -1};
LL n, m, r;
LL check (LL a, LL b) {
    LL x = max(1LL, a-r+1);
    LL y = max(1LL, b-r+1);
    LL xx = min(n-r+1, a);
    LL yy = min(m-r+1, b);
    return (yy-y+1)*(xx-x+1);
}


int main() {
//    freopen("test.txt", "r", stdin);
    int tot;
    cin >> n >> m >> r >> tot;
    priority_queue<pLL> q;
    LL tmp_a = (n+1) / 2;
    LL tmp_b = (m+1) / 2;
    unordered_set<LL> table;
    LD ret = 0;
    LL tmp1 = 0;
    q.push({check(tmp_a, tmp_b), tmp_a*base+tmp_b});
    table.insert(tmp_a*base + tmp_b);
    for (int i = 0; i < tot; i++) {
        pLL tmp = q.top(); q.pop();
        LL a = tmp.second / base;
        LL b = tmp.second % base;
        tmp1 += tmp.first;
        if (tmp1 > inf) {
            ret += tmp1;
            tmp1 = 0;
        }
        for (int k = 0; k < 8; k++) {
            if (a+da[k] <= 0 || a+da[k] > n) continue;
            if (b+db[k] <= 0 || b+db[k] > m) continue;
            LL ab = (a+da[k])*base + (b+db[k]);
            if (table.find(ab) != table.end())continue;
            q.push({check(a+da[k], b+db[k]),ab});
            table.insert(ab);
        }
    }
    ret += tmp1;
    LL tmp2 = (n-r+1) * (m-r+1);
    ret = ret / (LD)tmp2;
    printf("%.12Lf\n", ret);

    return 0;
}