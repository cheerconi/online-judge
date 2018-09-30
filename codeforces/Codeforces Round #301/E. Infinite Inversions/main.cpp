#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 2e5 + 10;
int tree[MAXN], tot;
int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= tot) {
        tree[i]++;
        i += lowbit(i);
    }
}
int find (int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    unordered_map<int, int> table;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        auto it = table.find(a);
        if (it == table.end()) {
            table[a] = a;
            c = a;
        }
        else c = it->second;
        it = table.find(b);
        if (it == table.end()) {
            table[b] = b;
            d = b;
        }
        else d = it->second;
        table[a] = d;
        table[b] = c;
    }
    vector<pii> vs;
    vector<int> vals;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->first == it->second) continue;
        vs.push_back({it->first, it->second});
        vals.push_back(it->second);
    }
    sort(vs.begin(), vs.end());
    sort(vals.begin(), vals.end());
    LL ret = 0;
    tot = vals.size();
    for (auto & v : vs) {
        int p = upper_bound(vals.begin(), vals.end(), v.second) - vals.begin();
        LL tmp = find((int)vals.size()) - find(p);
        if (v.second+1 <= v.first-1) {
            tmp += v.first-1 - v.second;
            auto it1 = upper_bound(vs.begin(), vs.end(), make_pair(v.first-1, INT_MAX));
            auto it2 = lower_bound(vs.begin(), vs.end(), make_pair(v.second+1, 0));
            tmp -= (it1 - it2);
        }
        if (v.first+1 <= v.second-1) {
            tmp += v.second-1 - v.first;
            auto it1 = upper_bound(vs.begin(), vs.end(), make_pair(v.second-1, INT_MAX));
            auto it2 = lower_bound(vs.begin(), vs.end(), make_pair(v.first+1, 0));
            tmp -= (it1 - it2);
        }
        ret += tmp;
        add(p);
    }
    cout << ret << endl;

    return 0;
}