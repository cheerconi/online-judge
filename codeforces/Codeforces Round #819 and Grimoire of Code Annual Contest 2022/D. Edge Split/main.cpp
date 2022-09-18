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
int a[MAXN], b[MAXN], par[MAXN];

int find(int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}

void add(int i, int j) {
    int x = find(i);
    int y = find(j);
    par[x] = y;
}

bool check(const vi& idx) {
    assert(idx.size() == 3);
    for (int i : idx) {
        par[a[i]] = a[i];
        par[b[i]] = b[i];
    }
    for (int i = 0; i < 2; i++) {
        int j = idx[i];
        add(a[j], b[j]);
    }
    int x = find(a[idx[2]]);
    int y = find(b[idx[2]]);
    return x != y;
}

string solve(int n, int m) {
    if (m == n-1) return string(m, '0');
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    vector<int> idx;
    for (int i = 0; i < m; i++) {
        int x = find(a[i]);
        int y = find(b[i]);
        if (x == y) {
            idx.push_back(i);
        } else {
            add(x, y);
        }
    }
    string ret = string(m, '0');
    for (int i : idx) {
        ret[i] = '1';
    }
    if (idx.size() <= 2 || check(idx)) {
        return ret;
    }
    int k = idx.back();
    ret[k] = '0';
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (ret[i] == '1') continue;
        add(a[i], b[i]);
        if (find(a[k]) == find(b[k])) {
            ret[i] = '1';
            break;
        }
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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i];
        }
        cout << solve(n, m) << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
