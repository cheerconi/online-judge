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
const int MAXN = 123;
int nums[MAXN], dist[MAXN];
vi edges[MAXN];
int ret[MAXN][MAXN];
int as[1234], bs[1234];
pii dp[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    memset(ret, -1, sizeof(ret));
    int c, d;
    cin >> c >> d;
    edges[1].clear();
    for (int i = 2; i <= c; i++) {
      edges[i].clear();
      cin >> nums[i];
    }
    for (int i = 0; i < d; i++) {
      cin >> as[i];
      cin >> bs[i];
      edges[as[i]].push_back(bs[i]);
      edges[bs[i]].push_back(as[i]);
    }
    map<int, vi> table1, table2;
    for (int i = 2; i <= c; i++) {
      if (nums[i] < 0) table1[-nums[i]].push_back(i);
      else table2[nums[i]].push_back(i);
      dist[i] = -1;
    }
    int cnt = 1, pre = 0;
    auto it1 = table1.begin();
    vector<vi> data;
    for (auto it2 = table2.begin(); it2 != table2.end(); it2++) {
      while (it1 != table1.end() && it1->first == cnt) {
        cnt += it1->second.size();
        data.push_back(it1->second);
        for (int num : it1->second) {
          dp[num].first = pre+1;
          dp[num].second = it2->first;
        }

        it1++;
      }
      cnt += it2->second.size();
      data.push_back(it2->second);
      for (int num : it2->second) {
        dp[num].first = it2->first;
        dp[num].second = it2->first;
      }
      pre = it2->first;
    }
    while(it1 != table1.end()) {
      assert(cnt == it1->first);
      cnt += it1->second.size();
      data.push_back(it1->second);
      for (int num : it1->second) {
        dp[num].first = pre+1;
        dp[num].second = 1e6;
      }
      it1++;
    }
    assert(cnt == c);
    int cur = 0;
    for (const vi& vs : data) {
      int val = max(cur+1, dp[vs[0]].first);
      val = min(val, dp[vs[0]].second);
      for (int num : vs) {
        for (int nxt : edges[num]) {
          if (dist[nxt] == -1) continue;
          ret[nxt][num] = val - dist[nxt];
          ret[num][nxt] = val - dist[nxt];
          dist[num] = val;
          assert(val - dist[nxt] > 0);
          break;
        }
      }
      cur = val;
    }
    cout << "Case #" << cs << ": ";
    for (int i = 0; i < d; i++) {
      if (ret[as[i]][bs[i]] == -1) cout << 1000000;
      else cout << ret[as[i]][bs[i]];
      if (i+1 == d) cout << '\n';
      else cout << ' ';
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
