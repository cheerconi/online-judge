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
int nums[MAXN], ret[MAXN];

inline LL diff(LL num, LL x) {
  return num - 3 * x * x + 3 * x - 1;
}

int get(int num, LL delta) {
  LL a = 0, b = num;
  while (a < b) {
    LL mid = (a+b+1) >> 1;
    LL value = diff(num, mid);
    if (value < delta) b = mid - 1;
    else a = mid;
  }
  return a;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n;
  LL k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  LL a = 1e9;
  a =  3 * a * (1 - a);
  LL b = 1e9;
  while (a < b) {
    LL mid = (a+b) >> 1;
    LL sum = 0;
    for (int i = 0; i < n; i++) {
      sum += get(nums[i], mid);
      if (sum > k) break;
    }
    if (sum > k) a = mid+1;
    else b = mid;
  }
  for (int i = 0; i < n; i++) {
    ret[i] = get(nums[i], a);
    k -= ret[i];
  }
  for (int i = 0; i < n && k > 0; i++) {
    if (ret[i] == nums[i]) continue;
    if (diff(nums[i], ret[i]+1) == a-1) {
      ret[i]++;
      k--;
    }
  }
  assert(k == 0);
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
