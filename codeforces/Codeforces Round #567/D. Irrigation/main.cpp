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
typedef pair<LL, int> pli;
const int MAXN = 500000 + 10;
LL nums[MAXN], tree[MAXN], m, B;
int tmp[MAXN];
pli qs[MAXN];

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}

template<typename T>
inline void read(T &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}


int lowbit(int i) {
    return i&(-i);
}

void add(int i) {
    while (i <= m) {
        tree[i] += 1;
        i += lowbit(i);
    }
}

int solve(int x) {
    int sum = 0, idx = 0;
    for (int i = B; i >= 0; i--) {
        int cand = idx + (1LL<<i);
        if (cand > m) continue;
        if (sum + tree[cand] >= x) continue;
        sum += tree[cand];
        idx = cand;
    }
    return idx+1;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    LL n, q, val;
    read(n); read(m); read(q);
    while ((1LL<<B) <= m) {
        B++;
    }
    B--;
    for (int i = 0; i < n; i++) {
        read(val);
        nums[val]++;
    }
    vector<pii> cities;
    for (int i = 1; i <= m; i++) {
        cities.emplace_back(nums[i], i);
    }
    sort(cities.begin(), cities.end());
    for (int i = 0; i < q; i++) {
        read(qs[i].first);
        qs[i].second = i;
    }
    sort(qs, qs+q);
    LL idx = 0, cnt = 0, value = cities[0].first;
    while (idx < cities.size()) {
        if (cities[idx].first != value) {
            break;
        }
        cnt++;
        add(cities[idx].second);
        idx++;
    }
    for (int i = 0; i < q; i++) {
        while (idx < cities.size() && cnt * (cities[idx].first - value) < qs[i].first-n) {
            n += cnt * (cities[idx].first - value);
            value = cities[idx].first;
            while (idx < cities.size()) {
                if (cities[idx].first != value) {
                    break;
                }
                cnt++;
                add(cities[idx].second);
                idx++;
            }
        }
        if (idx == cities.size()) {
            int ret = (qs[i].first - n) % m;
            if (ret == 0) ret = m;
            tmp[qs[i].second] = ret;
            continue;
        }
        int ret = (qs[i].first-n) % cnt;
        if (ret == 0) ret = cnt;
        tmp[qs[i].second] = solve(ret);
    }
    for (int i = 0; i < q; i++) {
        cout << tmp[i] << endl;
    }









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
