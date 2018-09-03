#include <iostream>
using namespace std;
char board[10][10];

int cnt(int i, int j, int di, int dj) {
    int ret = 1;
    int x = i + di;
    int y = j + dj;
    while (x >= 0 && y >= 0 && x < 10 && y < 10 && board[x][y]=='X') {
        ret++;
        x += di;
        y += dj;
    }
    x = i - di;
    y = j - dj;
    while (x >= 0 && y >= 0 && x < 10 && y < 10 && board[x][y]=='X') {
        ret++;
        x -= di;
        y -= dj;
    }
    return ret;

}

bool check(int i, int j) {
    if (board[i][j] == 'X' || board[i][j] == 'O') return false;
    if (cnt(i, j, 1, 0) >= 5) return true;
    if (cnt(i, j, 0, 1) >= 5) return true;
    if (cnt(i, j, 1, 1) >= 5) return true;
    if (cnt(i, j, 1, -1) >= 5) return true;
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    char c;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%c", &c);
            board[i][j] = c;
        }
        getchar();
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (check(i, j)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;

}