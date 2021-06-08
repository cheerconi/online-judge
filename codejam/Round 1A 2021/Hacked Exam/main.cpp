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
const int MAXN = 10;
string s[MAXN];
int score[MAXN], xx[150], yy[150], n, q;

LL gcd(LL a, LL b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}

bool add(vector<int>& cur_score, vector<bool>& cur_ans, bool val) {
  int idx = cur_ans.size();
  for (int i = 0; i < n; i++) {
    int tmp = cur_score[i];
    if ((val && s[i][idx] == 'T') || (!val && s[i][idx]=='F')) {
      tmp++;
    }
    if (tmp > score[i]) return false;
    if (tmp + q - (idx+1) < score[i]) return false;
  }
  cur_ans.push_back(val);
  for (int i = 0; i < n; i++) {
    if ((val && s[i][idx] == 'T') || (!val && s[i][idx]=='F')) {
      cur_score[i]++;
    }
  }
  return true;
}

void solve(vector<int>& cur_score, vector<bool>& cur_ans) {
  if (cur_ans.size() == q) {
    for (int i = 0; i < cur_score.size(); i++) {
      if (score[i] != cur_score[i]) return;
    }
    for (int i = 0; i < q; i++) {
      if (cur_ans[i]) xx[i]++;
      yy[i]++;
    }
    return;
  }
  int idx = cur_ans.size();
  if (add(cur_score, cur_ans, true)) {
    solve(cur_score, cur_ans);
    for (int i = 0; i < n; i++) {
      if (s[i][idx] == 'T') {
        cur_score[i]--;
      }
    }
    cur_ans.pop_back();
  }
  if (add(cur_score, cur_ans, false)) {
    solve(cur_score, cur_ans);
    for (int i = 0; i < n; i++) {
      if (s[i][idx] == 'F') {
        cur_score[i]--;
      }
    }
    cur_ans.pop_back();
  }
}

pll add_ab(pll a, pll b) {
  LL x = a.first * b.second + b.first * a.second;
  LL y = a.second * b.second;
  LL tmp = gcd(x, y);
  x /= tmp;
  y /= tmp;
  return {x, y};
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
    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> s[i] >> score[i];
    }
    vector<int> cur_score(n);
    vector<bool> cur_ans;
    solve(cur_score, cur_ans);
    string ret;
    pll a{0, 1};
    for (int i = 0; i < q; i++) {
      if (xx[i]*2 >= yy[i]) {
        ret.push_back('T');
        a = add_ab(a, {xx[i], yy[i]});
      } else {
        ret.push_back('F');
        a = add_ab(a, {yy[i]-xx[i], yy[i]});
      }
    }
    cout << "Case #" << cs << ": " <<  ret << ' ' << a.first << "/" << a.second << endl;

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
