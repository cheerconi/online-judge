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
const int MAXN = 15000000 + 10;
const int MAXM = 3e5 + 10;
int factor[MAXN];
int vals[MAXN];
unordered_map<int, int> table;


void init() {
    for (int i = 2; i < MAXN; i++) {
        if (factor[i] != 0) continue;
        for (int j = i+i; j < MAXN; j += i) {
            factor[j] = i;
        }
    }
}

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    init();
    int n; cin >> n;
    int com = 0;
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        com = gcd(com, vals[i]);
    }
    for (int i = 0; i < n; i++) {
        int val = vals[i] / com;
        while (val != 1 && factor[val] != 0) {
            int tmp = factor[val];
            table[tmp]++;
            while (val % tmp == 0) val /= tmp;
        }
        if (val != 1) table[val]++;
    }
    vector<int> nums;
    for (auto it = table.begin(); it != table.end(); it++) {
        nums.push_back(it->second);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int ret = -1;
    for (auto num : nums) {
        ret = n - num;
        break;
    }
    cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
