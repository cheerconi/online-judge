#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> pos;
vector<int> times;
int cnt = 0;
vector<vector<int> > board;


bool solve() {
    int tmp;
    int row = board.size();
    int col = board[0].size();

    if (row >= col) {
        for (int j = 0; j < col; j++) {
            tmp = INT_MAX;
            for (int i = 0; i < row; i++) {
                tmp = min(tmp, board[i][j]);
            }
            if (tmp == 0) continue;
            if (tmp < 0) return false;
            pos.push_back(-(j+1));
            times.push_back(tmp);
            for (int i = 0; i < row; i++) {
                board[i][j] -= tmp;
            }
            cnt -= tmp * row;

        }
        for (int i = 0; i < row; i++) {
            tmp = INT_MAX;
            for (int j = 0; j < col; j++) {
                tmp = min(tmp, board[i][j]);
            }
            if (tmp == 0) continue;
            if (tmp < 0) return false;
            pos.push_back(i+1);
            times.push_back(tmp);
            for (int j = 0; j < col; j++) {
                board[i][j] -= tmp;
            }
            cnt -= tmp * col;

        }
    }
    else {
        for (int i = 0; i < row; i++) {
            tmp = INT_MAX;
            for (int j = 0; j < col; j++) {
                tmp = min(tmp, board[i][j]);
            }
            if (tmp == 0) continue;
            if (tmp < 0) return false;
            pos.push_back(i+1);
            times.push_back(tmp);
            for (int j = 0; j < col; j++) {
                board[i][j] -= tmp;
            }
            cnt -= tmp * col;

        }
        for (int j = 0; j < col; j++) {
            tmp = INT_MAX;
            for (int i = 0; i < row; i++) {
                tmp = min(tmp, board[i][j]);
            }
            if (tmp == 0) continue;
            if (tmp < 0) return false;
            pos.push_back(-(j+1));
            times.push_back(tmp);
            for (int i = 0; i < row; i++) {
                board[i][j] -= tmp;
            }
            cnt -= tmp * row;

        }

    }
    if (cnt != 0) return false;
    return true;


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
    if (solve()) {
        for (int i = 0; i < times.size(); i++) {
            for (int j = 0; j < times[i]; j++) {
                if (pos[i] > 0) {
                    cout << "row " << pos[i] << endl;
                }
                else {
                    cout << "col " << -pos[i] << endl;
                }
            }
        }
    }
    else cout << "-1" << endl;
    return 0;
}