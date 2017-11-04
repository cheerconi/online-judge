#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;
const int MAXN = 1e5 + 10;
int dist[MAXN];

int main() {
    memset(dist, -1, sizeof(dist));
    int n;
    cin >> n;
    deque<int> q;
    dist[1] = 1;
    q.push_back(1);
    while (!q.empty()) {
        int val = q.front();
        q.pop_front();
        int cur = val*10 % n;
        while (dist[cur] == -1 || dist[cur] > dist[val]) {
            dist[cur] = dist[val];
            q.push_front(cur);
            cur = cur*10 % n;
        }
        cur = (val+1) % n;
        if (dist[cur] == -1 || dist[cur] > dist[val]+1) {
            dist[cur] = dist[val] + 1;
            q.push_back(cur);
        }
    }
    cout << dist[0] << endl;
}