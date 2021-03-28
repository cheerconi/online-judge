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
const int MAXN = 200000 + 10;
int tree[MAXN], n;
vector<int> idx[26];
inline int lowbit(int i) {
  return i&(-i);
}

void update(int i, int val) {
  while (i <= n) {
    tree[i] += val;
    i += lowbit(i);
  }
}
int query(int i) {
  int ret = 0;
  while (i > 0) {
    ret += tree[i];
    i -= lowbit(i);
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
  cin >> n;
  string s; cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  for (int i = n-1; i >= 0; i--) {
    idx[t[i]-'a'].push_back(i+1);
  }
  for (int i = 1; i <= n; i++) {
    update(i, 1);
  }
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    int val = s[i] - 'a';
    int j = idx[val].back(); idx[val].pop_back();
    int tmp = query(j);
    if (tmp - (i+1) <= 0) continue;
    ret += tmp - (i+1);
    update(1, 1);
    update(j, -1);
  }
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
