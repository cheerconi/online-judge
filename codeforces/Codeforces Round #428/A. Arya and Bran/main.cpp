#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    int now = 0;
    int given = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        now += tmp;
        given += min(8, now);
        if (given >= k) {
            cout << i << endl;
            return 0;
        }
        now -= min(8, now);

    }
    cout << -1 << endl;
    return 0;
}