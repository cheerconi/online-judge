#include <iostream>
#include <unordered_set>
#include <set>
#include <limits.h>
#include <vector>
using namespace std;

const int MAXN = 300000 + 10;
unordered_set<int> neg[MAXN];
int power[MAXN];

int solve(int root, multiset<int> & m) {
    vector<int> backup;
    int ret = power[root];
    m.erase(m.find(power[root]));
    backup.push_back(power[root]);

    for (int son : neg[root]) {
        ret = max(ret, power[son]+1);
        m.erase(m.find(power[son]));
        backup.push_back(power[son]);
    }
    if (!m.empty()) {
        ret = max(ret, *m.rbegin() + 2);
    }
    for (int item : backup) m.insert(item);

    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b, big = INT_MIN;
    scanf("%d", &n);
    multiset<int> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &power[i]);
        m.insert(power[i]);
        big = max(big, power[i]);
    }
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        neg[a].insert(b);
        neg[b].insert(a);
    }
    int ret = INT_MAX;
    unordered_set<int> cand1;
    for (int i = 1; i <= n; i++) {
        if (power[i] == big) {
            cand1.insert(i);
        }
    }
    unordered_set<int> cand2;
    for (int item : cand1) {
        for (int son : neg[item]) {
            if (power[son] != big) cand2.insert(son);
        }
    }

    for (int item : cand1) {
        ret = min(ret, solve(item, m));
    }
    for (int item : cand2) {
        ret = min(ret, solve(item, m));
    }
    cout << ret << endl;
    return 0;

}
