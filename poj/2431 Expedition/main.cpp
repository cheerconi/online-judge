#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 10000 + 10;
int ind[MAXN], dis[MAXN], fuel[MAXN];

bool cmp(int i, int j) {
    return dis[i] < dis[j];
}
int n, now, goal;

int solve() {
    priority_queue<int> pq;
    int cnt = 0, need = goal - now;
    int i = 0;
    while (need > 0) {
        while (i < n && dis[ind[i]] <= now) {
            pq.push(fuel[ind[i++]]);
        }
        if (pq.empty()) return -1;
        int tmp = pq.top();
        pq.pop();
        need -= tmp;
        now += tmp;
        cnt++;
    }
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &dis[i], &fuel[i]);
        ind[i] = i;
    }

    scanf("%d%d", &goal, &now);
    for (int i = 0; i < n; i++) dis[i] = goal - dis[i];
    sort(ind, ind+n, cmp);
    cout << solve() << endl;
    return 0;
}