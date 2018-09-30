#include <iostream>
#include <string>
using namespace std;
const int MAXN = 300 + 10;
string mat[MAXN], sec[MAXN];
int n;
bool check(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sec[i][j] = mat[(i+x)%n][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (sec[i][j] != sec[j][i]) return false;
        }
    }
    return true;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        sec[i] = mat[i];
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (check(i)) ret += n;
    }
    cout << ret << endl;

    return 0;
}