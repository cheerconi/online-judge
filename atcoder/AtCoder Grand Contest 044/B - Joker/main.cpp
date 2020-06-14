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
const int MAXN = 512;
int mat[MAXN][MAXN], n;
bool emp[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void update(int i, int j) {
  for (int k = 0; k < 4; k++) {
    int a = i + dx[k];
    int b = j + dy[k];
    if (a < 0 || b < 0 || a >= n || b >= n) continue;
    int val = mat[i][j] + (1 - emp[a][b]);
    if (mat[a][b] > val) {
      mat[a][b] = val;
      update(a, b);
    }
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = min(i+1, n-i);
      mat[i][j] = min(mat[i][j], min(j+1, n-j));
    }
  }
  int val, ret = 0;
  for (int k = 0; k < n*n; k++) {
    cin >> val;
    val--;
    int i = val / n;
    int j = val % n;
    emp[i][j] = true;
    mat[i][j]--;
    update(i, j);
    ret += mat[i][j];
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
