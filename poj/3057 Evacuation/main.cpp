#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 15;
const int MAXM =3e4;
const int base = 2e4;
const int bin = 300;
int dist[MAXN][MAXN][MAXN][MAXN];
string mat[MAXN];
vector<pii> door, people;
vector<int> edges[MAXM];
bool vis[MAXN][MAXN];
bool used[MAXM];
int match[MAXM];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs (int i, int j) {
    queue<pii> q;
    q.push(make_pair(i, j));
    dist[i][j][i][j] = 0;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int x = cur.first + dx[k];
            int y = cur.second + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (dist[i][j][x][y] != -1 || mat[x][y] != '.') continue;
            vis[x][y] = true;
            dist[i][j][x][y] = dist[i][j][cur.first][cur.second] + 1;
            q.push(make_pair(x, y));
        }
    }
}
bool dfs (int cur) {
    used[cur] = true;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        int u = match[nxt];
        if (u == -1 || (!used[u] && dfs(u))) {
            match[cur] = nxt;
            match[nxt] = cur;
            return true;
        }
    }
    return false;

}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    while (cs--) {
        memset(dist, -1, sizeof(dist));
        memset(vis, false, sizeof(vis));
        door.clear(); people.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'D') {
                    door.push_back(make_pair(i, j));
                    bfs(i, j);

                }
                else if (mat[i][j] == '.') {
                    people.push_back(make_pair(i, j));
                }
            }
        }
        bool succ = true;
        for (int i = 0; i < n && succ; i++) {
            for (int j = 0; j < m && succ; j++) {
                if (mat[i][j] == '.' && !vis[i][j]) {
                    succ = false;
                }
            }
        }
        if (!succ) {
            cout << "impossible\n";
            continue;
        }
        int d = door.size();
        int p = people.size();
        if (p == 0){
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < d*bin; i++) edges[i].clear();
        for (int i = base; i < base+n*m; i++) edges[i].clear();
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < p; j++) {
                int tmp = dist[door[i].first][door[i].second][people[j].first][people[j].second];
                if (tmp > 0) {
                    for (int k = tmp; k <= bin; k++) {
                        edges[base+people[j].first*m+people[j].second].push_back((k-1)*d+i);
                        edges[(k-1)*d+i].push_back(base+people[j].first*m+people[j].second);
                    }
                }
            }
        }
        memset(match, -1, sizeof(match));
        int cnt = 0;
        for (int i = 0; i < bin*d; i++) {
            if (match[i] == -1) {
                memset(used, false, sizeof(used));
                if (dfs(i)) cnt++;
                if (cnt == p) {
                    cout << i/d+1 << '\n';
                    break;
                }
            }
        }
    }

}


