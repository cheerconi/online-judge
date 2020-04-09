/*
ID: txingml
PROG: transform
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
vector<string> roate(const vector<string>& mat) {
  vector<string> ret;
  int n = mat.size();
  for (int j = 0; j < n; j++) {
    string s;
    for (int i = n-1; i >= 0; i--) {
      s.push_back(mat[i][j]);
    }
    ret.push_back(move(s));
  }
  return ret;
}
vector<string> reflex(const vector<string>& mat) {
  auto ret = mat;
  int n = mat.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n/2; j++) {
      swap(ret[i][j], ret[i][n-j-1]);
    }
  }
  return ret;
}

int solve(const vector<string>& mat, const vector<string>& target) {
  vector<string> ret;
  ret = roate(mat);
  if (ret == target) return 1;
  ret = roate(ret);
  if (ret == target) return 2;
  ret = roate(ret);
  if (ret == target) return 3;
  ret = reflex(mat);
  if (ret == target) return 4;
  ret = roate(ret);
  if (ret == target) return 5;
  ret = roate(ret);
  if (ret == target) return 5;
  ret = roate(ret);
  if (ret == target) return 5;
  if (mat == target) return 6;
  return 7;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  int n; cin >> n;
  vector<string> mat, target;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mat.push_back(move(s));
  }
  for (int i = 0; i < n; i++) {
    cin >> s;
    target.push_back(move(s));
  }
  cout << solve(mat, target) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
