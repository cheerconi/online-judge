#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int v;
vector<int> stairs, elevators;
int solve (int x1, int y1, int x2, int y2) {
    if (x1 == x2) return abs(y1-y2);
    int ret = INT_MAX;
    auto it = lower_bound(stairs.begin(), stairs.end(), y1);
    if (it != stairs.end()) {
        ret = min(ret, abs(*it - y1)+abs(x1-x2) + abs(*it - y2));
    }
    if (!stairs.empty() && it != stairs.begin()) {
        it--;
        ret = min(ret, abs(*it - y1)+abs(x1-x2) + abs(*it - y2));
    }
    auto it2 = lower_bound(elevators.begin(), elevators.end(), y1);
    int tmp = abs(x1-x2) / v;
    if (abs(x1-x2) % v != 0) tmp++;
    if (it2 != elevators.end()) {
        ret = min(ret, abs(*it2 - y1)+ tmp + abs(*it2 - y2));
    }
    if (!elevators.empty() && it2 != elevators.begin()) {
        it2--;
        ret = min(ret, abs(*it2 - y1)+ tmp + abs(*it2 - y2));
    }
    return ret;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, val, x1, y1, x2, y2;
    cin >> n >> m >> a >> b >> v;
    for (int i = 0; i < a; i++) {
        cin >> val;
        stairs.push_back(val);
    }
    for (int i = 0; i < b; i++) {
        cin >> val;
        elevators.push_back(val);
    }
    int q; cin >> q;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << min(solve(x1, y1, x2, y2), solve(x2, y2, x1, y1)) << '\n';
    }

}
