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

const int MAXN = 300 + 10;
LL nums[MAXN][2];
vector<int> edges[MAXN];
int degree[MAXN], ret;
bool used[MAXN];

LL gcd(LL a, LL b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b%a);
}

struct  Fra{
    LL a, b;
    Fra(LL a_, LL b_): a(a_), b(b_) {
        LL tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
    }
    bool operator== (const Fra& rhs) {
        return a*rhs.b == b*rhs.a;
    }
    bool operator< (const Fra& rhs) {
        return a*rhs.b < b*rhs.a;
    }
};

pair<Fra, Fra> check(pair<Fra, Fra> rule, int i, int j) {
    if (nums[i][0] <= nums[j][0] && nums[i][1] <= nums[j][1]) return rule;
    LL a = nums[i][0] - nums[j][0];
    LL b = nums[j][1] - nums[i][1];
    assert (a != 0 && b != 0);
    if (a > 0 && b > 0) {
        Fra tmp(a, b);
        rule.first = rule.first < tmp ? tmp : rule.first;
    } else {
        Fra tmp(-a, -b);
        rule.second = rule.second < tmp ? rule.second : tmp;
    }
    if (rule.first < rule.second) return rule;
    Fra tmp(1, 0);
    rule.first = tmp;
    return rule;
}

void solve(set<int> q, int i, int cnt, pair<Fra, Fra> rule) {
    if (rule.first == Fra(1, 0)) return;
    if (cnt == 0) {
        ret++;
        return;
    }
    vector<int> d_bk;
    q.erase(i);
    used[i] = true;
    for (int nxt : edges[i]) {
        if (used[nxt]) continue;
        d_bk.push_back(nxt);
        degree[nxt]--;
        if (degree[nxt] == 0) q.insert(nxt);
    }
    for (int tmp : q) {
        auto new_rule = check(rule, i, tmp);
        if (new_rule.first == Fra(1, 0)) continue;
        solve(q, tmp, cnt-1, new_rule);
    }
    for (int j : d_bk) {
        degree[j]++;
    }
    used[i] = false;
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n;
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        memset(degree, 0, sizeof(degree));
        memset(used, false, sizeof(used));
        ret = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i][0] >> nums[i][1];
            edges[i].clear();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (nums[i][0] >= nums[j][0] && nums[i][1] >= nums[j][1]) {
                    edges[j].push_back(i);
                    degree[i]++;
                }
            }
        }
        set<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) q.insert(i);
        }
        for (int i : q) {
            solve(q, i, n-1, make_pair(Fra(0, 1), Fra(1, 0)));
        }
        cout << "Case #"<< cs << ": " << ret << endl;


    }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
