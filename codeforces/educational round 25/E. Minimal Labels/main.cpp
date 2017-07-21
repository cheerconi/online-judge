#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
int degree[MAXN];
vector<int> dads[MAXN];
int label[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    set<int> ready;
    for (int i = 1; i <= n; i++) ready.insert(-i);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        dads[b].push_back(a);
        degree[a]++;
        auto it = ready.find(-a);
        if (it != ready.end()) ready.erase(it);
    }
    for (int i = n; i >= 1; i--) {
        int pos = -(*ready.begin());
        ready.erase(ready.begin());
        label[pos] = i;
        for (int dad : dads[pos]) {
            degree[dad]--;
            if (degree[dad] == 0) ready.insert(-dad);
        }
    }
    printf("%d", label[1]);
    for (int i = 2; i <= n; i++) {
        printf(" %d", label[i]);
    }
    cout << endl;

}
