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

struct OneHandScheduling{
    string checkSchedule(vector<int> tStart, vector<int> tEnd) {
        map<int, int> idx;
        for (int num : tStart) {
            idx[num] = 0;
        }
        for (int num : tEnd) {
            idx[num] = 0;
        }
        int tot = 0;
        for (auto it = idx.begin(); it != idx.end(); it++) {
            it->second = tot++;
        }
        vector<int> count(tot+1);
        for (int i = 0; i < tStart.size(); i++) {
            count[idx[tStart[i]]]++;
            count[idx[tEnd[i]]+1]--;
        }
        for (int i = 1; i < count.size(); i++) {
            count[i] = count[i-1] + count[i];
        }
        for (int num : count) {
            if (num > 1) {
                return "impossible";
            }
        }
        return "possible";

    }
};






int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    vector<int> s{10, 20};
    vector<int> t{20, 30};
    OneHandScheduling sol;
    cout << sol.checkSchedule(s, t) << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
