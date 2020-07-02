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

const int MAXN = 5e5 + 10;
struct Item{
  bool head;
  int len = 0;
  int8_t type[2] = {};
  int in = 0;
  int cnt[2] = {};
  Item() = default;
  Item(int h) {
    head = h;
    len = 1;
    type[1-h] = 1;
    cnt[1-h] = 1;
  }
};

string s;
Item tree[MAXN<<2][2];
int idx[MAXN<<2], info[MAXN<<2];

Item merge(const Item& x, const Item& y) {
  if (x.len == 0) return y;
  if (y.len == 0) return x;
  Item ret;
  ret.head = x.head;
  ret.len = x.len + y.len;
  if ((x.head+x.len-1)%2 == y.head) ret.len--;
  ret.in = max(x.in, y.in);

  if (x.type[0] == 0 && x.type[1] == 1) {
    if (y.type[0] == 0 && y.type[1] == 1) {
      ret.type[1] = 1;
      ret.cnt[1] = x.cnt[1] + y.cnt[1];
    } else if (y.type[1] == 0) {
      ret.type[0] = 2;
      ret.cnt[0] = x.cnt[1] + y.cnt[0];
    } else {
      ret.type[0] = 2;
      ret.type[1] = y.type[1];
      ret.cnt[0] = x.cnt[1] + y.cnt[0];
      ret.cnt[1] = y.cnt[1];
    }
    return ret;
  }
  if (x.type[0] == 1 && x.type[1] == 0) {
    if (y.type[0] == 0 || y.type[0] == 1) {
      ret.type[0] = 1;
      ret.type[1] = y.type[1];
      ret.cnt[0] = x.cnt[0] + y.cnt[0];
      ret.cnt[1] = y.cnt[1];
    } else if (y.type[1] == 0) {
      ret.type[0] = 1;
      ret.type[1] = 2;
      ret.cnt[0] = x.cnt[0];
      ret.cnt[1] = y.cnt[0];
    } else {
      ret.type[0] = 1;
      ret.type[1] = y.type[1];
      ret.in = max(ret.in, y.cnt[0]);
      ret.cnt[0] = x.cnt[0];
      ret.cnt[1] = y.cnt[1];
    }
    return ret;
  }
  if (x.type[0] == 2 && x.type[1] == 0 && y.type[0] == 2 && y.type[1] == 0) {
    ret.type[0] = 2;
    ret.type[1] = 2;
    ret.cnt[0] = x.cnt[0];
    ret.cnt[1] = y.cnt[0];
    return ret;
  }
  if (x.type[0] == 2 && x.type[1] == 0 && y.type[0] == 1) {
    ret.type[0] = 2;
    ret.type[1] = y.type[1];
    ret.cnt[0] = x.cnt[0] + y.cnt[0];
    ret.cnt[1] = y.cnt[1];
    return ret;
  }
  if (y.type[0] == 0 && x.type[1] == 1) {
    ret.type[0] = x.type[0];
    ret.type[1] = 1;
    ret.cnt[0] = x.cnt[0];
    ret.cnt[1] = x.cnt[1] + y.cnt[1];
    return ret;
  }
  if (y.type[0] == 1 && y.type[1] == 0) {
    ret.type[0] = x.type[0];
    ret.type[1] = 2;
    ret.cnt[0] = x.cnt[0];
    ret.cnt[1] = x.cnt[1] + y.cnt[0];
    return ret;
  }
  if (y.type[0] == 2 && y.type[1] == 0) {
    if (x.type[1] == 1) {
      ret.type[0] = x.type[0];
      ret.type[1] = 2;
      ret.cnt[0] = x.cnt[0];
      ret.cnt[1] = x.cnt[1] + y.cnt[0];
    } else {
      ret.type[0] = x.type[0];
      ret.type[1] = 2;
      ret.in = max(ret.in, x.cnt[1]);
      ret.cnt[0] = x.cnt[0];
      ret.cnt[1] = y.cnt[0];
    }
    return ret;
  }
  ret.type[0] = x.type[0];
  ret.type[1] = y.type[1];
  ret.cnt[0] = x.cnt[0];
  ret.cnt[1] = y.cnt[1];
  if (x.type[1] == 2 && y.type[0] == 2) {
    ret.in = max(ret.in, x.cnt[1]);
    ret.in = max(ret.in, y.cnt[0]);
  } else ret.in = max(ret.in, x.cnt[1] + y.cnt[0]);
  return ret;
}

void build(int node, int left, int right) {
  if (left == right) {
    if (s[left-1] == '>') {
      tree[node][0] = Item(0);
      tree[node][1] = Item(1);
    } else {
      tree[node][0] = Item(1);
      tree[node][1] = Item(0);
    }
    return;
  }
  int mid = getmid;
  build (leftnode, left, mid);
  build (rightnode, mid+1, right);
  tree[node][0] = merge(tree[leftnode][0], tree[rightnode][0]);
  tree[node][1] = merge(tree[leftnode][1], tree[rightnode][1]);
}

void push_down(int node, int left, int right) {
  if (left == right || info[node] == 0) return;
  idx[leftnode] ^= 1;
  idx[rightnode] ^= 1;
  info[leftnode] ^= 1;
  info[rightnode] ^= 1;
  info[node] = 0;
}

void update(int node, int left, int right, int i, int j) {
  if (right < i || j < left) return;
  if (i <= left && right <= j) {
    info[node] ^= 1;
    idx[node] ^= 1;
    return;
  }
  push_down(node, left, right);
  int mid = getmid;
  update(leftnode, left, mid, i, j);
  update(rightnode, mid+1, right, i, j);
  tree[node][idx[node]] = merge(tree[leftnode][idx[leftnode]], tree[rightnode][idx[rightnode]]);
  tree[node][idx[node]^1] = merge(tree[leftnode][idx[leftnode]^1], tree[rightnode][idx[rightnode]^1]);
}

Item query(int node, int left, int right, int i, int j) {
  if (right < i || j < left) return Item();
  if (i <= left && right <= j) {
    return tree[node][idx[node]];
  }
  push_down(node, left, right);
  int mid = getmid;
  Item a = query(leftnode, left, mid, i, j);
  Item b = query(rightnode, mid+1, right, i, j);
  return merge(a, b);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n, q; cin >> n >> q;
  cin >> s;
  build (1, 1, n);
  while (q--) {
    int a, b; cin >> a >> b;
    update(1, 1, n, a, b);
    Item tmp = query(1, 1, n, a, b);
    int ret = max(tmp.cnt[0], tmp.cnt[1]);
    ret = max(ret, tmp.in);
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