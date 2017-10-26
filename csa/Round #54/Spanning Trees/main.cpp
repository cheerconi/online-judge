#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int ret[MAXN<<1][3];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, ind = 0, val = 1;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        ret[ind][0] = i;
        ret[ind][1] = i+1;
        ret[ind++][2] = val++;
    }
    for (int i = 1; i < min(n-k, n-1); i++) {
        ret[ind][0] = i;
        ret[ind][1] = n;
        ret[ind++][2] = val++;
    }
    if (k == 0) {
        if (n == 2 || n == 3) {
            cout << -1 << endl;
            return 0;
        }
        if (n-1 > 2) {
            ret[ind][0] = 1;
            ret[ind][1] = n-1;
            ret[ind++][2] = val++;
        }
    }
    cout << ind << endl;
    for (int i = 0; i < ind; i++) {
        printf("%d %d %d\n", ret[i][0], ret[i][1], ret[i][2]);
    }
    return 0;
}