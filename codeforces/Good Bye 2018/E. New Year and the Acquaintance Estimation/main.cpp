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
constexpr int MAXN = 5e5 + 10;
LL  dp[MAXN];
int x, y, n, nums[MAXN], tmp[MAXN], cnt[MAXN];

void add(int num) {
    int flag = -1, idx = 0, i = 0;
    while (idx < n) {
        if (flag == -1 && nums[idx] <= num) {
            flag = 1;
            tmp[i++] = num;
        } else {
            tmp[i++] = nums[idx];
            idx++;
        }
    }
    if (flag == -1) tmp[n] = num;
}
void done() {
    cout << -1 << endl;
    exit(0);
}

int solve(int num) {
    add(num);
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = n; i >= 0; i--) {
        x = 0;
        y = min(tmp[i], i) - 1;
        if (x <= y) {
            cnt[x]++;
            cnt[y+1]--;
        }
        x = tmp[i];
        y = i-1;
        if (x <= y) {
            dp[x] += tmp[i];
            dp[y+1] -= tmp[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i-1];
        cnt[i] += cnt[i-1];
    }
    LL lft = 0, rght;
    for (int i = 0; i <= n; i++) {
        lft += tmp[i];
        rght = (LL)i*(i+1) + (LL)cnt[i]*(i+1) + dp[i];
        if (lft <= rght) continue;
        if (num >= tmp[i]) {
            return 1;
        } else {
            return -1;
        }
    }
    return 2;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        p = (p + nums[i]) % 2;
    }
    sort(nums, nums+n, greater<int>());
    int a = p;
    int b = n;
    if (n % 2 != p) b--;
    int ret1, ret2, ret;
    while (a < b) {
        int mid = (a + b) >> 1;
        if (mid % 2 != p) mid--;
        int val = solve(mid);
        if (val == 2) {
            a = mid;
            b = mid;
            break;
        }
        if (val == -1) a = mid+2;
        else b = mid - 2;
    }
    if (a != b || solve(a) != 2) done();
    ret = a;
    int xx = p, yy = ret;
    while (xx < yy) {
        int mid = (xx + yy) >> 1;
        if (mid % 2 != p) mid--;
        int val = solve(mid);
        if (val == 2) yy = mid;
        else xx = mid + 2;
    }
    ret1 = xx;
    xx = ret;
    yy = n;
    if (n % 2 != p) yy--;
    while (xx < yy) {
        int mid = (xx+yy) >> 1;
        if (mid % 2 != p) mid++;
        int val = solve(mid);
        if (val == 2) xx = mid;
        else yy = mid - 2;
    }
    ret2 = xx;
    while (ret1 <= ret2) {
        cout << ret1;
        if (ret1 == ret2) cout << endl;
        else cout << ' ';
        ret1 += 2;
    }









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
