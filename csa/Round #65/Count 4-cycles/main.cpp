#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
unordered_set<int> edges[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ret = 0, a, b;
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        edges[a].insert(b);
    }
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (edges[a].find(b) != edges[a].end()) ret++;
    }
    cout << ret << endl;
    return 0;
}