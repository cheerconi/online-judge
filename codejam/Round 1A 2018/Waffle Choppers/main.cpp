#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 100 + 10;
string mat[MAXN];
int cnt[MAXN][MAXN];
int n, m, hh, vv, tot;
bool solve (int sp) {
    if (tot == 0) return true;
    vector<int> v; v.push_back(0);
    int cur = 0, unit = tot / (hh+1) / (vv+1), tmp = 0;
    for (int i = 0; i < n; i++) {
        cur += cnt[i][sp-1];
        tmp += cnt[i][m-1];
        if (cur == unit && tmp == unit*(v.size())*(vv+1)) {
            cur = 0;
            v.push_back(i+1);
        }
        else if (cur > unit) return false;
    }
    if (v.size() != hh+2 || cur != 0) return false;
    vector<int> ret; ret.push_back(sp);
    for (int j = sp; j < m; j++) {
        bool flag = true;
        cur = 0;
        for (int k = 0; k+1 < v.size(); k++) {
            for (int i = v[k]; i < v[k+1]; i++) {
                cur += cnt[i][j] - cnt[i][ret.back()-1];
            }
            if (cur > unit) return false;
            if (cur !=  unit) {
                flag = false;
                break;
            }
            cur = 0;
        }
        if (flag) ret.push_back(j+1);
    }
    if (ret.size() != vv+1) return false;
    return true;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;

    for (int k = 1; k <= cs; k++) {
        cin >> n >> m >> hh >> vv;
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == '@') {
                    tot++;
                    cnt[i][j]++;
                }
            }
            for (int i = 0; i < n && j != 0; i++) {
                cnt[i][j] += cnt[i][j-1];
            }
        }
        cout << "Case #" << k << ": ";
        if (tot % ((hh+1)*(vv+1)) != 0) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            bool flag = false;
            for (int i = 1; i <= m && !flag; i++) {
                flag = solve(i);
            }
            if (flag) cout << "POSSIBLE\n";
            else cout << "IMPOSSIBLE\n";
        }

    }
    return 0;
}