#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10;
map<pii, int> table;
int tot;
int degree[MAXN];
int nums[MAXN];
vector<int> edges[MAXN];
pii items[MAXN];
vector<pii> ret;

bool solve() {
    int n;
    cin >> n;
    int a, b, cnt;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cnt);
        set<int> tmp;
        int pre = -1;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &a);
            tmp.insert(a);
            b = i;
            if (a > b) swap(a, b);
            if (table.find({a, b}) == table.end()) {
                table[{a, b}] = tot++;
                items[tot-1] = {a, b};
            }
            nums[table[{a, b}]]++;
            if (j > 0) {
                edges[pre].push_back(table[{a, b}]);
                degree[table[{a, b}]]++;
            }
            pre = table[{a, b}];
        }
        if (tmp.size() != cnt) return false;
    }
    for (int i = 0; i < tot; i++) {
        if (nums[i] != 2) return false;
    }
    vector<int> cur;
    for (int i = 0; i < tot; i++) {
        if (degree[i] == 0) cur.push_back(i);
    }
    while (!cur.empty()) {
        vector<int> nxt;
        for (int i : cur) {
            ret.push_back(items[i]);
            for (int j : edges[i]) {
                degree[j]--;
                if (degree[j] == 0) {
                    nxt.push_back(j);
                }
            }

        }
        swap(nxt, cur);
    }
    if (ret.size() != tot) return false;
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    if (solve()) {
        for (int i = 0; i < tot; i++) {
            printf("%d %d\n", ret[i].first, ret[i].second);
        }
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}