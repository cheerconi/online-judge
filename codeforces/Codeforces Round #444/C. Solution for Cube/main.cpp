#include <iostream>
#include <set>
using namespace std;
int cubes[6][4];
int a, b;

void get(int k) {
    for (int i = 0; i < 4; i++) {
        cin >> cubes[k][i];
    }
}

bool check() {
    set<int> same;
    for (int i = 0; i < 6; i++) {
        bool flag = true;
        for (int j = 0; j < 3 && flag; j++) {
            if (cubes[i][j] != cubes[i][j+1]) flag = false;
        }
        if (flag) same.insert(i);
    }
    if (same.size() != 2) return false;
    a = *same.begin();
    b = *same.rbegin();
    if (a + 1 != b) return false;
    if (a % 2 != 0) return false;
    return true;
}

bool solve() {
    if (a == 0) {
        if (cubes[4][0] != cubes[4][1]) return false;
        if (cubes[4][2] != cubes[4][3]) return false;
        if (cubes[2][0] != cubes[2][1]) return false;
        if (cubes[2][2] != cubes[2][3]) return false;
        if (cubes[5][0] != cubes[5][1]) return false;
        if (cubes[5][2] != cubes[5][3]) return false;
        if (cubes[3][0] != cubes[3][1]) return false;
        if (cubes[3][2] != cubes[3][3]) return false;
        if (cubes[4][0]==cubes[2][2] && cubes[2][1]==cubes[5][2] && cubes[5][0]==cubes[3][2] && cubes[3][0]==cubes[4][2]) {
            return true;
        }
        if (cubes[4][0]==cubes[3][2] && cubes[3][1]==cubes[5][2] && cubes[5][0]==cubes[2][2] && cubes[2][0]==cubes[4][2]) {
            return true;
        }
        return false;
    }
    if (a == 2) {
        if (cubes[4][0] != cubes[4][2]) return false;
        if (cubes[4][1] != cubes[4][3]) return false;
        if (cubes[0][0] != cubes[0][1]) return false;
        if (cubes[0][2] != cubes[0][3]) return false;
        if (cubes[5][0] != cubes[5][2]) return false;
        if (cubes[5][1] != cubes[5][3]) return false;
        if (cubes[1][0] != cubes[1][1]) return false;
        if (cubes[1][2] != cubes[1][3]) return false;
        if (cubes[4][0]==cubes[1][0] && cubes[1][2]==cubes[5][0] && cubes[5][1]==cubes[0][2] && cubes[0][0]==cubes[4][1]) {
            return true;
        }
        if (cubes[4][0]==cubes[0][2] && cubes[0][0]==cubes[5][0] && cubes[5][1]==cubes[1][0] && cubes[1][2]==cubes[4][1]) {
            return true;
        }
        return false;
    }
    if (a == 4) {
        if (cubes[2][0] != cubes[2][2]) return false;
        if (cubes[2][1] != cubes[2][3]) return false;
        if (cubes[0][0] != cubes[0][2]) return false;
        if (cubes[0][1] != cubes[0][3]) return false;
        if (cubes[3][0] != cubes[3][2]) return false;
        if (cubes[3][1] != cubes[3][3]) return false;
        if (cubes[1][0] != cubes[1][2]) return false;
        if (cubes[1][1] != cubes[1][3]) return false;
        if (cubes[0][0]==cubes[2][1] && cubes[2][0]==cubes[1][1] && cubes[1][0]==cubes[3][0] && cubes[3][1]==cubes[0][1]) {
            return true;
        }
        if (cubes[0][0]==cubes[3][0] && cubes[3][1]==cubes[1][1] && cubes[1][0]==cubes[2][1] && cubes[2][0]==cubes[0][1]) {
            return true;
        }
    }
    return false;

}
int main() {
    get(0);
    get(2);
    get(1);
    get(4);
    get(5);
    get(3);
    if (!check()) return cout << "NO" << endl, 0;
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}