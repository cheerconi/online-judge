#include <iostream>
const int MAXN = 110;
int graph[MAXN][MAXN];
int h, w;
int cnt = 0;

void solve(int color, int time) {
    if (time == 0) return;
    int x = cnt / w;
    int y = cnt % w;
    if (x % 2 == 1) y = w - y - 1;
    graph[x][y] = color;
    cnt++;
    solve(color, time-1);

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &h, &w);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        solve(i, a);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d", graph[i][j]);
            if(j != w-1) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}