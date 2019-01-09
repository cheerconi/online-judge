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
constexpr int MAXN = 2e5 + 10;
int nums[MAXN];
int n;
map<int, int> table;

void split(int idx) {
    if (idx == 0) {
        table.clear();
        return;
    }
    auto it = table.lower_bound(idx);
    table[idx] = it->second;
    table.erase(table.upper_bound(idx), table.end());
}

void insert(int idx, int val) {
    split(idx-1);
    table[idx] = val;
    auto it = table.find(idx);
    while (it != table.begin()) {
        it--;
        if (it->second == val) it = table.erase(it);
        else break;
    }
}



bool solve(int tot) {
    table.clear();
    table[nums[0]] = 1;
    for (int i = 1; i < n; i++) {
        auto it = table.lower_bound(nums[i]);
        if (it == table.end()) {
            table[nums[i]] = 1;
            it = table.find(nums[i]);
            while (it != table.begin()) {
                it--;
                if (it->second == 1) it = table.erase(it);
                else break;
            }
            continue;
        }
        split(nums[i]);
        it = table.find(nums[i]);
        if (it->second == tot && table.begin() == it) return false;
        if (it->second != tot) {
            insert(nums[i], it->second + 1);
        } else {
            it--;
            insert(it->first, it->second+1);
            table[nums[i]] = 1;
            it = table.find(nums[i]);
            while (it != table.begin()) {
                it--;
                if (it->second == 1) it = table.erase(it);
                else break;
            }
        }
    }
    return true;
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
    int a = 1, b = n;
    while (a < b) {
        int mid = (a+b) >> 1;
        if (solve(mid)) b = mid;
        else a = mid + 1;
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
