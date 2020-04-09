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
typedef pair<char, char> pcc;
typedef pair<char, int> pci;
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
const int MAXN = 1000 + 10;
map<pii, pcc> table[MAXN];
string mat[MAXN];



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for (int i = 0; i < m; i++) {
        vector<pci> tmp;
        int j = 0, p = 0;
        while (j < n) {
            if (j-1 >= 0 && mat[j-1][i] != mat[j][i]) {
                tmp.emplace_back(mat[j-1][i], j-p);
                p = j;
            }
            j++;
        }
        tmp.emplace_back(mat[j-1][i], j-p);
        int start = tmp[0].second;
        for (int j = 1; j+1 < tmp.size(); j++) {
            if (tmp[j-1].second >= tmp[j].second && tmp[j+1].second >= tmp[j].second) {
                table[i][make_pair(start, start+tmp[j].second)] = make_pair(tmp[j-1].first, tmp[j+1].first);
            }
            start += tmp[j].second;
        }
    }
    LL ret = 0;
    for (int i = 0; i < m; i++) {
        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            LL cnt = 1;
            for (int j = i+1; j < m; j++) {
                if (mat[it->first.first][i] != mat[it->first.first][j]) break;
                auto it2 = table[j].find(it->first);
                if (it2 == table[j].end()) break;
                if (it2->second != it->second) break;
                cnt++;
                table[j].erase(it2);
            }
            ret += (cnt+1)*cnt / 2;
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