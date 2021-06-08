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
typedef pair<string, int> psi;
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
#define leftnode (node << 1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)

const int MAXN = 1e5 + 10;
int idxs[MAXN];
vi data[MAXN<<2];

void build(int node, int left, int right) {
  if (left == right) {
    data[node].push_back(idxs[left]);
    return;
  }
  int mid = getmid;
  build(leftnode, left, mid);
  build(rightnode, mid+1, right);
  data[node].reserve(data[leftnode].size() + data[rightnode].size());
  merge(data[leftnode].begin(), data[leftnode].end(),
        data[rightnode].begin(), data[rightnode].end(),
        back_inserter(data[node]));
}

pii get_range(const vector<psi>& data,  string&& s) {
  psi item = make_pair(move(s), 0);
  auto it1 = lower_bound(data.begin(), data.end(), item);
  if (it1 == data.end()) return {-1, -1};
  item.first.push_back('z'+1);
  auto it2 = upper_bound(it1, data.end(), item);
  return {it1-data.begin(), it2-data.begin()};
}

int count(int node, int left, int right, int i, int j, int c, int d) {
  if (right < i || j < left) return 0;
  if (i <= left && right <= j) {
    auto it1 = lower_bound(data[node].begin(), data[node].end(), c);
    auto it2 = upper_bound(it1, data[node].end(), d);
    return it2 - it1;
  }
  int mid = getmid;
  int ret = count(leftnode, left, mid, i, j, c, d);
  ret += count(rightnode, mid+1, right, i, j, c, d);
  return ret;
}


int solve(const vector<psi>& s, const vector<psi>& rs, string&& a, string&& b) {
  pii x = get_range(s, move(a));
  if (x.first == -1) return 0;
  pii y = get_range(rs, move(b));
  if (y.first == -1) return 0;
  int n = s.size()-1;
  return count(1, 1, n, x.first, x.second-1, y.first, y.second-1);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, q; cin >> n >> q;
  vector<psi> s(n+1), rs(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i].first;
    s[i].second = i;
    rs[i].first = s[i].first;
    reverse(rs[i].first.begin(), rs[i].first.end());
    rs[i].second = i;
  }
  sort(s.begin()+1, s.end());
  sort(rs.begin()+1, rs.end());
  vector<int> idx2r(n+1);
  for (int i = 1; i <= n; i++) {
    idx2r[rs[i].second] = i;
  }
  for (int i = 1; i <= n; i++) {
    idxs[i] = idx2r[s[i].second];
  }
  build (1, 1, n);
  while (q--) {
    string a, b; cin >> a >> b;
    reverse(b.begin(), b.end());
    cout << solve(s, rs, move(a), move(b)) << '\n';
  }










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
