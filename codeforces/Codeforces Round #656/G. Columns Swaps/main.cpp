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
const int MAXN = 2e5 + 10;
int nums[MAXN*2], par[MAXN*2];
vi idx[MAXN];
vi edges[MAXN*2];
vi cur;

int find(int i) {
  if (par[i] == i) return i;
  return par[i] = find(par[i]);
}

void add(int i, int j) {
  int a = find(i);
  int b = find(j);
  par[a] = b;
}

bool solve(int n) {
  for (int i = 1; i <= n; i++) {
    if (idx[i].size() != 2) return false;
    int a = idx[i][0];
    int b = idx[i][1];
    if (min(a, b) + n == max(a, b)) continue;
    if (a >= n && b >= n) {
      add(a, b-n);
      add(b, a-n);
    } else if (a < n && b < n) {
      add(a, b+n);
      add(b, a+n);
    } else if (a >= n) {
      add(a-n, b);
      add(a, b+n);
    } else {
      add(a, b-n);
      add(a+n, b);
    }
  }
  for (int i = 0; i < n; i++) {
    int a = find(i);
    int b = find(i+n);
    if (a == b) return false;
    edges[a].push_back(i);
    edges[b].push_back(i+n);
  }

  for (int i = 0; i < 2*n; i++) {
    if (edges[i].empty()) continue;
    int tmp = 0;
    for (int nxt : edges[i]) {
      if (nxt >= n) tmp++;
    }
    if (tmp > edges[i].size() - tmp) {
      for (int nxt : edges[i]) {
        if (nxt < n) cur.push_back(nxt);
      }
    } else {
      for (int nxt : edges[i]) {
        if (nxt >= n) cur.push_back(nxt-n);
      }
    }
    if (i >= n) edges[find(i-n)].clear();
    else edges[find(i+n)].clear();
  }
  return true;

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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      idx[i].clear();
    }
    for (int i = 0; i < 2*n; i++) {
      cin >> nums[i];
      idx[nums[i]].push_back(i);
      par[i] = i;
      edges[i].clear();
    }
    cur.clear();
    if (solve(n)) {
      cout << cur.size() << '\n';
      for (int i = 0; i < cur.size(); i++) {
        cout << cur[i] + 1;
        if (i+1 == cur.size()) cout << '\n';
        else cout << ' ';
      }
    } else {
      cout << "-1\n";
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
