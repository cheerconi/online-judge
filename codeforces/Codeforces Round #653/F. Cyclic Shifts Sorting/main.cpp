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
const int MAXN = 555;
int a[MAXN], b[MAXN];
vector<int> ret;
void move(int i) {
  int x = a[i];
  int y = a[i+1];
  int z = a[i+2];
  a[i] = z;
  a[i+1] = x;
  a[i+2] = y;
  ret.push_back(i);
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
    ret.clear();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b+n);
    int idx = -1;
    for (int i = 0; i+1 < n; i++) {
      if (b[i] == b[i+1]) {
        idx = i-2;
        break;
      }
    }
    for (int i = 0; i <= idx; i++) {
      if (a[i] == b[i]) continue;
      int j = i+1;
      while (j < n && a[j] != b[i]) j++;
      assert(j < n);
      while (j - i >= 2) {
        move(j-2);
        j -= 2;
      }
      if (j != i) {
        move(i);
        move(i);
      }
    }
    idx = max(idx+1, 0);
    for (int i = n-1; i >= idx + 3; i--) {
      if (a[i] == b[i]) continue;
      int j = i-1;
      while (j >= idx && a[j] != b[i]) j--;
      assert(j >= idx);
      while (j != i) {
        if (j == idx) move(j);
        else move(j-1);
        j++;
      }
    }
    if (a[idx] != b[idx] || a[idx+1] != b[idx+1] || a[idx+2] != b[idx+2]) {
      move(idx);
    }
    if (a[idx] != b[idx] || a[idx+1] != b[idx+1] || a[idx+2] != b[idx+2]) {
      move(idx);
    }
    if (a[idx] != b[idx] || a[idx+1] != b[idx+1] || a[idx+2] != b[idx+2]) {
      cout << -1 << '\n';
    } else {
      cout << ret.size() << '\n';
      for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] + 1;
        if (i+1 == ret.size()) cout << '\n';
        else cout << ' ';
      }
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
