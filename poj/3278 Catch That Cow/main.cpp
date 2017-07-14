#include <iostream>
#include <memory.h>
#include <queue>
#include <limits.h>

using namespace std;
static const int MAXN = 200000 + 20;
int dis[MAXN];

bool update(int val, int pos) {
    if (pos < 0 || pos >= MAXN) return false;
    if (dis[pos] != -1) return false;
    dis[pos] = val;
    return true;
}

int main() {
    freopen("test.txt", "r", stdin);
    memset(dis, -1, sizeof(dis));
    int n, k;
    scanf("%d%d", &n, &k);
    queue<int> q;
    dis[k] = 0;
    q.push(k);
    while (q.size() > 0) {
        int tmp = q.front();
        q.pop();
        int pos, val = dis[tmp] + 1;
        if((tmp & 1) == 0) {
            if (update(val, tmp>>1)) q.push(tmp>>1);

        }
        if (update(val, tmp+1)) q.push(tmp+1);
        if (update(val, tmp-1)) q.push(tmp-1);
        if (dis[n] != -1) {
            cout << dis[n] << endl;
            break;
        }
    }
    return 0;
}