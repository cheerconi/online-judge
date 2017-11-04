#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 3e5 + 10;
LL dp[MAXN<<1];
LL dp1[MAXN<<1];
int n, a, b, c, d, start, len;
struct Act{
    int t, type;
    bool operator< (const Act & other) const {
        if (t != other.t) return t < other.t;
        return type > other.type;
    }
    bool operator== (const Act & other) const {
        return t == other.t;
    }
};
Act acts[MAXN<<1];
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> a >> b >> c >> d >> start >> len;
    int tot = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &acts[tot].t, &acts[tot].type);
        acts[tot].type++;
        tot++;
        acts[tot].t = acts[tot-1].t + 1;
        tot++;
    }
    sort(acts, acts+tot);
    n = unique(acts, acts+tot) - acts;
    LL delta = 0, bad = 0;
    int ind = 0;
    while (ind < n && len > acts[ind].t) {
        if (acts[ind].type == 1) {
            delta -= d;
        }
        else if (acts[ind].type == 2) {
            delta += c;
        }
        bad = min(bad, delta);
        ind++;
    }
    dp1[0] = bad;
    dp[0] = delta;
    for (int i = 1; i < n; i++) {
        while (ind < n && acts[i].t + len > acts[ind].t) {
            if (acts[ind].type == 1) {
                delta -= d;
                bad = min(bad, delta);
            }
            else if (acts[ind].type == 2) {
                delta += c;
            }
            ind++;
        }
        if (acts[i-1].type == 1) {
            delta += d;
            bad += d;
        }
        else if (acts[i-1].type == 2) {
            delta -= c;
            bad -= c;
        }
        dp[i] = delta;
        dp1[i] = bad;
    }
    int ret = -1;
    LL cur = start;
    for (int i = 0; i < n; i++) {
        if (cur >= 0 && cur+dp[i] >= 0 && cur+dp1[i] >= 0) {
            ret = acts[i].t;
            break;
        }
        if (acts[i].type == 1) {
            cur -= b;
        }
        else if (acts[i].type == 2) {
            cur += a;
        }
        if (cur < 0) break;

    }
    cout << ret << endl;
}