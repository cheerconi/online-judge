#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

static const int MAXM = 100 + 5;
static const int MAXN = 100 + 5;

int trans[MAXM];
int ret[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> trans[i];
        if (trans[i] > n) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (n == 1) {
        for (int i = 0; i < m; i++) {
            if (trans[i] != 1) {
                cout << -1 << endl;
                return 0;
            }
        }
        cout << 1 << endl;
        return 0;
    }

    memset(ret, -1, sizeof(ret));
    vector<bool> used(n+1, false);
    for (int i = 1; i < m; i++) {
        int tmp = trans[i] - trans[i-1];
        if (tmp <= 0) tmp += n;
        if (ret[trans[i-1]] == -1){
            if (used[tmp]) {
                cout << -1 << endl;
                return 0;
            }
            ret[trans[i-1]] = tmp;

        }
        if (ret[trans[i-1]] != tmp) {
            cout << -1 << endl;
            return 0;
        }
        used[tmp] = true;
    }
    int j = 1;
    int i = 1;
    while (j <= n) {
        while (j <= n && used[j]) j++;
        while (i <= n && ret[i]!=-1) i++;
        if (j <= n) {
            used[j] = true;
            ret[i] = j;
        }
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';
    cout << endl;



    return 0;
}