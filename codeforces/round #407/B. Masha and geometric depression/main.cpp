#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long LL;
int a, q, b, m, tmp;
unordered_set<int> ban;

int solve() {
    if (abs(a) > b) return 0;
    if (a == 0 || q == 0) {
        if (ban.find(0) == ban.end()) return -1;
        if (ban.find(a) == ban.end() && abs(a) <= b) return 1;
        return 0;
    }
    if (q == 1) {
        if (ban.find(a)==ban.end() && abs(a) <= b) return -1;
        return 0;
    }
    if (q == -1) {
        if (ban.find(a)==ban.end() && abs(a) <= b) return -1;
        if (ban.find(-a) == ban.end() && abs(a) <= b) return -1;
        return 0;
    }
    int cnt = 0;
    LL cur = a;
    while (abs(cur) <= b) {
        if (ban.find(cur) == ban.end()) cnt++;
        cur = cur*q;
    }
    return cnt;


}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d%d%d", &a, &q, &b, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        if (abs(tmp) <= b) ban.insert(tmp);
    }
    int cnt = solve();
    if (cnt == -1) cout << "inf" << endl;
    else cout << cnt << endl;
    return 0;
}