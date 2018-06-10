#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((i+j) >> 1)
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/


const int MAXN = 1e4 + 10;
bitset<MAXN> tree[MAXN<<2];
bool info[MAXN<<2];
bitset<MAXN> ret;

void update(int node, int i, int j, int a, int b, int c) {
    if (j < a || b < i) return;
    if (info[node] && a <= i && j <= b) {
        tree[node] |= tree[node] << c;
        return;
    }
    int mid = getmid;
    if (info[node]) {
        info[leftnode] = true;
        info[rightnode] = true;
        tree[leftnode] = tree[node];
        tree[rightnode] = tree[node];

    }
    update(leftnode, i, mid, a, b, c);
    update(rightnode, mid+1, j, a, b, c);
    if (info[leftnode] && info[rightnode] && tree[leftnode] == tree[rightnode]) {
        info[node] = true;
        tree[node] = tree[leftnode];
    }
    else info[node] = false;
}

void solve(int node, int i, int j) {
    if (info[node]) {
        ret |= tree[node];
        return;
    }
    int mid = getmid;
    solve(leftnode, i, mid);
    solve(rightnode, mid+1, j);
}



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int n, q;
    cin >> n >> q;
    int a, b, c;
    memset(info, true, sizeof(info));
    for (int i = 0; i < (MAXN<<2); i++) {
        tree[i][0] = 1;
    }
    while (q--) {
        cin >> a >> b >> c;
        update(1, 1, n, a, b, c);
    }
    solve(1, 1, n);
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        if (ret[i] == 1) pos.push_back(i);
    }
    cout << pos.size() << endl;
    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i];
        if (i+1 == pos.size()) cout << endl;
        else cout << ' ';
    }





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
