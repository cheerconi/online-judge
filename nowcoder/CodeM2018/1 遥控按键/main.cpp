#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
string mat[3][3];
int a, b;
int solve(char c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (char tmp : mat[i][j]) {
                if (tmp == c) {
                    int ret = abs(i-a) + abs(j-b);
                    a = i;
                    b = j;
                    return ret;
                }
            }
        }
    }
    return 0;
}



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    mat[0][0] = "@!:";
    mat[0][1] = "ABC";
    mat[0][2] = "DEF";
    mat[1][0] = "GHI";
    mat[1][1] = "JKL";
    mat[1][2] = "MNO";
    mat[2][0] = "PQRS";
    mat[2][1] = "TUV";
    mat[2][2] = "WXYZ";
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        a = 0, b = 0;
        int ret = 0;
        for (char c : s) {
            ret += solve(c);
        }
        cout << ret << endl;

    }


/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
