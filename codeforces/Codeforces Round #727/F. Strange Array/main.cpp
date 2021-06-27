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
vi val2idx[MAXN];
int mi[MAXN], ma[MAXN], ret[MAXN];
bool used[MAXN];

int find(int m[], int i) {
  if (m[i] == i) return i;
  return m[i] = find(m, m[i]);
}

void add(int i, int j) {
  int tmp_i = find(mi, i);
  int tmp_j = find(mi, j);
  mi[max(tmp_i, tmp_j)] = min(tmp_i, tmp_j);

  tmp_i = find(ma, i);
  tmp_j = find(ma, j);
  ma[min(tmp_i, tmp_j)] = max(tmp_i, tmp_j);
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    val2idx[val].push_back(i);
    mi[i] = i;
    ma[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int idx : val2idx[i]) {
      used[idx] = true;
      if (idx-1 >= 0 && used[idx-1]) add(idx-1, idx);
      if (idx+1 < n && used[idx+1]) add(idx, idx+1);
    }
    for (int idx : val2idx[i]) {
      int x = find(mi, idx);
      int y = find(ma, idx);
      int z = (y-x) / 2;
      ret[idx] = max(ret[idx], z);
    }
  }
  for (int i = 0; i < n; i++) {
    mi[i] = i;
    ma[i] = i;
    used[i] = false;
  }
  for (int i = n; i >= 1; i--) {
    for (int idx : val2idx[i]) {
      used[idx] = true;
      if (idx-1 >= 0 && used[idx-1]) add(idx-1, idx);
      if (idx+1 < n && used[idx+1]) add(idx, idx+1);
    }
    for (int idx : val2idx[i]) {
      int x = find(mi, idx);
      int y = find(ma, idx);
      int z = (y-x+1) / 2;
      ret[idx] = max(ret[idx], z);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ret[i];
    if (i+1 == n) cout << '\n';
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
