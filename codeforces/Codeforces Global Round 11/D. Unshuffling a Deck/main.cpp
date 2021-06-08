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






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<vi> ret;
  while (true) {
    int a = -1, b = -1;
    for (int i = 0; i < n && a == -1; i++) {
      for (int j = i+1; j < n && a == -1; j++) {
        if (nums[i] == nums[j]+1) {
          a = i;
          b = j;
        }
      }
    }
    if (a == -1) break;
    vector<int> tmp;
    vector<vi> segments;
    if (a-1 >= 0){
      tmp.push_back(a);
      segments.emplace_back(nums.begin(), nums.begin()+a);
    }
    tmp.push_back(1);
    segments.emplace_back(1, nums[a]);
    while (nums[a+1] == nums[a]+1) {
      a++;
      assert(a < b);
      segments.back().push_back(nums[a]);
      tmp.back()++;
    }
    tmp.push_back(b-a);
    segments.emplace_back(nums.begin()+a+1, nums.begin()+b+1);
    if (n-1 > b){
      tmp.push_back(n-1-b);
      segments.emplace_back(nums.begin()+b+1, nums.end());
    }
    ret.push_back(move(tmp));
    vector<int> new_nums;
    for (int i = (int)segments.size()-1; i >= 0; i--) {
      new_nums.insert(new_nums.end(), segments[i].begin(), segments[i].end());
    }
    nums = move(new_nums);
  }
  cout << ret.size() << '\n';
  for (const auto& tmp : ret) {
    cout << tmp.size();
    for (int i = 0; i < tmp.size(); i++) {
      cout << ' ' << tmp[i];
    }
    cout << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
