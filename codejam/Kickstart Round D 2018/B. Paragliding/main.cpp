#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/
struct Item{
    int x, y, cls;
    bool operator< (const Item & rhs) const {
        return x < rhs.x;
    }
};
const int MAXM = 5;
const int MAXN = 1e5 + 10;
LL a[MAXM], b[MAXM], c[MAXM], m[MAXM];
LL p[MAXM][MAXN];
int cnt[MAXN<<1];

void solve(int s, int t, int delta, vector<Item> & items) {
    Item item;
    item.x = items[s].x;
    item.y = 0;
    for (int i = s; i != t; i += delta) {
        auto & cur = items[i];
        if (cur.cls == 0) {
            if (item.y - abs(cur.x-item.x) < cur.y) {
                item = cur;
            }
        } else {
            if (item.y - abs(cur.x-item.x) >= cur.y) cnt[i]++;
        }
    }
}

int solve(int n, int k) {
    memset(cnt, 0, sizeof(cnt));
    Item item;
    vector<Item> items;
    item.cls = 0;
    for (int i = 1; i <= n; i++) {
        item.x = p[1][i];
        item.y = p[2][i];
        items.push_back(item);
    }
    item.cls = 1;
    for (int i = 1; i <= k; i++) {
        item.x = p[3][i];
        item.y = p[4][i];
        items.push_back(item);
    }
    sort(items.begin(), items.end());
    solve(0, n+k, 1, items);
    solve(n+k-1, -1, -1, items);
    int ret = 0;
    for (int i = 0; i < n+k; i++) {
        if (items[i].cls == 1 && cnt[i] > 0) ret++;
    }
    return ret;

}







int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= 4; i++) {
            cin >> p[i][1] >> p[i][2] >> a[i] >> b[i] >> c[i] >> m[i];
        }
        for (int j = 1; j <= 2; j++) {
            for (int i = 3; i <= n; i++) {
                p[j][i] = (a[j]*p[j][i-1] + b[j]*p[j][i-2] + c[j]) % m[j] + 1;

            }
        }
        for (int j = 3; j <= 4; j++) {
            for (int i = 3; i <= k; i++) {
                p[j][i] = (a[j]*p[j][i-1] + b[j]*p[j][i-2] + c[j]) % m[j] + 1;
            }
        }
        cout << "Case #" << cs << ": " << solve(n, k) << endl;

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
