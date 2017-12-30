#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 55;
char graph[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int s1, s2;
vector<int> v;
string s;

bool check () {
    int x = s1, y = s2;
    for (char c : s) {
        int cmd = v[c - '0'];
        x += dx[cmd];
        y += dy[cmd];
        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= m) return false;
        if (graph[x][y] == '#') return false;
        if (graph[x][y] == 'E') {
            return true;
        }
    }
    return false;

}


int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &graph[i][j]);
            if (graph[i][j] == 'S') {
                s1 = i;
                s2 = j;
            }
        }
    }

    cin >> s;

    for (int i = 0; i < 4; i++) v.push_back(i);
    int cnt = 0;
    do {
        if (check())  cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;

    return 0;
}