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

string add( string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int rem = 0;
    string ret;
    int i = 0;
    for (; i < min(s1.size(), s2.size()); i++) {
        int value = rem + s1[i]-'0' + s2[i]-'0';
        ret.push_back(value%10 + '0');
        rem = value/10;
    }
    while (i < s1.size()) {
        int value = rem + s1[i] - '0';
        ret.push_back(value%10 + '0');
        rem = value/10;
        i++;
    }
    while (i < s2.size()) {
        int value = rem + s2[i] - '0';
        ret.push_back(value%10 + '0');
        rem = value/10;
        i++;
    }
    if (rem != 0) {
        ret.push_back(rem + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool lt(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    return s1 < s2;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    string s; cin >> s;
    int len = n;
    for (int i = 1; i < n; i++) {
        if (s[i] != '0') {
            len = min(len, max(i, n-i));
        }
    }
    string ret = string(n+1, '9');
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') continue;
        if (max(i, n-i) == len || max(i, n-i) == len+1) {
            string tmp = add(s.substr(0, i), s.substr(i));
            if (lt(tmp, ret)) {
                ret = move(tmp);
            }
        }
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
