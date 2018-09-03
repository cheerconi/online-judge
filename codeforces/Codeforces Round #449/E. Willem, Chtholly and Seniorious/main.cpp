#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int MAXN = 1e5 + 10;
int a[MAXN];
LL n, m, seed, v;
int rnd() {
    LL ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

LL power(LL base, int p, int mod) {
    LL ret = 1;
    base = base % mod;
    while (p) {
        if (p&1) ret = ret * base % mod;
        p >>= 1;
        base = base  * base % mod;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m >> seed >> v;
    map<int, LL> tree;
    tree[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        tree[i] = (rnd() % v) + 1;
    }
    int x, y;
    LL ret;
    for (int i = 1; i <= m; i++) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) swap(l, r);
        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % v) + 1;
        if (op == 4) y = (rnd() % v) + 1;

        if (tree.find(l) == tree.end()) {
            tree[l] = 0;
            auto it = tree.find(l);
            it--;
            tree[l] = it->second;
        }
        if (tree.find(r+1) == tree.end()) {
            tree[r+1] = 0;
            auto it = tree.find(r+1);
            it--;
            tree[r+1] = it->second;
        }
        if (op == 1) {
            for (auto it = tree.find(l); it != tree.find(r+1); it++) {
                it->second += x;
            }
        }
        else if (op == 2) {
            auto it = tree.upper_bound(l);
            while (it != tree.end() && it->first <= r) {
                tree.erase(it);
                it = tree.upper_bound(l);
            }
            tree[l] = x;
        }
        else if (op == 3) {
            vector<pli> v;
            auto it = tree.find(l);
            LL pre_val = it->second;
            int pre_idx = it->first;
            it++;
            while (true) {
                v.push_back({pre_val, it->first-pre_idx});
                if (it->first == r+1) break;
                pre_idx = it->first;
                pre_val = it->second;
                it++;
            }
            sort(v.begin(), v.end());
            for (auto item : v) {
                if (item.second >= x) {
                    ret = item.first;
                    break;
                }
                x -= item.second;
            }
        }
        else {
            ret = 0;
            auto it = tree.find(l);
            LL pre_val = it->second;
            LL pre_idx = it->first;
            it++;
            while (true) {
                ret = (ret + (it->first-pre_idx)*power(pre_val, x, y) % y) % y;
                if (it->first == r+1) break;
                pre_idx = it->first;
                pre_val = it->second;
                it++;
            }
        }
        if (op == 3 || op == 4) printf("%I64d\n", ret);

    }

    return 0;
}