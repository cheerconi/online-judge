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
int cnt[MAXN], nums[MAXN];

bool check(int p, int n) {
  if (p <= 0 || p >= n) return false;
  for (int i = 1; i <= p; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < p; i++) {
    cnt[nums[i]]++;
  }
  for (int i = 1; i <= p; i++) {
    if (cnt[i] != 1) return false;
  }
  for (int i = 1; i <= n-p; i++) {
    cnt[i] = 0;
  }
  for (int i = p; i < n; i++) {
    cnt[nums[i]]++;
  }
  for (int i = 1; i <= n-p; i++) {
    if (cnt[i] != 1) return false;
  }
  return true;
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
    int n; cin >> n;
    for (int i = 0; i < n+2; i++) {
      cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      cnt[nums[i]]++;
    }
    int p = -1;
    for (int i = 1; ;i++) {
      if (cnt[i] != 2) {
        p = i-1;
        break;
      }
    }
    vector<int> ret;
    if (check(p, n)) ret.push_back(p);
    if (n-p != p && check(n-p, n)) ret.push_back(n-p);
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
      cout << ret[i] << ' ' << n-ret[i] << '\n';
    }

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
