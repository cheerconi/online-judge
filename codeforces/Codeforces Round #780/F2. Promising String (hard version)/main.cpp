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
const int MAXN = 2e5 + 10;
int state[MAXN], tree[MAXN];
int n;

int lowbit(int i) {
    return i&(-i);
}

void update(int i) {
    while (i <= n+1) {
        tree[i]++;
        i += lowbit(i);
    }
}
LL query(int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}



LL solve(vector<pii>& items) {
    sort(items.begin(), items.end());
    LL ret = 0;
    for (int i = 1; i <= n+1; i++) tree[i] = 0;
    for (const auto [_, i] : items) {
        ret += query(n+1) - query(-i);
        update(-i);
    }
    return ret;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        cin >> n;
        string s; cin >> s;
        for (int i = 1; i <= n; i++) {
            state[i] = state[i-1];
            if (s[i-1] == '-') state[i]--;
            else state[i]++;
        }
        vector<pii> items[3];
        for (int i = 0; i <= n; i++) {
            int j = state[i] % 3;
            if (j < 0) j += 3;
            items[j].emplace_back(state[i], -i-1);
        }
        LL ret = 0;
        for (int i = 0; i < 3; i++) {
            ret += solve(items[i]);
        }
        cout << ret << '\n';


    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
