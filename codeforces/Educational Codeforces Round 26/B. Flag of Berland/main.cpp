#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 110;
char flag[MAXN][MAXN];

bool used[128];
int m, n;

bool checkrow() {
    memset(used, 0, sizeof(used));
    for (int k = 0; k < 3; k++) {
        char now = flag[m/3*k][0];
        if (used[now]) return false;
        used[now] = true;
        for (int i = m/3*k; i < m/3*(k+1); i++) {
            for (int j = 0; j < n; j++) {
                if (flag[i][j] != now) return false;
            }
        }

    }
    return true;

}

bool checkcol() {
    memset(used, 0, sizeof(used));
    for (int k = 0; k < 3; k++) {
        char now = flag[0][n/3*k];
        if (used[now]) return false;
        used[now] = true;
        for (int j = n/3*k; j < n/3*(k+1); j++) {
            for (int i = 0; i < m; i++) {
                if (flag[i][j] != now) return false;
            }
        }

    }
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        getchar();
        for (int j = 0; j < n; j++) {
            scanf("%c", &flag[i][j]);
        }
    }
    if (m%3==0 && checkrow()) cout << "YES" << endl;
    else if (n%3==0 && checkcol()) cout << "YES" << endl;
    else cout << "NO" << endl;



    return 0;
}