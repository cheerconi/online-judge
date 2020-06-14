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
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int factor[MAXN], cnt[MAXN];
map<int, int> table;
vi nums;

LL power(LL base, int p) {
  base = base % mod;
  LL ret = 1;
  while (p) {
    if (p&1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}

void solve(map<int, int>::iterator it, int cur) {
  if (it == table.end()) {
    nums.push_back(cur);
    return;
  }
  for (int i = 0; i <= it->second; i++) {
    auto it2 = it;
    it2++;
    solve(it2, cur);
    cur *= it->first;
  }
}

int get(int a, int b) {
  return cnt[b] - cnt[a-1];
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < MAXN; i++) {
    if (factor[i] != 0) continue;
    for (int j = i+i; j < MAXN; j += i) {
      factor[j] = i;
    }
  }
  int n, m = 0, val; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    cnt[val]++;
    m = max(val, m);
  }
  for (int i = 1; i <= m; i++) {
    cnt[i] += cnt[i-1];
  }
  LL ret = 1;
  for (int i = 2; i <= m; i++) {
    table.clear();
    val = i;
    while(factor[val] > 0) {
      table[factor[val]]++;
      val = val / factor[val];
    }
    if (val > 1) table[val]++;
    nums.clear();
    solve(table.begin(), 1);
    sort(nums.begin(), nums.end());
    LL tmp = get(nums.back(), m);
    tmp = (power(nums.size(), tmp) - power(nums.size()-1, tmp)) % mod;
    if (tmp < 0) tmp += mod;
    for (int j = 0; j+1 < nums.size(); j++) {
      LL x = get(nums[j], nums[j+1]-1);
      tmp = tmp * power(j+1, x) % mod;
    }
    ret = (tmp + ret) % mod;
  }
  cout << ret << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
