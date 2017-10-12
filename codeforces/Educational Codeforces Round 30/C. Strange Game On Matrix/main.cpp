#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100 + 10;
int graph[MAXN][MAXN];
int cost = 0;
int n, m, k;
int solve(int col) {
    int ones = 0;

    vector<int> sum(n, 0);
    sum[0] = graph[0][col];
    for (int j = 1; j < n; j++) {
        sum[j] += sum[j-1] + graph[j][col];
    }
    int i = 0;
    while (i < n && graph[i][col] == 0) i++;
    for (int j = 0; j < k && i < n; j++,i++) {
        ones += graph[i][col];
    }
    int cur = ones;
    int tmp = 0;
    while (i < n) {
        if (graph[i-k][col] == 1) cur--;
        cur += graph[i][col];
        if (cur > ones) {
            ones = cur;
            if (i-k-1 >= 0) tmp = sum[i-k-1];
        }
        i++;
    }
    cost += tmp;
    return ones;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int ret = 0;
    for (int j = 0; j < m; j++) {
        ret += solve(j);
    }
    cout << ret << ' ' << cost << endl;

    return 0;
}