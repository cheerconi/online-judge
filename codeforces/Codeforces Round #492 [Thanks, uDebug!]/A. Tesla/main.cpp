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
struct Action{
    int val, x, y;
};
const int MAXN = 50 + 10;
vector<Action> actions;
int mat[5][MAXN];
int n, k;

pii nxt(pii pos) {
    if (pos.first == 2) {
        pos.second++;
        if (pos.second == n+1) {
            pos.first = 3;
            pos.second = n;
        }
    }
    else {
        pos.second--;
        if (pos.second == 0) {
            pos.first = 2;
            pos.second = 1;
        }
    }
    return pos;
}

bool check(int i, int j) {
    if (mat[i][j] == 0) return false;
    Action item;
    item.val = mat[i][j]; item.y = j;
    if (i == 2) {
        if (mat[1][j] != mat[i][j]) return false;
        mat[i][j] = 0;
        item.x = 1;
        actions.push_back(item);
        return true;
    }
    else {
        if (mat[4][j] != mat[i][j]) return false;
        mat[i][j] = 0;
        item.x = 4;
        actions.push_back(item);
        return true;
    }
}

void move(int i, int j) {
    pii tmp = {i, j};
    pii tmp2 = nxt(tmp);
    if (mat[tmp.first][tmp.second] != 0 && mat[tmp2.first][tmp2.second] == 0) {
        Action item;
        item.val = mat[tmp.first][tmp.second];
        item.x = tmp2.first; item.y = tmp2.second;
        actions.push_back(item);
        mat[tmp2.first][tmp2.second] = item.val;
        mat[tmp.first][tmp.second] = 0;
    }
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

    cin >> n >> k;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int j = 1; j <= n; j++) {
       if (check(2, j)) k--;
       if (check(3, j)) k--;
    }
    if (k == 2*n) {
        cout << -1 << endl;
        return 0;
    }
    while (k) {
        for (int j = 1; j <= n && k > 0; j++) {
            if (check(2, j)) k--;
            move(2, j);
        }
        for (int j = n; j >= 1 && k > 0; j--) {
            if (check(3, j)) k--;
            move(3, j);
        }
    }
    cout << actions.size() << '\n';
    for (auto item : actions) {
        cout << item.val << ' ' << item.x << ' ' << item.y << '\n';
    }





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
