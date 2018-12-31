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
int data[3][2];
set<pii> ret;

int solve(int a, int b, int val) {
    if (val >= min(a, b) && val <= max(a, b)) return val;
    if (val > max(a, b)) return max(a, b);
    return min(a, b);
}
void add(int a, int b, int c, int d) {
    int x = a, y = b;
    ret.emplace(x, y);
    while (x != c) {
        if (x > c) x--;
        else x++;
        ret.emplace(x, y);
    }
    while (y != d) {
        if (y > d) y--;
        else y++;
        ret.emplace(x, y);
    }
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int cnt = INT_MAX;
    cin >> data[0][0] >> data[0][1];
    cin >> data[1][0] >> data[1][1];
    cin >> data[2][0] >> data[2][1];
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            int tmp = abs(data[i][0] - data[j][0]) + abs(data[i][1] - data[j][1]);
            int k = 3 - i - j;
            int x = solve(data[i][0], data[j][0], data[k][0]);
            int y = solve(data[i][1], data[j][1], data[k][1]);
            tmp += abs(x-data[k][0]) + abs(y-data[k][1]);
            if (tmp < cnt) {
                cnt = tmp;
                ret.clear();
                add(data[i][0], data[i][1], x, y);
                add(x, y, data[j][0], data[j][1]);
                add(x, y, data[k][0], data[k][1]);
            }
        }
    }
    cout << cnt+1 << endl;
    for (auto it = ret.begin(); it != ret.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
