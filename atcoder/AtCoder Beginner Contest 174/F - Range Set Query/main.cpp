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
const int MAXN = 5e5 + 10;
int nums[MAXN], tree[MAXN], a[MAXN], b[MAXN], idx[MAXN], pre[MAXN], ret[MAXN];
int n;

int lowbit(int i) {
  return i&(-i);
}
void update(int i, int val) {
  while (i <= n) {
    tree[i] += val;
    i += lowbit(i);
  }
}

int query(int i) {
  int tot = 0;
  while (i > 0) {
    tot += tree[i];
    i -= lowbit(i);
  }
  return tot;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i];
    idx[i] = i;
  }
  sort(idx, idx+q, [](int i, int j){return make_pair(b[i], a[i]) < make_pair(b[j], a[j]);});
  int cur = 1;
  for (int j = 0; j < q; j++) {
    int i = idx[j];
    while (cur <= b[i]) {
      if (pre[nums[cur]] != 0) update(pre[nums[cur]], -1);
      pre[nums[cur]] = cur;
      update(pre[nums[cur]], 1);
      cur++;
    }
    ret[i] = query(b[i]) - query(a[i]-1);
  }
  for (int i = 0; i < q; i++) {
    cout << ret[i] << '\n';
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
