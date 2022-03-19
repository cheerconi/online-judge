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
bool state[MAXN];
int n;
string s;
void solve(int i, int& cnt) {
    if (i < 0 || i+2 >= n) return;
    bool flag = false;
    if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
       flag = true;
    }
    if (state[i] == flag) return;
    cnt -= state[i];
    cnt += flag;
    state[i] = flag;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q; cin >> n >> q;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i+2 < n; i++) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            state[i] = true;
            cnt++;
        }
    }
    int idx;
    char c;
    while (q--) {
        cin >> idx >> c;
        idx--;
        if (s[idx] == c) {
            cout << cnt << '\n';
            continue;
        }
        s[idx] = c;
        solve(idx-2, cnt);
        solve(idx-1, cnt);
        solve(idx, cnt);
        cout << cnt << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
