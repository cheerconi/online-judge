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

struct OneHandSort{
    void solve(vector<int>& ret, map<int, int>& nums) {
        auto it = nums.begin();
        while (it->second != -1) {
            ret.push_back(it->second);
            it->second = -1;
            it = nums.find(ret.back());
        }
    }
    void dfs(map<int, int>& nums, vector<int>& target, int i) {
        if (target[i] == i) return;
        nums[target[i]] = i;
        target[i] = i;
        dfs(nums, target, nums.rbegin()->first);

    }
    vector <int> sortShelf(vector <int> target) {
        vector<int> ret;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == i) continue;
            map<int, int> nums;
            nums[target[i]] = i;
            dfs(nums, target, nums.rbegin()->first);
            solve(ret, nums);
            ret.push_back(target.size());
        }

        return ret;
    }
};





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    vector<int> target{1, 2, 0, 4, 3};
    OneHandSort sol;
    auto ret = sol.sortShelf(target);






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
