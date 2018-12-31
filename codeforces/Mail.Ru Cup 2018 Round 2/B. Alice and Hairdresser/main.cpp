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
const int MAXN = 100000 + 10;
LL nums[MAXN];
int par[MAXN];
unordered_set<int> roots;

int find(int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a == b) return;
    par[a] = b;
    roots.erase(a);
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m, L, cmd, p, delta;
    cin >> n >> m >> L;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cin >> nums[i];
        if (nums[i] > L) roots.insert(i);
        if (nums[i-1] > L && nums[i] > L) {
            add(i-1, i);
        }
    }
    while (m--) {
        cin >> cmd;
        if (cmd == 0) {
            cout << roots.size() << endl;
        } else {
            cin >> p >> delta;
            if (nums[p] > L) continue;
            nums[p] += delta;
            if (nums[p] <= L) continue;
            roots.insert(p);
            if (p-1 >= 1 && nums[p-1] > L) {
                add(p-1, p);
            }
            if (p+1 <= n && nums[p+1] > L) {
                add(p, p+1);
            }
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
