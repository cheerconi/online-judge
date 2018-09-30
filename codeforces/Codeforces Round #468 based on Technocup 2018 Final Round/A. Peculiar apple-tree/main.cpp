#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
vector<int> nxt[MAXN];
int deep[MAXN], cnt[MAXN];

void dfs(int cur) {
    for (int son : nxt[cur]) {
        deep[son] = deep[cur] + 1;
        dfs (son);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        nxt[p].push_back(i);
    }
    deep[1] = 0;
    dfs (1);
    for (int i = 1; i <= n; i++) {
        cnt[deep[i]]++;
    }
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += cnt[i] % 2;
    }
    cout << ret << endl;


    return 0;
}