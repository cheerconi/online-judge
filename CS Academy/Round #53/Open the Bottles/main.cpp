#include <iostream>
#include <limits.h>
using namespace std;
int cost[3][3];

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    int ret = INT_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int tmp = cost[0][i] + cost[1][j] + cost[2][k];
                ret = min(ret, tmp);
            }
        }
    }
    cout << ret << endl;
    return 0;
}