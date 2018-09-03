#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL mh[MAXN], sh[MAXN], re[MAXN], ti[MAXN], id[MAXN], change[MAXN], idx[MAXN];
LL state[MAXN], from[MAXN];
LL bounty, increase, damage;
map<LL, LL> table;
bool cmp(int i, int j) {
    return ti[i] < ti[j];
}
void adjust(int start, int ma, int cur, int delta) {
    if (cur <= damage) {
        table[start]++;
        if (ma > damage && delta > 0) {
            int tmp = (damage - cur) / delta;
            tmp++;
            table[tmp+start]--;
            table[tmp-1+start] += 0;
            table[tmp-2+start] += 0;
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    cin >> bounty >> increase >> damage;
    table[2e9] = 0;
    table[-1] = 0;
    for (int i = 0; i < n; i++) {
        cin >> mh[i] >> sh[i] >> re[i];
        adjust(0, mh[i], sh[i], re[i]);
        state[i] = sh[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ti[i] >> id[i] >> change[i];
        idx[i] = i;
    }
    sort(idx, idx+m, cmp);
    LL ret_tot = 0;
    auto it = table.begin();
    it++;
    for (int j = 0; j < m; j++) {
        int i = idx[j];
        while (it->first+1 < ti[i]) {
            auto pre = it; pre--;
            it->second += pre->second;
            ret_tot = max(ret_tot, (bounty + increase*it->first) * it->second);
            it++;
        }
        table[ti[i]-1] += 0;
        while (j < m && ti[idx[j]] == ti[i]) {
            int k = idx[j];
            if (min(mh[id[k]-1], re[id[k]-1]*(ti[k]-from[id[k]-1]) + state[id[k]-1]) <= damage) {
                table[ti[k]]--;
                if (mh[id[k]-1] > damage && re[i] > 0) {
                    int tmp = (damage - state[id[k]-1]) / re[i];
                    tmp++;
                    table[from[id[k]-1]+tmp]++;
                }
            }
            from[id[k]-1] = ti[k];
            state[id[k]-1] = change[k];
            adjust(ti[k], mh[id[k]-1], change[k], re[id[k]-1]);
            j++;
        }
        j--;
        it = table.find(ti[i]-1);
    }
    while (it != table.end()) {
        auto pre = it; pre--;
        it->second += pre->second;
        if (ret_tot < (bounty + increase*it->first) * it->second) {
            ret_tot = (bounty + increase*it->first) * it->second;
        }
        it++;
    }
    it--;
    if (it->second > 0 && increase > 0) ret_tot = -1;
    cout << ret_tot << endl;

}