#include <iostream>
#include <vector>
#include <memory.h>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 1e5 + 10;
pii points[MAXN];
vector<int> ys[MAXN];
bool pos[MAXN];
LL ret;

void solve(int i) {
    LL cur = 0;
    for (int item : ys[i]) {
        cur += pos[item];
    }
    ret += cur*(cur-1) / 2;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &points[i].first, &points[i].second);
        ys[points[i].first].push_back(points[i].second);
    }
    int threshold = 34;
    for (int i = 1; i < MAXN; i++) {
        if (ys[i].size() <= threshold) continue;
        for (int item : ys[i]) pos[item] = true;
        for (int j = i+1; j < MAXN; j++) {
            solve(j);
        }
        for (int j = 1; j < i; j++) {
            if (ys[j].size() > threshold) continue;
            solve(j);
        }
        for (int item : ys[i]) pos[item] = false;
    }
    map<pii, int> table;
    for (int i = 1; i < MAXN; i++) {
        if (ys[i].size() > threshold) continue;
        for (int a = 0; a < ys[i].size(); a++) {
            for (int b = a+1; b < ys[i].size(); b++) {
                int c = ys[i][a];
                int d = ys[i][b];
                if (c > d) swap(c, d);
                table[{c, d}]++;
            }
        }
    }
    for (auto it = table.begin(); it != table.end(); it++) {
        ret += 1LL * (it->second) * (it->second - 1) / 2;
    }
    cout << ret << endl;
    return 0;
}


