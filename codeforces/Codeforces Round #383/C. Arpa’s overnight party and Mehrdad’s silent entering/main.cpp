#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN<<1];
int ret[MAXN<<1], nums[MAXN][2];

void dfs (int cur, int food) {
    for (int son : edges[cur]) {
        if (ret[son] == 0) {
            ret[son] = food;
            dfs (son, -food);
            return;
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        edges[nums[i][0]].push_back(nums[i][1]);
        edges[nums[i][1]].push_back(nums[i][0]);
    }
    for (int i = 1; i < 2*n; i += 2) {
        edges[i].push_back(i+1);
        edges[i+1].push_back(i);
    }
    for (int i = 1; i <= n*2; i++) {
        if (ret[i] == 0) ret[i] = 1;
        dfs(i, -1);
    }
    int val;
    for (int i = 0; i < n; i++) {
        val = (ret[nums[i][0]]+1) / 2 + 1;
        cout << val << ' ';
        val = (ret[nums[i][1]]+1) / 2 + 1;
        cout << val << '\n';
    }
    return 0;
}