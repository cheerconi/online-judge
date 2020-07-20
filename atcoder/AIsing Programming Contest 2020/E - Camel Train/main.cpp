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
int k[MAXN], a[MAXN], b[MAXN], idx[MAXN];

bool cmp(int i, int j) {
  return k[i] < k[j];
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
    LL ret = 0;
    vector<int> idx[2];
    for (int i = 0; i < n; i++) {
      cin >> k[i] >> a[i] >> b[i];
      LL tmp = min(a[i], b[i]);
      ret += tmp;
      a[i] -= tmp;
      b[i] -= tmp;
      if (a[i] > b[i]) idx[0].push_back(i);
      else if (b[i] > a[i]) idx[1].push_back(i);
    }
    {
      sort(idx[0].begin(), idx[0].end(), cmp);
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i : idx[0]) {
        if (pq.size() < k[i]) {
          pq.push(a[i]);
          ret += a[i];
        }
        else {
          if (pq.top() < a[i]) {
            ret -= pq.top();
            pq.pop();
            pq.push(a[i]);
            ret += a[i];
          }
        }
      }
    }
    {
      sort(idx[1].begin(), idx[1].end(), cmp);
      reverse(idx[1].begin(), idx[1].end());
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i : idx[1]) {
        int tmp = n - k[i];
        if (tmp == 0) continue;
        if (pq.size() < tmp) {
          ret += b[i];
          pq.push(b[i]);
        } else if (pq.top() < b[i]) {
          ret -= pq.top();
          pq.pop();
          ret += b[i];
          pq.push(b[i]);
        }
      }
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
