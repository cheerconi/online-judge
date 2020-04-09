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
int sa[MAXN], rk[MAXN], height[MAXN], nums[MAXN], n;

int cmp(int i, int j, int base) {
    int ret = max(base, 0);
    while (max(i, j) + ret < n) {
        if (nums[i+ret] == nums[j+ret]) {
            ret++;
        } else {
            break;
        }
    }
    return ret;
}

void build() {
    for (int i = 0; i < n; i++) {
        rk[i] = nums[i];
    }
    int len = 1;
    while (true) {
        map<pii, vector<int>> table;
        for (int j = 0; j < n; j++) {
            int k = j + len;
            if (k > n) k = n;
            table[make_pair(rk[j], rk[k])].push_back(j);
        }
        int tmp = 1;
        for (auto it = table.begin(); it != table.end(); it++) {
            for (int idx : it->second) {
                rk[idx] = tmp;
            }
            tmp++;
        }
        if (tmp == n+1) break;
        len <<= 1;
    }
    for (int i = 0; i <= n; i++) {
        sa[rk[i]] = i;
    }
    height[rk[0]] = cmp(0, sa[rk[0]-1], 0);
    for (int i = 1; i < n; i++) {
        height[rk[i]] = cmp(i, sa[rk[i]-1], height[rk[i-1]]-1);
    }
}

bool solve(int k) {
    int ma = INT_MIN, mi = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (height[i] < k) {
            if (ma != INT_MIN) {
                if (ma - mi >= k) return true;
            }
            ma = INT_MIN;
            mi = INT_MAX;
        } else {
            ma = max(ma, sa[i]);
            ma = max(ma, sa[i-1]);
            mi = min(mi, sa[i]);
            mi = min(mi, sa[i-1]);
        }
    }
    if (ma != INT_MIN) {
        if (ma - mi >= k) return true;
    }
    return false;


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
    build();
    int a = 0, b = n/2;
    while (a < b) {
        int mid = (a + b + 1) >> 1;
        if (solve(mid)) {
            a = mid;
        } else {
            b = mid - 1;
        }
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
