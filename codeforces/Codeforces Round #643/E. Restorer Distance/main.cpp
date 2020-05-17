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
const int MAXN = 1e5 + 10;
int cnt[MAXN], nums[MAXN];
LL sum[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, a, b, c, val;
  cin >> n >> a >> b >> c;
  map<int, int> table;
  LL xxx = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    table[val]++;
    xxx += val;
  }
  xxx /= n;
  if (table.find(xxx) == table.end()) table[xxx] = 0;
  if (table.find(xxx+1) == table.end()) table[xxx+1] = 0;
  int idx = 1;
  for (const auto& item : table) {
    cnt[idx] += item.second;
    sum[idx] += (LL)item.second * item.first;
    nums[idx] = item.first;
    cnt[idx] += cnt[idx-1];
    sum[idx] += sum[idx-1];
    idx++;
  }
  LL ret = LLONG_MAX;
  for (auto it = table.rbegin(); it != table.rend(); it++) {
    idx--;
    LL rsum = sum[table.size()] - sum[idx];
    LL rcnt = cnt[table.size()] - cnt[idx];
    LL z = it->first;
    LL y = rsum - rcnt * z;
    LL x = cnt[idx] * z - sum[idx];
    LL tmp = a * x + b * y;
    ret = min(ret, tmp);

    if (c >= a + b) continue;
    LL u = min(x, y);
    x -= u;
    y -= u;
    tmp = x * a + y * b + u * c;
    ret = min(tmp, ret);
  }
  cout << ret << endl;










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
