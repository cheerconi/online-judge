#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
int dollar[MAXN], pound[MAXN], itemd[MAXN], itemp[MAXN], idxd[MAXN], idxp[MAXN];
int td, tp, s, k, idd[MAXN], idp[MAXN];
LL d, p;
vector<int> retd, retp;

bool cmpd(int i, int j) {
    return itemd[i]*d < itemd[j]*d;
}
bool cmpp(int i, int j) {
    return itemp[i]*p < itemp[j]*p;
}

bool solve (int n, bool print = false) {
    retd.clear(); retp.clear();
    d = dollar[n];
    p = pound[n];
    if (d == 0) return false;
    sort(idxd, idxd+td, cmpd);
    sort(idxp, idxp+tp, cmpp);
    LL cur = s;
    int cnt = 0, i = 0, j = 0;
    while (cnt < k && cur > 0) {
        if (i < td && j < tp) {
            if (itemd[idxd[i]]*d <= itemp[idxp[j]]*p) {
                if (print) retd.push_back(idd[idxd[i]]);
                cur -= itemd[idxd[i++]]*d;
            }
            else {
                if(print) retp.push_back(idp[idxp[j]]);
                cur -= itemp[idxp[j++]]*p;
            }
        }
        else if (i < td) {
            if(print) retd.push_back(idd[idxd[i]]);
            cur -= itemd[idxd[i++]]*d;
        }
        else {
            if(print) retp.push_back(idp[idxp[j]]);
            cur -= itemp[idxp[j++]]*p;
        }
        cnt++;
    }
    if (cnt == k && cur >= 0) return true;
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, t, val;
    cin >> n >> m >> k >> s;
    pound[0] = dollar[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        dollar[i] = min(dollar[i-1], val);
    }
    for (int i = 1; i <= n; i++) {
        cin >> val;
        pound[i] = min(pound[i-1], val);
    }
    for (int i = 0; i < m; i++) {
        cin >> t >> val;
        if (t == 1) {
            idxd[td] = td;
            idd[td] = i+1;
            itemd[td++] = val;
        }
        else {
            idxp[tp] = tp;
            idp[tp] = i+1;
            itemp[tp++] = val;
        }
    }
    int left = 1, right = n+1;
    while (left < right) {
        int mid = (left+right) >> 1;
        if (solve(mid)) right = mid;
        else left = mid + 1;
    }
    if (left <= n) {
        solve(left, true);
        int x = 0, y = 0;
        for (int i = 1; i <= left; i++) {
            if (dollar[left] == dollar[i]) {
                x = i;
                break;
            }
        }
        for (int i = 1; i <= left; i++) {
            if (pound[left] == pound[i]) {
                y = i;
                break;
            }
        }
        cout << left << endl;
        for (int item : retd) {
            cout << item << ' ' << x << '\n';
        }
        for (int item : retp) {
            cout << item << ' ' << y << '\n';
        }
    }

    else cout << -1 << endl;
    return 0;
}