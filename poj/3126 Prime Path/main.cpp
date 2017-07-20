#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 10000;
bool comp[MAXN];
bool visited[MAXN];
char s[10];

void make_prime() {
    comp[0] = comp[1] = true;
    for (int i = 4; i < MAXN; i += 2) comp[i] = true;
    for (int i = 3; i < MAXN; i += 2) {
        if (comp[i]) continue;
        for (int j = i; i*j < MAXN; j += 2) {
            comp[i*j] = true;
        }
    }
}
int bfs(int start, int end) {
    if (start == end) return 0;
    queue<pii> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 9; j++) {
                sprintf(s, "%d", now);
                s[i] = j+'0';
                int next = atoi(s);
                if (next < 1000 || comp[next] || next == now || visited[next]) continue;
                if (next == end) return cnt+1;
                q.push(make_pair(next, cnt+1));
                visited[next] = true;
            }
        }
    }
    return -1;

}
int main() {
//    freopen("test.txt", "r", stdin);
    make_prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(visited, 0, sizeof(visited));
        int start, end;
        scanf("%d%d", &start, &end);
        int ret = bfs(start, end);
        if (ret >= 0) cout << ret << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}