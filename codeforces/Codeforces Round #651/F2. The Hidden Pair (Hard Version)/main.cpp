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
const int MAXN = 1234;
vi edges[MAXN];
vi nums;
int node, dist, deep[MAXN];

void ask(int i, int j) {
  cout << "? " <<  j-i + 1;
  for (int k = i; k <= j; k++) {
    cout << ' ' << nums[k];
  }
  cout << endl;
  cin >> node >> dist;
  assert(node != -1);
}

void bfs(int root) {
  memset(deep, -1, sizeof(deep));
  nums.clear();
  queue<int> q;
  q.push(root);
  deep[root] = 0;
  nums.push_back(root);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : edges[cur]) {
      if (deep[nxt] != -1) continue;
      q.push(nxt);
      deep[nxt] = deep[cur] + 1;
      nums.push_back(nxt);
    }
  }

}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    nums.clear();
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      nums.push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    ask(0, n-1);
    int root = node;
    int md = dist;
    bfs(root);
    int a = 0, b = n-1;
    while (deep[nums.back()] > md/2) {
      nums.pop_back();
      b--;
    }
    while (a < b) {
      int mid = (a+b) >> 1;
      ask(mid+1, b);
      if (dist == md) a = mid+1;
      else b = mid;
    }
    int ret1 = nums[a];
    bfs(ret1);
    nums.clear();
    for (int i = 1; i <= n; i++) {
      if (deep[i] == md) nums.push_back(i);
    }
    if (nums.size() != 1) {
      ask(0, nums.size()-1);
    } else {
      node = nums[0];
    }
    cout << "! " <<  ret1 << ' ' << node << endl;
    string s; cin >> s;
    assert(s == "Correct");
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
