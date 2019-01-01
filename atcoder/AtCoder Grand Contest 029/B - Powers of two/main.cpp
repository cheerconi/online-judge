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
LL nums[MAXN];
map<LL, vector<int>> table[32];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n, greater<>());
    for (int i = 0; i < n; i++) {
        int j = 30;
        while (true) {
            if ((1LL<<j) & nums[i]) break;
            j--;
        }
        while (j >= 0) {
            if ((1LL<<j) & nums[i]) j--;
            else break;
        }
        j += 1;
        while (j < 32) {
            LL val = 1LL<<j;
            table[j][nums[i]%val].push_back(i);
            j++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == -1) continue;
        int j = 30;
        while (true) {
            if ((1LL<<j) & nums[i]) break;
            j--;
        }
        j++;
        LL rem = (1LL<<j) - nums[i];
        auto it = table[j].find(rem);
        if (it == table[j].end()) continue;
        while (!it->second.empty()) {
            int k = it->second.back();
            if (k == i && it->second.size() >= 2) {
                int sz = it->second.size();
                swap(it->second[sz-1], it->second[sz-2]);
                k = it->second[sz-1];
            }
            if (nums[k] == -1) {
                it->second.pop_back();
            } else {
                if (k == i) break;
                nums[k] = -1;
                nums[i] = -1;
                it->second.pop_back();
                cnt += 1;
                break;
            }
        }
    }
    cout << cnt << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
