#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
unordered_set<int> table;
int a[4];
int k;

bool dfs(int cur, int i, vector<int> & v) {
    if (v.size() == i) {
        return false;
    }
    int val = v[i];
    bool flag = true;
    for (int j = 0; j < k; j++) {
        a[j] += val % 10;
        val /= 10;
        if (a[j] > (cur+1)/2) flag = false;
    }
    if (flag) return true;
    if (dfs(cur+1, i+1, v)) return true;
    val = v[i];
    for (int j = 0; j < k; j++) {
        a[j] -= val % 10;
        val /= 10;
    }
    return dfs(cur, i+1, v);

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp, now;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &tmp);
            now = now*10 + tmp;
        }
        table.insert(now);
    }
    vector<int> v;
    for (auto it = table.begin(); it != table.end(); it++) {
        v.push_back(*it);
    }
    if (dfs(0, 0, v)) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}