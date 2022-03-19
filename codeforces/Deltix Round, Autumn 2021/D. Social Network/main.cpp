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
const int MAXN = 1e3 + 10;
int par[MAXN];
int cnt[MAXN];
set<pii> table;

int find(int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    assert(a != b);
    table.erase(make_pair(cnt[a], a));
    table.erase(make_pair(cnt[b], b));
    par[a] = b;
    cnt[b] += cnt[a];
    table.emplace(cnt[b], b);
}

int solve(int sparse) {
    int ret = 0;
    for (auto it = table.rbegin(); sparse >= 0; it++, sparse--) {
        ret += it->first;
    }
    return ret-1;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        cnt[i] = 1;
        table.emplace(1, i);
    }
    int sparse = 0;
    while (d--) {
        int i, j; cin >> i >> j;
        i--; j--;
        if (find(i) == find(j)) {
            sparse++;
        } else {
            add(i, j);
        }


        cout << solve(sparse) << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
