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
const int bias = 5001;
const int MAXN = 10000 + 10;
struct Item{
    int a, b, c;
    Item(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
};
bool cmpv(const Item& x, const Item& y) {
    return x.c < y.c;
}
bool cmph(const Item& x, const Item& y) {
    return x.a < y.a;
}
vector<Item> v, h;
int tree[MAXN];
int lowbit(int i) {
    return i&(-i);
}
void add(int i) {
    while (i < MAXN) {
        tree[i]++;
        i += lowbit(i);
    }
}
int query(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        a += bias;
        b += bias;
        c += bias;
        d += bias;
        if (a == c) v.emplace_back(b, d, a);
        else h.emplace_back(a, c, b);
    }
    sort(v.begin(), v.end(), cmpv);
    sort(h.begin(), h.end(), cmph);
    LL ret = 0;
    for (int j = 0; j < v.size(); j++) {
        int k = 0;
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < j && v[i].c != v[j].c; i++) {
            for (; k < h.size(); k++) {
                if (h[k].a > v[i].c) break;
                if (h[k].b < v[j].c) continue;
                if (h[k].c > v[j].b || h[k].c < v[j].a) continue;
                add(h[k].c);
            }
            LL cur = query(v[i].b) - query(v[i].a-1);
            ret += cur * (cur-1) / 2;
        }
    }
    cout << ret << endl;


/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
