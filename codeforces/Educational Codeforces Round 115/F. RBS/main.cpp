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
const int MAXN = 4e5 + 10;
const int MAXM = 20;
int table[MAXM][MAXN<<1];
int state[1<<MAXM];
int needs[MAXM];
int values[1<<MAXM][2];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    memset(values, -1, sizeof(values));
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int mask_i = 1<<i;
        string s; cin >> s;
        for (char c : s) {
            if (c == '(') state[mask_i]++;
            else state[mask_i]--;
            needs[i] = min(needs[i], state[mask_i]);
            if (state[mask_i] <= 0 && -state[mask_i] >= -needs[i]) {
                table[i][state[mask_i]+MAXN]++;
            }
        }
        values[mask_i][0] = table[i][MAXN];
        if (needs[i] == 0) values[mask_i][1] = table[i][MAXN];
    }
    int mask = 1<<n;
    vector<int> idxes(mask-1);
    iota(idxes.begin(), idxes.end(), 1);
    sort(idxes.begin(), idxes.end(), [](int i, int j){
        return __builtin_popcount(i) < __builtin_popcount(j);
    });
    for (int mask_i : idxes) {
        if (values[mask_i][1] == -1) continue;
        for (int j = 0; j < n; j++) {
            int mask_j = 1<<j;
            if (mask_i&mask_j) continue;
            state[mask_i|mask_j] = state[mask_i] + state[mask_j];
            values[mask_i|mask_j][0] = max(values[mask_i|mask_j][0], values[mask_i][1] + table[j][MAXN - state[mask_i]]);
            if (needs[j] + state[mask_i] >= 0) {
                values[mask_i|mask_j][1] = max(values[mask_i|mask_j][1], values[mask_i][1] + table[j][MAXN - state[mask_i]]);
            }

        }
    }
    int ret = 0;
    for (int i = 1; i < mask; i++) {
        ret = max(ret, values[i][0]);
        ret = max(ret, values[i][1]);
    }
    cout << ret << '\n';





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
