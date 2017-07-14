#include <iostream>
#include <limits.h>
#include <memory.h>
using namespace std;

int step = INT_MAX;
const int MAXN = 20;
int ret[MAXN][MAXN];
int tile[MAXN][MAXN];
int state[MAXN][MAXN];
int tmp_tile[MAXN][MAXN];
int tmp_state[MAXN][MAXN];
int m;
int n;



void flip(int i, int j) {
    tmp_tile[i][j] = (tmp_tile[i][j]+1) % 2;
    if (i-1 >= 0) tmp_tile[i-1][j] = (tmp_tile[i-1][j]+1) % 2;
    if (i+1 < m) tmp_tile[i+1][j] = (tmp_tile[i+1][j]+1) % 2;
    if (j-1 >= 0) tmp_tile[i][j-1] = (tmp_tile[i][j-1]+1) % 2;
    if (j+1 < n) tmp_tile[i][j+1] = (tmp_tile[i][j+1]+1) % 2;
    return;
}

void dfs(int k) {
    if (k == n) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp_tile[i][j] = tile[i][j];
            }
        }
        memset(tmp_state, 0, sizeof(tmp_state));
        for (int i = 0; i < n; i++) tmp_state[0][i] = state[0][i];

        for (int i = 0; i < n; i++) {
            if (tmp_state[0][i] == 1) {
                flip(0, i);
                cnt++;
                if (cnt >= step) return;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp_tile[i-1][j] == 1) {
                    tmp_state[i][j] = 1;
                    flip(i, j);
                    cnt++;
                    if (cnt >= step) return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (tmp_tile[m-1][i] != 0) return;
        }
        step = cnt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                ret[i][j] = tmp_state[i][j];
        }
        return;
    }
    dfs(k+1);
    state[0][k] = 1;
    dfs(k+1);
    state[0][k] = 0;

}


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tile[i][j]);
        }
    }
    memset(state, 0, sizeof(state));
    dfs(0);
    if (step == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        printf("%d", ret[i][0]);
        for (int j = 1; j < n; j++) {
            printf(" %d", ret[i][j]);
        }
        printf("\n");
    }



    return 0;
}