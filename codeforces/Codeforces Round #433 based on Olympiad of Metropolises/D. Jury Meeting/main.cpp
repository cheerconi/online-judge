#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXD = 2000000 + 10;
const int MAXN = 100000 + 10;
const LL LLMAX = 0x7fffffffffffffff;
vector<pii> arrive[MAXD], depart[MAXD];
int arr_cost[MAXN], dep_cost[MAXN];
LL arr_time_cost[MAXD], dep_time_cost[MAXD];

int main() {
//    freopen("test.txt", "r", stdin);
    memset(arr_cost, -1, sizeof(arr_cost));
    memset(dep_cost, -1, sizeof(dep_cost));
    memset(arr_time_cost, -1, sizeof(arr_time_cost));
    memset(dep_time_cost, -1, sizeof(dep_time_cost));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int d, f, t, c;
    int dm = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &d, &f, &t, &c);
        dm = max(dm, d);
        if (f == 0) depart[d].push_back({t, c});
        else arrive[d].push_back({f, c});
    }
    int size = 0;
    LL cur = 0;
    for (int i = 1; i+k <= dm; i++) {
        for (pii item : arrive[i]) {
            if (arr_cost[item.first] == -1) {
                size++;
                arr_cost[item.first] = item.second;
                cur += item.second;
            }
            else if (arr_cost[item.first] > item.second) {
                cur = cur - arr_cost[item.first] + item.second;
                arr_cost[item.first] = item.second;
            }
        }
        if (size == n) arr_time_cost[i] = cur;
    }
    size = 0;
    cur = 0;
    for (int i = dm; i-k >= 1; i--) {
        for (pii item : depart[i]) {
            if (dep_cost[item.first] == -1) {
                size++;
                dep_cost[item.first] = item.second;
                cur += item.second;
            }
            else if (dep_cost[item.first] > item.second) {
                cur = cur - dep_cost[item.first] + item.second;
                dep_cost[item.first] = item.second;
            }
        }
        if (size == n) dep_time_cost[i] = cur;
    }
    LL ret = LLMAX;
    for (int i = 1; i+k <= dm; i++) {
        if (arr_time_cost[i] != -1 && dep_time_cost[i+k+1]!= -1)
        ret = min(arr_time_cost[i] + dep_time_cost[i+k+1], ret);
    }
    if (ret == LLMAX) cout << -1 << endl;
    else cout << ret << endl;




    return 0;
}