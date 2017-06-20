#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minus_col();
void minus_row();

vector<vector<int> > board;
vector<int> steps;
vector<int> pos;
int cnt = 0;

void minus_row() {
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) {
        int tmp = INT_MAX;
        for (int j = 0; j < col; j++) {
            tmp = min(tmp, board[i][j]);
        }
        if (tmp > 0) {
            for (int j = 0; j < col; j++) board[i][j] -=tmp;
            steps.push_back(tmp);
            pos.push_back(i);
            cnt -= tmp * col;
        }
    }
}


void minus_col() {
    int row = board.size();
    int col = board[0].size();
    for (int j = 0; j < col; j++) {
        int tmp = INT_MAX;
        for (int i = 0; i < row; i++) {
            tmp = min(tmp, board[i][j]);
        }
        if (tmp > 0) {
            for (int i = 0; i < row; i++) board[i][j] -=tmp;
            steps.push_back(-tmp);
            pos.push_back(j);
            cnt -= tmp * row;
        }
    }
}

int main() {
    //freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    board = vector<vector<int> >(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            cnt += board[i][j];
        }
    }
    if (n >= m) {
        minus_col();
        minus_row();
    }
    else {
        minus_row();
        minus_col();
    }
    if (cnt != 0) cout << "-1" <<endl;
    else {
        int cnt = 0;
        for (int tmp : steps) cnt += abs(tmp);
        cout << cnt << endl;
        for (int i = 0; i < steps.size(); i++) {
            string tmp = steps[i] > 0 ? "row " : "col ";
            for (int j = 0; j < abs(steps[i]); j++) {
                cout << tmp << pos[i]+1 << endl;
            }
        }
    }

    return 0;
}