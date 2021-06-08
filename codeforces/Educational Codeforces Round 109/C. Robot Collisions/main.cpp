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
typedef pair<int, char> pic;
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
const int MAXN = 3e5 + 10;
int a[MAXN], b[MAXN], ret[MAXN], rk[MAXN];
pic nums[MAXN];
int m;

void insert(int i, int j, priority_queue<vi, vector<vi>, greater<vi>>& pq) {
  int diff = (nums[j].first - nums[i].first)/2;
  if (nums[i].second == 'L' && nums[j].second == 'L') {
    pq.push({diff + nums[i].first, i, j});
  } else if (nums[i].second == 'L' && nums[j].second == 'R') {
    pq.push({diff + nums[i].first + m - nums[j].first, i, j});
  } else if (nums[i].second == 'R' && nums[j].second == 'L') {
    pq.push({diff, i, j});
  } else {
    pq.push({diff + m - nums[j].first, i, j});
  }
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
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    memset(ret, -1, sizeof(ret));
    int n; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> nums[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> nums[i].second;
      rk[i] = i;
    }
    sort(rk, rk+n, [](int i, int j){return nums[i] < nums[j];});
    sort(nums, nums+n);

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    for (int i = 0; i < 2; i++) {
      vector<int> idx;
      for (int j = 0; j < n; j++) {
        if (nums[j].first % 2 == i) idx.push_back(j);
      }
      for (int j = 0; j+1 < idx.size(); j++) {
        a[idx[j+1]] = idx[j];
        b[idx[j]] = idx[j+1];
        insert(idx[j], idx[j+1], pq);
      }
    }
    while (!pq.empty()) {
      const auto item  = pq.top(); pq.pop();
      int x = item[1];
      int y = item[2];
      if (ret[rk[x]] != -1 || ret[rk[y]] != -1) continue;
      ret[rk[x]] = item[0];
      ret[rk[y]] = item[0];
      int xx = a[x];
      int yy = b[y];
      if (xx >= 0) b[xx] = yy;
      if (yy >= 0) a[yy] = xx;
      if (xx >= 0 && yy >= 0) insert(xx, yy, pq);
    }
    for (int i = 0; i < n; i++) {
      cout << ret[i];
      if (i+1 == n) cout << '\n';
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
