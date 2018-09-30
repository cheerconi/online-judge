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

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
inline void read(int &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

const int MAXB = 22;
bool data[1<<MAXB], hidden[1<<MAXB];




/*-------------------------------------coding area end------------------------------------------*/
int main() {
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    memset(data, true, sizeof(data));
    int n, m, val;
    read(n); read(m);
    int mask = (1<<n) - 1;
    for (int i = 0; i < m; i++) {
        read(val);
        data[val] = false;
    }
    int cnt = 0;
    for (int i = 0; i <= mask; i++) {
        if (data[i]) continue;
        cnt++;
        queue<pii> q;
        q.push({i, 0});
        data[i] = true;
        while (!q.empty()) {
            pii item = q.front(); q.pop();
            val = item.first;
            if (item.second == 1) {
                for (int j = 0; j < n; j++) {
                    if ((val>>j) & 1) continue;
                    if (hidden[val|(1<<j)]) continue;
                    hidden[val|(1<<j)] = true;
                    q.push({val|(1<<j), 1});
                }
                int nxt = (~val) & mask;
                if (data[nxt]) continue;
                data[nxt] = true;
                q.push({nxt, 0});
            }
            else {
                if (hidden[val]) continue;
                hidden[val] = true;
                q.push({val, 1});
            }
        }
    }
    cout << cnt << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
