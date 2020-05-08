/*
ID: txingml
PROG: milk3
LANG: C++
*/
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
bool dp[21][21][21];






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);
  int nums[3];
  for (int i = 0; i < 3; i++) cin >> nums[i];
  dp[0][0][nums[2]] = true;
  queue<vi> q;
  q.push({0, 0, nums[2]});
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int i = 0; i < 3; i++) {
      if (cur[i] == 0) continue;
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        auto tmp = cur;
        int val = min(cur[i], nums[j] - cur[j]);
        tmp[i] -= val;
        tmp[j] += val;
        if (dp[tmp[0]][tmp[1]][tmp[2]]) continue;
        q.push(tmp);
        dp[tmp[0]][tmp[1]][tmp[2]] = true;
      }
    }
  }
  set<int> table;
  for (int i = 0; i <= nums[1]; i++) {
    for (int j = 0; j <= nums[2]; j++) {
      if (dp[0][i][j]) table.insert(j);
    }
  }
  int cnt = 0;
  for (auto num : table) {
    cout << num;
    cnt++;
    if (cnt == table.size()) cout << '\n';
    else cout << ' ';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
