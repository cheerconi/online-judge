#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 4e5 + 10;
vector<int> items[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        items[a+b].push_back(max(a, b));
    }
    int ret = 1;
    for (int i = 3; i < MAXN-1; i++) {
        sort(items[i].begin(), items[i].end());
        int cur = 0;
        int num = i / 2 + 1;
        for (int val : items[i]) {
            if (val == num) {
                cur += 2;
            }
            else break;
            num++;
        }
        if (i % 2 == 0) cur++;
        ret = max(ret, cur);
    }
    cout << ret << endl;

    return 0;
}