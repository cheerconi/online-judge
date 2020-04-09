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

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class SaturdayNightStay{
public:
    int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth) {
        int current = 0;
        firstDay--;
        firstMonth--;
        lastDay--;
        lastMonth--;
        vector<int> nums;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < days[i]; j++) {
                current = (current+1) % 7;
                if (i < firstMonth) continue;
                if (i > lastMonth) continue;
                if (i == lastMonth && j > lastDay) continue;
                if (i == firstMonth && j < firstDay) continue;
                nums.push_back(0);
                if (current != 5) continue;
                nums.back() = 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                if (val != 0) ret++;
                val += nums[j];
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
    auto sol = SaturdayNightStay();
    cout << sol.countOptions(15,6,16,6) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
