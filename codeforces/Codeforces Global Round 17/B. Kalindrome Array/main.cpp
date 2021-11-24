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
int nums[MAXN];
vector<int> tmp;

bool check(int n, int x) {
    tmp.clear();
    for (int i = 0; i < n; i++) {
        if (nums[i] != x) tmp.push_back(nums[i]);
    }
    int m = tmp.size();
    for (int i = 0; i < m-1-i; i++) {
        if (tmp[i] != tmp[m-1-i]) return false;
    }
    return true;

}

bool solve(int n) {
    for (int i = 0; i < n-1-i; i++) {
        if (nums[i] != nums[n-1-i]) {
            if (check(n, nums[i])) return true;
            if (check(n, nums[n-1-i])) return true;
            return false;
        }
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
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> nums[i];
        if (solve(n)) cout << "YES\n";
        else cout << "NO\n";
    }




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
