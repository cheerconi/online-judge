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
const int MAXN = 1e5 + 10;
int nums[MAXN], dp[MAXN], tree[MAXN<<1];
LL n;
int lowbit(int i) {
    return i&(-i);
}
LL query(int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
void add(int i) {
    while (i < (MAXN<<1)) {
        tree[i]++;
        i += lowbit(i);
    }
}
LL solve(LL val) {
    for (int i = 1; i <= n; i++) {
        if (nums[i-1] >= val) dp[i] = 1;
        else dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i-1];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] += MAXN;
    }
    memset(tree, 0, sizeof(tree));
    LL ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += query(dp[i]);
        add(dp[i]);
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (n == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    LL a = 1, b = 1e9;
    LL tot = n * (n+1) / 2 + 1;

    while (a < b) {
        LL mid = (a+b + 1) >> 1;
        if (solve(mid) >= tot/2) a = mid;
        else b = mid - 1;
    }
    cout << a << endl;


/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
