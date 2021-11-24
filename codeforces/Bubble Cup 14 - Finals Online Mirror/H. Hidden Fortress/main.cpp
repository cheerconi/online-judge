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
int tot = 0;
int ask(int i, int j) {
    assert(tot < 40);
    cout << "? " << i << ' ' << j << endl;
    int val; cin >> val;
    assert(val != -1);
    tot++;
    return val;
}

pll solve(const pll& item1, const pll& item2) {
    if (item1.first == item2.first || item1.first+1 == item2.first) {
        if (item1.second > item2.second) return item2;
        return item1;
    }
    LL mid = (item1.first + item2.first)  >> 1;
    pll tmp = make_pair(mid, ask(mid, 1));
    if (item1.second == item2.second) {
        return tmp;
    }
    int diff = mid - item1.first;
    if (item1.second - diff == tmp.second) {
        return solve(tmp, item2);
    }
    return solve(item1, tmp);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n = 1e9;
    pll item1 = make_pair(1, ask(1, 1));
    pll item2 = make_pair(n, ask(n, 1));
    pll ret = solve(item1, item2);
    int a = ret.second;
    int b = ask(ret.first, n);
    int c = ask(1, a+1);
    int d = ask(n, a+1);
    cout << "! " << c+1 << ' ' << a+1 << ' ' << n-d << ' ' << n-b << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
