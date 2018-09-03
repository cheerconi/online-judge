#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
string s;
int tree[MAXN], n, ind[MAXN], rnk[MAXN];
char ret[MAXN];

inline int lowbit(int i) {
    return i&(-i);
}
int find(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}

int search(int i) {
    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (mid - find(mid) >= i) right = mid;
        else left = mid + 1;
    }
    return left;
}
bool cmp(int i, int j) {
    return rnk[i] < rnk[j];
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, a, b;
    cin >> n >> q;
    string s;
    cin >> s;
    unordered_map<char, set<int> > table;
    for (int i = 1; i <= n; i++) {
        table[s[i-1]].insert(i);
    }
    char c;
    while (q--) {
        cin >> a >> b >> c;
        auto & item = table[c];
        a = search(a);
        b = search(b);
        while (true) {
            auto it = item.lower_bound(a);
            if (it == item.end() || *it > b) break;
            add(*it);
            item.erase(it);
        }
    }
    int tot = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        for (int p : it->second) {
            rnk[tot] = p;
            ind[tot] =tot;
            ret[tot++] = it->first;
        }
    }
    sort(ind, ind+tot, cmp);
    for (int i = 0; i < tot; i++) {
        cout << ret[ind[i]];
    }
    cout << endl;
    return 0;
}