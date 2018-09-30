#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int MAXN = 100000 + 10;
bool state[MAXN];
bool cannot[MAXN];
unordered_set<int> sons[MAXN];

bool change(int i) {
    if (state[i]) return true;
    if (cannot[i]) return false;
    state[i] = true;
    for (int j : sons[i]) {
        if (!change(j)) return false;
    }
    return true;
}

bool solve(int m) {
    int len, val;
    scanf("%d", &len);
    vector<int> pre, cur;
    for (int i = 0; i < len; i++) {
        scanf("%d", &val);
        pre.push_back(val);
    }
    for (int i = 1; i < m; i++) {
        cur.clear();
        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &val);
            cur.push_back(val);
        }
        bool flag = true;
        for (int j = 0; j < cur.size() && j < pre.size(); j++) {
            if (cur[j] == pre[j]) continue;
            if (cur[j] < pre[j]) {
                if (state[cur[j]]) return false;
                cannot[cur[j]] = true;
                if (!change(pre[j])) return false;
            }
            else {
                if (state[cur[j]]) {
                    if (!change(pre[j])) return false;
                }
                else sons[cur[j]].insert(pre[j]);
            }
            flag = false;
            break;
        }
        if (flag && cur.size() < pre.size()) return false;
        swap(cur, pre);
    }
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (solve(n)) {
        cout << "Yes" << endl;
        int k = 0;
        for (int i = 1; i <= m; i++) {
            if (state[i]) k++;
        }
        cout << k << endl;
        for (int i = 1; i <= m; i++) {
            if (!state[i]) continue;
            printf("%d", i);
            k--;
            if (k > 0) printf(" ");
            else printf("\n");
        }
    }
    else {
        cout << "No" << endl;
    }
}