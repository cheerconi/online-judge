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
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LL, int> pli;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 2e5 + 10;
LL tree[MAXN], nums[MAXN];
pli data[MAXN<<2];
int n;
inline int lowbit(int i) {
    return i&(-i);
}
void add(int i, LL val) {
    while (i <= n) {
        tree[i] += val;
        i += lowbit(i);
    }
}
LL sum(int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

void update(int node, int left, int right, int i, LL val) {
    if (left == right) {
        data[node] = {val, i};
        return;
    }
    int mid = getmid;
    if (i <= mid) update(leftnode, left, mid, i, val);
    else update(rightnode, mid+1, right, i, val);
    data[node] = data[leftnode];
    if (data[rightnode].first > data[node].first) data[node] = data[rightnode];
}

int query(int node, int left, int right, int i, int j, LL val) {
    if (j < left || right < i || i > j) return -1;
    if (i <= left && right <= j) return data[node].second;
    int mid = getmid;
    int ret = query(leftnode, left, mid, i, j, val);
    if (ret != -1 && nums[ret] >= val) return ret;
    ret = query(rightnode, mid+1, right, i, j, val);
    return ret;
}

int find(int i, LL val) {
    int idx = query(1, 1, n, i, n, val);
    if (idx == -1) return -1;
    while (true) {
        int tmp = query(1, 1, n, i, idx-1, val);
        if (tmp == -1) break;
        idx = tmp;
    }
    return idx;

}

int solve() {
    if (nums[1] == 0) return 1;
    int idx = 1;
    while (true) {
        LL val = sum(idx);
        idx = find(idx+1, val);
        if (idx == -1) return -1;
        if (nums[idx] == sum(idx-1))return idx;
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
    int q, idx;
    LL val;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        add(i, nums[i]);
        update(1, 1, n, i, nums[i]);
    }
    while (q--) {
        cin >> idx >> val;
        add(idx, val - nums[idx]);
        nums[idx] = val;
        update(1, 1, n, idx, nums[idx]);
        cout << solve() << "\n";
    }



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
