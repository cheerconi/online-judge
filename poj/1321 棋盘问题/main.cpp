#include <iostream>
#include <vector>
using namespace std;
static const int MAXN = 8;
vector<int> row[MAXN];
vector<bool> colused(MAXN, false);
vector<bool> rowused(MAXN, false);
int cnt, n;
void dfs(int i, int j, int need) {
    if (need == 0) {
        cnt++;
        return;
    }
    for (int k = i+1; k < n; k++) {
        if (rowused[k]) continue;
        for (int m = 0; m < row[k].size(); m++) {
            if (colused[row[k][m]]) continue;
            rowused[k] = true;
            colused[row[k][m]] = true;
            dfs(k, row[k][m], need-1);
            rowused[k] = false;
            colused[row[k][m]] = false;
        }
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int k;
    char c;

    while (scanf("%d%d", &n, &k) && n != -1) {
        for (int i = 0; i < n; i++) {
            row[i].clear();
            colused[i] = false;
            rowused[i] = false;
        }
        cnt = 0;
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < n; j++) {
                scanf("%c", &c);
                if (c == '#') {
                    row[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < row[i].size(); j++) {
                rowused[i] = true;
                colused[row[i][j]] = true;
                dfs(i, row[i][j], k-1);
                rowused[i] = false;
                colused[row[i][j]] = false;
            }
        }
        cout << cnt << endl;


    }
    return 0;
}