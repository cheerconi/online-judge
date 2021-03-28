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
int Q, N;
vi nums;
int read() {
  int val; cin >> val;
  return val;
}
void write(const vi& tmp) {
  if (tmp.size() == 3) Q--;
  if (Q == -1) {
    exit(0);
  }
  set<int> table;
  for (int i = 0; i < tmp.size(); i++) {
    if(!table.insert(tmp[i]).second) {
      exit(0);
    }
    assert(tmp[i] <= N);
    cout << tmp[i];
    if (i+1 == tmp.size()) cout << endl;
    else cout << ' ';
  }
}

void solve(int a, int b, int val) {
  if (a == b) {
    nums.insert(nums.begin()+a, val);
    return;
  }
  if (a+1 == b) {
    if (nums[b] != N+1) {
      write({nums[a], nums[b], val});
      int tmp = read();
      if (tmp == -1) exit(0);
      if (tmp == val) {
        nums.insert(nums.begin()+b, val);
      } else if (tmp == nums[a]){
        nums.insert(nums.begin()+a, val);
      }
    } else {
      write({nums[a], nums[a-1], val});
      int tmp = read();
      if (tmp == -1) exit(0);
      if (tmp == nums[a]) {
        nums.insert(nums.begin() + b, val);
      } else if (tmp == val) {
        nums.insert(nums.begin() + a, val);
      }
    }
    return;
  }
  if (a+2 == b) {
    write({nums[a], nums[a+1], val});
    int tmp = read();
    if (tmp == -1) {
      exit(0);
    }
    if (tmp == nums[a]) {
      nums.insert(nums.begin()+a, val);
    } else if (tmp == nums[a+1]) {
      nums.insert(nums.begin()+b, val);
    } else {
      nums.insert(nums.begin()+a+1, val);
    }
    return;
  }
  if (a+3 == b) {
    write({nums[a], nums[a+2], val});
    int tmp = read();
    if (tmp == -1) {
      exit(0);
    }
    if (tmp == nums[a]) {
      nums.insert(nums.begin()+a, val);
    } else if (tmp == nums[a+2]) {
      nums.insert(nums.begin()+b, val);
    } else {
      solve(a+1, a+2, val);
    }
    return;
  }
  int tot = b - a - 1;
  vi seg(3, tot/3);
  if (seg[0] + seg[1] + seg[2] < tot) seg[0]++;
  if (seg[0] + seg[1] + seg[2] < tot) seg[1]++;
  if (seg[0] + seg[1] + seg[2] != tot) {
    exit(0);
  }
  int x = a + seg[0];
  int y = x + seg[1] + 1;
  write({nums[x], nums[y], val});
  int tmp = read();
  assert(tmp != -1);
  if (tmp == nums[x]) {
    solve(a, x, val);
  } else if (tmp == nums[y]) {
    solve(y+1, b, val);
  } else {
    solve(x+1, y, val);
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T;
  cin >> T >> N >> Q;
  while (T--) {
    nums = vi{1, 2, 3, N+1};
    write({1, 2, 3});
    int tmp = read();
    if (tmp == -1) {
      exit(0);
    }
    if (nums[0] == tmp) swap(nums[0], nums[1]);
    if (nums[2] == tmp) swap(nums[2], nums[1]);
    for (int i = 4; i <= N; i++) {
      solve(0, i-1, i);
    }
    assert(nums.back() == N+1);
    nums.pop_back();
    write(nums);
    if(read() != 1) {
      exit(0);
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
