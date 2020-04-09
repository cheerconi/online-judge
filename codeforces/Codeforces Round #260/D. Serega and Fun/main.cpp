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
int cnt[320][MAXN];
deque<int> data[320];

int block, n;

int remove(int ii) {
  int idx = ii / block;
  int i = ii - block*idx;
  int val = data[idx][i];
  cnt[idx][val]--;
  data[idx].erase(data[idx].begin() + i);
  for (int b = idx+1; ; b++) {
    if (b*block >= n) break;
    cnt[b][data[b][0]]--;
    cnt[b-1][data[b][0]]++;
    data[b-1].push_back(data[b][0]);
    data[b].pop_front();
  }
  return val;
}

void insert(int ii, int val) {
  int idx = ii / block;
  if (ii == n) {
    cnt[idx][val]++;
    data[idx].push_back(val);
    return;
  }
  int i = ii - block * idx;
  cnt[idx][val]++;
  data[idx].insert(data[idx].begin()+i, val);
  for (int b = idx; ;b++) {
    if (data[b].size() < block) break;
    cnt[b][data[b].back()]--;
    cnt[b+1][data[b].back()]++;
    data[b+1].push_front(data[b].back());
    data[b].pop_back();
  }
}

int query(int a, int b, int k) {
  int i = a, ret = 0;

  while (i < b) {
    int idx = i / block;
    if (i % block == 0 && i+block <= b) {
      ret += cnt[idx][k];
      i += block;
    } else {
      ret += (data[i/block][i-idx*block] == k);
      i++;
    }
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
  int val;
  cin >> n;
  block = sqrt(n) + 1;
  for (int i = 0; i < n; i++) {
    cin >> val;
    cnt[i/block][val]++;
    data[i/block].push_back(val);
  }
  int q; cin >> q;
  int seed = 0, cmd, a, b, k;
  while (q--) {
    cin >> cmd >> a >> b;
    a = (a+seed - 1) % n;
    b = (b+seed - 1) % n;
    if (a > b) swap(a, b);
    if (cmd == 1) {
      val = remove(b);
      insert(a, val);

    } else {
      cin >> k;
      k = (k + seed - 1) % n + 1;
      seed = query(a, b+1, k);
      cout << seed << '\n';


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
