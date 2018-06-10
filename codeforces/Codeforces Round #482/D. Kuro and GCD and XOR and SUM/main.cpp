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

struct TrieNode{
    int mi = INT_MAX;
    TrieNode* nxt[2];
};
const int MAXN = 1e5 + 10;
const int MAXB = 16;
vector<int> nums[MAXN];
bool used[MAXN];
TrieNode* tries[MAXN];

void insert(int x, int num) {
    if (tries[num] == NULL) tries[num] = new TrieNode();
    TrieNode* cur = tries[num];
    cur->mi = min(cur->mi, x);
    for (int i = MAXB; i >= 0; i--) {
        int idx = (x>>i) & 1;
        if (cur->nxt[idx] == NULL) cur->nxt[idx] = new TrieNode();
        cur = cur->nxt[idx];
        cur->mi = min(cur->mi, x);
    }
}

void insert(int x) {
    if (used[x]) return;
    used[x] = true;
    for (int num : nums[x]) {
        insert(x, num);
    }
}

int solve(int x, int k, int s) {
    if (x % k != 0 || tries[k] == NULL || tries[k]->mi+x > s) return -1;
    TrieNode* cur = tries[k];
    for (int i = MAXB; i >= 0; i--) {
        int idx = (x>>i) & 1; idx = 1 - idx;
        if (cur->nxt[idx] == NULL || cur->nxt[idx]->mi+x > s) {
            idx = 1-idx;
            if (cur->nxt[idx] == NULL || cur->nxt[idx]->mi+x > s) return -1;
        }
        cur = cur->nxt[idx];
    }
    return cur->mi;

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

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            nums[j].push_back(i);
        }
    }
    int q; cin >> q;
    int cmd, x, k, s;
    while (q--) {
        cin >> cmd >> x;
        if (cmd == 1) {
            insert(x);
        }
        else {
            cin >> k >> s;
            cout << solve(x, k, s) << '\n';

        }
    }

/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
