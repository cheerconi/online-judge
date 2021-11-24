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
#define getmid ((left + right)>>1)
const int MAXN = 1e6 + 10;
pii tree[MAXN<<2];
string s;

pii merge(const pii& a, const pii& b) {
    if (a.first == 0) return b;
    if (b.first == 0) return a;
    pii ret;
    int tmp = (a.second + a.first + 1) % 2;
    if (tmp == b.second) {
        ret.first = abs(a.first - b.first);
        ret.second = a.second;
        if (b.first > a.first) ret.second ^= 1;
    } else {
        ret.first = a.first + b.first;
        ret.second = a.second;
    }
    return ret;
}

void build(int node, int left, int right) {
    if (left == right) {
        tree[node].first = 1;
        if (s[left-1] == '(' || s[left-1] == ')') tree[node].second = 0;
        else tree[node].second = 1;
        return;
    }
    int mid = getmid;
    build(leftnode, left, mid);
    build(rightnode, mid+1, right);
    tree[node] = merge(tree[leftnode], tree[rightnode]);
}

pii query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return {0, 0};
    if (i <= left && right <= j) {
        return tree[node];
    }
    int mid = getmid;
    pii a = query(leftnode, left, mid, i, j);
    pii b = query(rightnode, mid+1, right, i, j);
    pii ret =  merge(a, b);
    return ret;
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        cin >> s;
        int n = s.size();
        build(1, 1, n);
        int q; cin >> q;
        int a, b;
        while (q--) {
            cin >> a >> b;
            cout << query(1, 1, n, a, b).first / 2 << '\n';
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
