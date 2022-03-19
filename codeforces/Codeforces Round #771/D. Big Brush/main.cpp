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
int mat[MAXN][MAXN];
int dx[] = {0, 0, 1, 1};
int dy[] = {1, 0, 1, 0};
vector<vi> ret;
int n, m;

int get(int i, int j) {
    int val = -1;
    for (int k = 0; k < 4; k++) {
        int ii = dx[k] + i;
        int jj = dy[k] + j;
        if (ii < 0 || ii >= n) return -1;
        if (jj < 0 || jj >= m) return -1;
        if (mat[ii][jj] == 0) continue;
        if (val == -1) val = mat[ii][jj];
        else if (val != mat[ii][jj]) return -1;
    }
    return val;
}

void dfs(int i, int j) {
    int val = get(i, j);
    if (val == -1) return;
    ret.push_back({i, j, val});
    for (int k = 0; k < 4; k++) {
        int ii = dx[k] + i;
        int jj = dy[k] + j;
        mat[ii][jj] = 0;
    }
    dfs(i-1, j-1);
    dfs(i-1, j);
    dfs(i-1, j+1);
    dfs(i, j-1);
    dfs(i+1, j-1);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i+1 < n; i++) {
        for (int j = 0; j+1 < m; j++) {
            dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ret.size() << '\n';
    for (int i = (int)ret.size()-1; i >= 0; i--) {
        cout << ret[i][0]+1 << ' ' << ret[i][1]+1 << ' ' << ret[i][2] << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
