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
const int MAXN = 1000 + 10;
bool ban[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;

inline bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !ban[i][j];
}

LL count(int i, int j, int idx1, int idx2, int first_step, int step) {
    int ret = 0;
    while (first_step--) {
        i += dx[idx1];
        j += dy[idx1];
        if (!check(i, j)) return 0;
        swap(idx1, idx2);
    }
    while (check(i, j)) {
        ret++;
        for (int k = 0; k < step; k++) {
            i += dx[idx1];
            j += dy[idx1];
            if (!check(i, j)) return ret;
            swap(idx1, idx2);
        }
    }
    return ret;
}

LL solve(int x, int y) {
    LL tmp1 =  count(x, y, 1, 2, 1, 2);
    LL tmp2 =  count(x, y, 2, 1, 2, 2);
    LL tmp3 =  count(x, y, 0, 3, 1, 1);
    LL tmp4 = count(x, y, 3, 0, 1, 1);

    LL tmp5 =  count(x, y, 1, 2, 2, 2);
    LL tmp6 = count(x, y, 2, 1, 1, 2);
    LL tmp7 = count(x, y, 3, 0, 1, 1);
    LL tmp8 = count(x, y, 0, 3, 1, 1);

    return tmp1 * (tmp4 + 1) + (tmp2 +1) * (tmp3 + 1) + (tmp5 + 1) * (tmp7 + 1) + tmp6 * (tmp8 + 1) - 1;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q; cin >> n >> m >> q;
    LL ret = -n*m;
    for (int i = 0; i < n; i++) {
        int len_i = n - i;
        for (int j = 0; j < m; j++) {
            int len_j = m - j;
            ret += min(len_i * 2, len_j * 2 - 1);
            ret += min(len_i * 2 - 1, len_j * 2);
        }
    }
    while (q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        ban[x][y] = !ban[x][y];
        if (ban[x][y]) ret -= solve(x, y);
        else ret += solve(x, y);
        cout << ret << '\n';
    }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
