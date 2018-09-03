#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1000 + 10;
int dis[MAXN][MAXN];
bool used[MAXN];
int n;

int prim() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    used[0] = true;
    for (int i = 1; i < n; i++) pq.push({dis[0][i], i});
    int cnt = 1;
    int ret = 0;
    while (cnt < n) {
        pii item = pq.top();
        pq.pop();
        if (used[item.second]) continue;
        used[item.second] = true;
        cnt++;
        ret += item.first;
        for (int i = 1; i < n; i++) {
            if (used[i]) continue;
            pq.push({dis[i][item.second], i});
        }
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dis[i][j]);
        }
    }
    cout << prim() << endl;

    return 0;
}