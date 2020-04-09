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
const int MAXN = 1000 + 10;
pii data[MAXN];
bool cmp(int a, int b) {
  return data[a] < data[b];
}

string solve(const vi& idx) {
  int dp[] = {0, 0};
  string ret(idx.size(), ' ');
  for (int i : idx) {
    if (dp[0] <= data[i].first) {
      dp[0] = data[i].second;
      ret[i] = 'C';
      continue;
    }
    if (dp[1] <= data[i].first) {
      dp[1] = data[i].second;
      ret[i] = 'J';
      continue;
    }
    return "";
  }
  return ret;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n, a, b; cin >> n;
    vi idx;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      data[i] = {a, b};
      idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), cmp);
    string ret = solve(idx);
    cout << "Case #" << cs << ": ";
    if (ret.empty()) cout << "IMPOSSIBLE\n";
    else cout << ret << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
