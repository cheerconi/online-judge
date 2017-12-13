#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 2500 + 10;
int norm[26], cur[26];
string data[MAXN];
vector<pii> cand;
set<int> pos;
bool dup = false;
int k, n;
void check() {
    for (int i = 1; i < k; i++) {
        memset(cur, 0, sizeof(cur));
        for (char c : data[i]) {
            cur[c-'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (cur[j] != norm[j]) {
                cout << -1 << endl;
                exit(0);
            }
        }
    }
}
int solve() {
    if (k == 1) return 0;
    vector<int> votes(cand.size(), 1);
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < cand.size(); j++) {
            if (votes[j] < i) continue;
            int cnt = 0;
            for (int v : pos) {
                int tmp = v;
                if (tmp == cand[j].first) {
                    tmp = cand[j].second;
                }
                else if (tmp == cand[j].second) {
                    tmp = cand[j].first;
                }
                if (data[0][tmp] != data[i][v]) {
                    cnt++;
                }
                if (cnt > 6) return -1;
            }
            if (pos.find(cand[j].first) == pos.end()) {
                if (data[0][cand[j].second] != data[i][cand[j].first]) {
                    cnt++;
                }
            }
            if (pos.find(cand[j].second) == pos.end()) {
                if (data[0][cand[j].first] != data[i][cand[j].second]) {
                    cnt++;
                }
            }
            if (cnt > 6) return -1;
            if (cnt == 0 && !dup) continue;
            if (cnt > 2) continue;
            votes[j]++;
            if (votes[j] == k) return j;
        }
    }
    return -1;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> data[i];
    }
    for (char c : data[0]) {
        norm[c-'a']++;
        if (norm[c-'a'] == 2) dup = true;
    }
    check();
    if (dup) {
        cand.push_back({0, 0});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[0][i] != data[0][j]) cand.push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k; j++) {
            if (data[0][i] != data[j][i]) {
                pos.insert(i);
                break;
            }
        }
    }
    int ret = solve();
    if (ret == -1) cout << -1 << endl;
    else {
        swap(data[0][cand[ret].first], data[0][cand[ret].second]);
        cout << data[0] << endl;
    }
}