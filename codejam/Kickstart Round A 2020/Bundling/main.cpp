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
#include <memory>
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
struct TrieNode{
  int cnt = 0;
  vector<shared_ptr<TrieNode>> nxt;
};

void add(shared_ptr<TrieNode> root, const string& s) {
  root->cnt++;
  auto cur = root;
  for (char c : s) {
    if (cur->nxt.empty()) cur->nxt = vector<shared_ptr<TrieNode>>(26, nullptr);
    if (cur->nxt[c-'A'] == nullptr) cur->nxt[c-'A'] = make_shared<TrieNode>();
    cur = cur->nxt[c-'A'];
    cur->cnt++;
  }
}
int solve(shared_ptr<TrieNode> cur, int k, int value, int& used) {
  if (cur->cnt < k) return 0;
  int ret = 0, cur_used = 0;
  for (auto& p : cur->nxt) {
    if (p != nullptr) ret += solve(p, k, value+1, cur_used);
  }
  ret += (cur->cnt - cur_used) / k * value;
  used += (cur->cnt - cur_used) / k * k + cur_used;
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
    int n, k;
    cin >> n >> k;
    auto root = make_shared<TrieNode>();
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      add(root, s);
    }
    int used = 0;
    int ret = solve(root, k, 0, used);
    assert(used == n);
    cout << "Case #" << cs << ": " << ret << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
