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
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)

const int MAXN = 2e5 + 10;
const int MAXM = 1e4 + 10;
int a[MAXN], b[MAXN], t[MAXN];
int sum[MAXM<<2], cnt[MAXM<<2];
bool used[MAXN];

void update(int node, int left, int right, int val) {
  if (left == right) {
    sum[node] += val;
    cnt[node]++;
    return;
  }
  int mid = getmid;
  if (val <= mid) update(leftnode, left, mid, val);
  else update(rightnode, mid+1, right, val);
  sum[node] += val;
  cnt[node]++;
}

int query(int node, int left, int right, int k) {
  assert(k <= cnt[node]);
  if (left == right) {
    return k * left;
  }
  int mid = getmid;
  if (cnt[leftnode] <= k) return sum[leftnode] + query(rightnode, mid+1, right, k-cnt[leftnode]);
  else return query(leftnode, left, mid, k);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> dp[3], dpp[3];
  int N = 1e4;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> a[i] >> b[i];
    if (a[i] == 0 && b[i] == 0) {
      update(1, 1, N, t[i]);
    } else if (a[i] == 0) {
      dp[1].push_back(i);
    } else if (b[i] == 0) {
      dp[0].push_back(i);
    } else {
      dp[2].push_back(i);
    }
  }
  for (int i = 0; i < 3; i++) {
    sort(dp[i].begin(), dp[i].end(), [](int x, int y){return t[x] < t[y];});
    for (int num : dp[i]) {
      dpp[i].push_back(t[num]);
      if (dpp[i].size() >= 2) dpp[i].back() += dpp[i][dpp[i].size()-2];
    }
  }
  for (int i = k+1; i < dp[0].size(); i++) {
    update(1, 1, N, t[dp[0][i]]);
  }
  for (int i = k+1; i < dp[1].size(); i++) {
    update(1, 1, N, t[dp[1][i]]);
  }
  pii ret = {INT_MAX, -1};
  for (int i = 0; i <= dp[2].size(); i++) {
    int j = k-i;
    if (j < dp[0].size() && j >= 0) update(1, 1, N, t[dp[0][j]]);
    if (j < dp[1].size() && j >= 0) update(1, 1, N, t[dp[1][j]]);
    if (j > (int)dp[0].size() || j > (int)dp[1].size()) continue;
    int rem = m - i;
    if (j > 0) rem -= j*2;
    if (rem < 0 || cnt[1] < rem) continue;
    int tmp = query(1, 1, N, rem);
    if (j-1 >= 0) tmp += dpp[0][j-1] + dpp[1][j-1];
    if (i-1 >= 0) tmp += dpp[2][i-1];
    if (tmp < ret.first) {
      ret.first = tmp;
      ret.second = i;
    }
  }
  if (ret.first == INT_MAX) {
    cout << -1 << '\n';
  } else {
    cout << ret.first << '\n';
    for (int i = 0; i < ret.second; i++) {
      used[dp[2][i]] = true;
    }
    for (int i = 0; i < k - ret.second; i++) {
      used[dp[1][i]] = true;
      used[dp[0][i]] = true;
    }
    dp[0].clear();
    for (int i = 0; i < n; i++) {
      if (!used[i]) dp[0].push_back(i);
    }
    sort(dp[0].begin(), dp[0].end(), [](int i, int j){return t[i] < t[j];});
    for (int i = 0; i < m-(ret.second+max((k-ret.second)*2, 0)); i++) {
      assert(i < dp[0].size());
      used[dp[0][i]] = true;
    }
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        m--;
        cout << i+1;
        if (m == 0) cout << '\n';
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
