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
typedef pair<int, char> pic;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 55;
char mat[MAXN][MAXN];
pic nums[4];
int i, j;

void go() {
    if (j < 50 && mat[i][j] == 0) return;
    j++;
    if (j == 50) {
        i++;
        j = 0;
    }
    go();
}

void solve() {
    if (nums[0].first == 1) {
        for (int k = 1; k < 4; k++) {
            while (nums[k].first) {
                go();
                mat[i][j] = nums[k].second;
                mat[i+1][j]  = nums[0].second;
                mat[i][j+1] = nums[0].second;
                mat[i+1][j+1] = nums[0].second;
                nums[k].first--;
            }
        }
        while (i != 50) {
            go();
            mat[i][j] = nums[0].second;
        }
        return;
    }
    nums[3].first--;
    while (nums[0].first > 1) {
        go();
        mat[i][j] = nums[0].second;
        mat[i+1][j] = nums[3].second;
        mat[i][j+1] = nums[3].second;
        mat[i+1][j+1] = nums[3].second;
        nums[0].first--;
    }
    while (j < 50) {
        if (mat[i][j] == 0) mat[i][j] = nums[3].second;
        j++;
    }
    i++;
    j = 0;
    while (j < 50) {
        if (mat[i][j] == 0) mat[i][j] = nums[3].second;
        j++;
    }
    i++;
    j = 0;
    while (j < 50) {
        if (mat[i][j] == 0) mat[i][j] = nums[0].second;
        j++;
    }
    i++;
    j = 0;
    solve();
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
    int val;
    for (int k = 0; k < 4; k++) {
        cin >> val;
        nums[k] = {val, k+'A'};
    }
    sort(nums, nums+4);
    solve();
    cout << 50 << ' ' << 50 << endl;
    for (int a = 0; a < 50; a++) {
        for (int b = 0; b < 50; b++) {
            cout << mat[a][b];
        }
        cout << endl;
    }


/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
