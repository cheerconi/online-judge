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
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
const int mod = 998244353;
const int MAXN = 5e5 + 10;
int x[MAXN], y[MAXN];
struct Mat{
  int data[2][2] = {0};
  Mat operator*(const Mat& rhs) const {
    Mat ret;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          ret.data[i][j] = ((LL)data[i][k] * rhs.data[k][j] % mod + ret.data[i][j]) % mod;
        }
      }
    }
    return ret;
  }

};

Mat tree[MAXN<<2];
string s;

Mat eye;

void build(int node, int left, int right) {
  if (left == right) {
    tree[node].data[0][0] = 0;
    tree[node].data[0][1] = 1;
    tree[node].data[1][0] = y[left];
    tree[node].data[1][1] = x[left];
    return;
  }
  int mid = getmid;
  build(leftnode, left, mid);
  build(rightnode, mid+1, right);
  tree[node] = tree[rightnode] * tree[leftnode];
}

void update(int node, int left, int right, int i) {
  if (left == right) {
    tree[node].data[0][0] = 0;
    tree[node].data[0][1] = 1;
    tree[node].data[1][0] = y[left];
    tree[node].data[1][1] = x[left];
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, i);
  else update(rightnode, mid+1, right, i);
  tree[node] = tree[rightnode] * tree[leftnode];
}

void get_coeff(int i) {
  x[i+1] = s[i] - '0' + 1;
  if (i-1 >= 0 && s[i-1] == '1') {
    int a = 1 + (s[i] - '0');
    int b = 9;
    y[i+1] = b-a+1;
  } else {
    y[i+1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  eye.data[0][0] = 1;
  eye.data[1][1] =1;
  int n, q; cin >> n >> q;
  cin >> s;
  for (int i = 0; i < n; i++) {
    get_coeff(i);
  }
  build (1, 1, n);
  while (q--) {
    int c, d; cin >> c >> d;
    if (s[c-1] - '0' != d) {
      s[c-1] = d + '0';
      get_coeff(c-1);
      update(1, 1, n, c);
      if (c < n) {
        get_coeff(c);
        update(1, 1, n, c+1);
      }
    }
    cout << (tree[1].data[1][1] + tree[1].data[1][0]) % mod << '\n';
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
