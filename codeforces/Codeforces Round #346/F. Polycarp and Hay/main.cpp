#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 1000 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, graph[MAXN][MAXN], par[MAXN*MAXN], sz[MAXN*MAXN];
vector<int> edges[MAXN];
int find (int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}
void print(int a, int b, int tot) {
    queue<pii> q;
    q.push({a, b});
    int num = graph[a][b];
    graph[a][b] = -1;
    tot--;
    while (tot > 0) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4 && tot > 0; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= n || x < 0 || y >= m || y < 0) continue;
            if (graph[x][y] < num) continue;
            graph[x][y] = -1;
            tot--;
            q.push({x, y});
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == -1) cout << num;
            else cout << 0;
            if (j+1 != m) cout << ' ';
        }
        cout << endl;
    }
}
int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL sum;
    cin >> n >> m >> sum;
    vector<pii> nums;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            nums.push_back({graph[i][j], i*m+j});
            par[i*m+j] = i*m+j;
            sz[i*m+j] = 1;
        }
    }
    sort(nums.begin(), nums.end(), greater<pii>());
    for (pii item : nums) {
        int num = item.first;
        if (1LL * num * n * m < sum) break;
        int cur = item.second;
        int i = cur / m;
        int j = cur % m;
        for (int k = 0; k < 4; k++) {
            int a = i + dx[k];
            int b = j + dy[k];
            if (a >= n || a < 0 || b >= m || b < 0) continue;
            if (graph[a][b] < graph[i][j]) continue;
            if (find(cur) != find(a*m+b)) {
                int tmp = sz[find(cur)] + sz[find(a*m+b)];
                add(cur, a*m+b);
                sz[find(cur)] = tmp;
            }
        }
        if (sum % num == 0 && sz[find(cur)] >= sum/num) {
            print(i, j, sum/num);
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}