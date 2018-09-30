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
const int MAXN = 2e5 + 10;
int nums[MAXN];
vector<int> pos[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (pos[nums[i]].size() <= 1) pos[nums[i]].push_back(i);
        else pos[nums[i]][1] = i;
    }
    bool flag = true;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (nums[i] == 0) continue;
        if (!st.empty() && st.top() > nums[i]) {
            flag = false;
            break;
        }
        if (pos[nums[i]].size() <= 1) continue;
        if (pos[nums[i]][0] == i) {
            if (st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
            }
            else {
                flag = false;
                break;
            }
        }
        else if (pos[nums[i]][1] == i) {
            if (!st.empty() && st.top() == nums[i]) {
                st.pop();
            }
            else {
                flag = false;
                break;
            }
        }
    }
    if (!st.empty()) flag = false;
    if (pos[q].empty()) {
        flag = false;
        for (int i = 1; i <= n; i++) {
            if (nums[i] == 0) {
                nums[i] = q;
                flag = true;
                break;
            }

        }
    }
    if (!flag) {
        cout << "NO" << endl;
        return 0;
    }
    set<int> zeros;
    for (int i = 1; i <= n; i++) {
        if (nums[i] == 0) zeros.insert(i);
    }
    for (int i = q; i >= 1; i--) {
        if (pos[i].size() <= 1) continue;
        auto it = zeros.lower_bound(pos[i][0]);
        while (it != zeros.end()) {
            if (*it > pos[i][1]) break;
            nums[*it] = i;
            zeros.erase(it++);
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        if (nums[i] == 0) nums[i] = 1;
        cout << nums[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
