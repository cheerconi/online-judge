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
const int MAXN = 5e5 + 10;
struct Node{
    Node* par = nullptr;
    int val = -1;
};
vector<Node*> val2node[MAXN];
Node* idx2node[MAXN];

Node* find(Node* cur) {
    if (cur->par == cur) return cur;
    return cur->par = find(cur->par);
}

void add(Node* a, Node* b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    a->par = b;
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q; cin >> q;
    int n = 0;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int val; cin >> val;
            Node* node = new Node;
            node->val = val;
            node->par = node;
            val2node[val].push_back(node);
            idx2node[n] = node;
            n++;
        } else {
            int x, y; cin >> x >> y;
            Node* b = new Node;
            b->val = y;
            b->par = b;
            while (!val2node[x].empty()) {
                Node* a = val2node[x].back(); val2node[x].pop_back();
                add(a, b);
            }
            val2node[y].push_back(b);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << find(idx2node[i])->val;
        if (i+1 == n) cout << '\n';
        else cout << ' ';
    }




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
