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
const int MAXN = 5200 + 16;
int n;
string mat[MAXN];
unordered_map<char, string> table;
string s;

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b%a);
}

char get(int i, int j) {
    char x = mat[i][j/4];
    return table[x][j%4];
}

int cnt() {
    int cur = 0, ret = n;
    for (int i = 0; i < n; i++) {
        if (i != 0 && s[i] != s[i-1]) {
            ret = gcd(ret, cur);
            cur = 1;
        }
        else cur++;
    }
    ret = gcd(ret, cur);
    return ret;
}

int solve(int idx) {
    int ret = n;
    s.clear();
    for (int i = 0; i < n; i++) {
        s.push_back(get(idx, i));
    }
    ret = gcd(ret, cnt());


    s.clear();
    for (int i = 0; i < n; i++) {
        s.push_back(get(i, idx));
    }
    ret = gcd(ret, cnt());
    return ret;
}








int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    table['0'] = "0000";
    table['1'] = "0001";
    table['2'] = "0010";
    table['3'] = "0011";
    table['4'] = "0100";
    table['5'] = "0101";
    table['6'] = "0110";
    table['7'] = "0111";
    table['8'] = "1000";
    table['9'] = "1001";
    table['A'] = "1010";
    table['B'] = "1011";
    table['C'] = "1100";
    table['D'] = "1101";
    table['E'] = "1110";
    table['F'] = "1111";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    int val = n;
    for (int i = 0; i < n; i++) {
        val = gcd(val, solve(i));
    }
    cout << val << endl;










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
