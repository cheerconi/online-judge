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

struct OneHandSort2{
    int minMoves(int N, vector<int> targetPrefix, int a, int b) {
        int L = targetPrefix.size();
        vector<int> target(N);
        set<int> nums;
        for (int i = 0; i < N; i++) {
            nums.insert(i);
        }
        for (int i = 0; i < L; i++) {
            target[i] = targetPrefix[i];
            nums.erase(target[i]);
        }
        for (int i = L; i < N; i++) {
            int tmp = (target[i-1]*(LL)a+(LL)b) % N;
            auto it = nums.lower_bound(tmp);
            if (it == nums.end()) {
                it = nums.begin();
            }
            target[i] = *it;
            nums.erase(it);
        }
        int ret = N;
        for (int i = 0; i < N; i++) {
            if (target[i] == i) continue;
            ret++;
            int cur = i;
            while (target[cur] != cur) {
                int tmp = target[cur];
                target[cur] = cur;
                cur = tmp;
            }
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
    OneHandSort2 sol;
    vector<int> pre{5, 9, 8, 7, 6, 0, 3};
    cout << sol.minMoves(10, pre, 0, 1) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
