#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
const int MAXN = 1e5 + 10;
pair<pll, int> items[MAXN];
int ret[MAXN], tree[MAXN], n;
bool cmp(pll a, pll b) {
    return a.second*b.first < a.first*b.second;
}
int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}
int find(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b;
    vector<pll> tmp;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        items[i] = {{a, b}, i};
        tmp.push_back({a, b});
    }
    sort(tmp.begin(), tmp.end(), cmp);
    map<pll, int> table;
    int idx = 1;
    for (pll item : tmp) {
        table[item] = idx++;
    }
    sort(items, items+n);
    for (int i = 0; i < n; i++) {
        ret[items[i].second] = find(table[items[i].first]);
        add (table[items[i].first]);
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}