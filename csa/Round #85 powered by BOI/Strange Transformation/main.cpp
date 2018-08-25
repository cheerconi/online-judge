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
struct Item{
    int cnt3, cnt2, val;
    bool operator< (const Item & rhs) const {
        if (cnt3 != rhs.cnt3) return cnt3 < rhs.cnt3;
        return cnt2 > rhs.cnt2;
    }
    Item(int _val) {
        val = _val;
        cnt2 = cnt3 = 0;
        while (_val % 2 == 0) {
            _val /= 2;
            cnt2++;
        }
        while (_val % 3 == 0) {
            _val /= 3;
            cnt3++;
        }
    }
    bool operator!= (const Item & rhs) {
        return val != rhs.val;
    }
    bool operator== (const Item & rhs) {
        return val == rhs.val;
    }
};





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    vector<Item> v;
    v.push_back(Item(a));
    v.push_back(Item(b));
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(Item(val));
    }
    sort(v.begin(), v.end());
    bool flag = true;
    Item pre = v[0];
    for (int i = 1; i < n+2; i++) {
        if (pre.cnt2 < v[i].cnt2 || pre.cnt3 > v[i].cnt3) {
            flag = false;
            break;
        }
        if (pre == v[i]) {
            flag = false;
            break;
        }
        while (pre.cnt2 != v[i].cnt2) {
            pre = Item(pre.val / 2);
            if (pre != v[i]) v.push_back(pre);
        }
        while (pre.cnt3 != v[i].cnt3) {
            pre = Item(pre.val * 3);
            if (pre != v[i]) v.push_back(pre);
        }
        if (pre != v[i]) {
            flag = false;
            break;
        }
    }
    sort(v.begin(), v.end());
    if (a != v.begin()->val || b != v.rbegin()->val) flag = false;
    if (!flag) {
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].val;
            if (i+1 == v.size()) cout << endl;
            else cout << ' ';
        }
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
