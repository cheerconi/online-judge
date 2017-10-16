#include <iostream>
#include <vector>
#include <set>
typedef long long LL;
using namespace std;
const int MAXN = 1e6 + 10;
vector<int> edges[MAXN];
bool city[MAXN];
int dad[MAXN];
int n, m;
int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    dad[a] = b;
}

LL solve(LL loop) {
    set<int> s;
    for (int i = 1; i <= n; i++) {
        if (city[i]) s.insert(find(i));
    }
    if (s.size() != 1) return 0;
    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        LL sz = edges[i].size();
        if (sz >= 2) {
            cnt += (sz-1)*sz / 2;
        }
    }
    cnt += (m - loop)*loop;
    cnt += (loop-1)*loop / 2;
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &n, &m);
    LL loop = 0;
    for (int i = 1; i <= n; i++) dad[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (a != b) {
            edges[b].push_back(a);
            edges[a].push_back(b);
        }
        else loop++;
        city[a] = true;
        city[b] = true;
        add(a, b);
    }
    cout << solve(loop) << endl;


    return 0;
}