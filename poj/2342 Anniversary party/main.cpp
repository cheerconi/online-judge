#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;

static const int MAXN = 6000 + 10;

struct Emp{
    int val;
    vector<int> slave;
    int dp0;
    int dp1;
    Emp() {
        dp0 = 0;
        dp1 = 0;
        return;
    }
    void add (int id) {
        slave.push_back(id);
    }

} emps[MAXN];
bool root[MAXN];

void dfs(int root) {
    for (int i = 0; i < emps[root].slave.size(); i++) {
        int id = emps[root].slave[i];
        dfs(id);
        emps[root].dp0 += max(emps[id].dp0, emps[id].dp1);
        emps[root].dp1 += emps[id].dp0;
    }
    return;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &tmp);
            emps[i] = Emp();
            emps[i].dp1 = tmp;
        }
        int L, K;
        memset(root, -1, sizeof(root));
        scanf("%d%d", &L, &K);
        while (L != 0) {
            emps[K].add(L);
            root[L] = false;
            scanf("%d%d", &L, &K);
        }
        for (int i = 1; i <= n; i++) {
            if (root[i]) {
                dfs(i);
                cout << max(emps[i].dp0, emps[i].dp1) << endl;
                break;
            }
        }
    }
    return 0;


}