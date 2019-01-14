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
const int MAXN = 1234;
int nums[MAXN][2], col[MAXN], row[MAXN];
int x, y;

void move(int a, int b) {
    if (a == x && b == y) return;
    int u = x, v = y;
    if (u > a) u--;
    else if (u < a) u++;
    if (v > b) v--;
    else if (v < b) v++;
    if (row[u] != 0) cout << u << ' '  << y << endl;
    else if (col[v] != 0) cout << x << ' ' << v << endl;
    else cout << u << ' ' << v << endl;
    x = u;
    y = v;
    int idx;
    cin >> idx >> u >> v;
    if (idx <= 0) exit(0);
    row[u]++;
    col[v]++;
    row[nums[idx][0]]--;
    col[nums[idx][1]]--;
    nums[idx][0] = u;
    nums[idx][1] = v;
    move(a, b);
}

void solve(int idx) {
    if (idx == 0) move(999, 999);
    if (idx == 1) move(999, 1);
    if (idx == 2) move(1, 999);
    move(1, 1);
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> x >> y;
    for (int i = 1; i <= 666; i++) {
        cin >> nums[i][0] >> nums[i][1];
        row[nums[i][0]]++;
        col[nums[i][1]]++;
    }
    move(500, 500);
    int cnt[4] = {0};
    for (int i = 1; i <= 666; i++) {
        if (nums[i][0] < 500) {
            if (nums[i][1] < 500) cnt[0]++;
            else cnt[1]++;
        } else {
            if (nums[i][1] < 500) cnt[2]++;
            else cnt[3]++;
        }
    }
    int idx = 0;
    for (int i = 1; i < 4; i++) {
        if (cnt[idx] > cnt[i]) idx = i;
    }
    solve(idx);



/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
