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

const int MAXN = 1e5 + 10;
vector<string> subseq;
const int MAXB = 5;
int tree[MAXN<<2][1<<MAXB];
int table[1<<MAXB][1<<MAXB];
string s;

void merge(int node, int left, int right) {
    int mask = 1<<MAXB;
    for (int i = 0; i < mask; i++) {
        tree[node][i] = -1;
    }
    for (int i = 0; i < mask; i++) {
        if (tree[leftnode][i] == -1) continue;
        for (int j = 0; j < mask; j++) {
            if (tree[rightnode][j] == -1) continue;
            int k = table[i][j];
            if (k == -1) continue;
            int value = tree[leftnode][i] + tree[rightnode][j];
            if (tree[node][k] == -1 || tree[node][k] > value) {
                tree[node][k] = value;
            }
        }
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        for (int i = 0; i < 3; i++) {
            tree[node][1<<i] = 1;
        }
        int value = s[left-1] - 'a';
        tree[node][1<<value] = 0;
        return;
    }
    int mid = getmid;
    build(leftnode, left, mid);
    build(rightnode, mid+1, right);
    merge(node, left, right);
}

void update(int node, int left, int right, int i) {
    if (left == right) {
        for (int j = 0; j < 3; j++) {
            tree[node][1<<j] = 1;
        }
        int value = s[left-1] - 'a';
        tree[node][1<<value] = 0;
        return;
    }
    int mid = getmid;
    if (i <= mid) update(leftnode, left, mid, i);
    else update(rightnode, mid+1, right, i);
    merge(node, left, right);
}

int query() {
    int ret = INT_MAX;
    int mask = 1<<MAXB;
    for (int i = 0; i < mask; i++) {
        if (tree[1][i] != -1) ret = min(ret, tree[1][i]);
    }
    return ret;
}

vector<string> mask2seq(int mask) {
    vector<string> ret;
    for (int i = 0; i < MAXB; i++) {
        if (mask & (1<<i)) {
            ret.push_back(subseq[i]);
        }
    }
    return ret;
}

bool contain(const string& full, const string& sub) {
    int i = 0;
    for (char c : full) {
        if (i < sub.size() && sub[i] == c) i++;
    }
    return i == sub.size();
}

int seq2mask(const string& a) {
    int mask = 0;
    for (int i = 0; i < MAXB; i++) {
        if (contain(a, subseq[i])) mask |= 1<<i;
    }
    return mask;

}

void init() {
    subseq.push_back("a");
    subseq.push_back("b");
    subseq.push_back("c");
    subseq.push_back("ab");
    subseq.push_back("bc");
    int mask = 1<<MAXB;
    for (int i = 0; i < mask; i++) {
        vector<string> as = mask2seq(i);
        for (int j = 0; j < mask; j++) {
            vector<string> bs = mask2seq(j);
            int k = i | j;
            for (const string& a : as) {
                if (k == -1) break;
                for (const string& b : bs) {
                    string c = a + b;
                    if (contain(c, "abc")) {
                        k = -1;
                        break;
                    }
                    k |= seq2mask(c);
                }
            }
            table[i][j] = k;
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
    init();
    memset(tree, -1, sizeof(tree));
    int n, q; cin >> n >> q;
    cin >> s;
    build(1, 1, n);
    int i;
    char c;
    while (q--) {
        cin >> i >> c;
        if (s[i-1] != c) {
            s[i-1] = c;
            update(1, 1, n, i);
        }
        cout << query() << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
