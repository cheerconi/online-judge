#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 123;
string pieces[4][MAXN];

int solve (vector<int> & v, int s, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int cur = s;
        for (int j = 0;j < n; j++) {
            if (pieces[v[0]][i][j]-'0' != cur) ret++;
            cur = 1 - cur;
        }
        for (int j = 0; j < n; j++) {
            if (pieces[v[1]][i][j] - '0' != cur) ret++;
            cur = 1 - cur;
        }
        s = 1 - s;
    }
    for (int i = 0; i < n; i++) {
        int cur = s;
        for (int j = 0;j < n; j++) {
            if (pieces[v[2]][i][j]-'0' != cur) ret++;
            cur = 1 - cur;
        }
        for (int j = 0; j < n; j++) {
            if (pieces[v[3]][i][j] - '0' != cur) ret++;
            cur = 1 - cur;
        }
        s = 1 - s;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pieces[i][j];
        }
    }
    int ret = 1e9;
    vector<int> v{0, 1, 2, 3};
    do {
        ret = min(ret, solve(v, 0, n));
        ret = min(ret, solve(v, 1, n));

    } while (next_permutation(v.begin(), v.end()));
    cout << ret << endl;
    return 0;
}