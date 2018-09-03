#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;
char s[MAXN];
int n, m;
bool solve (int len) {
    int cnt = 0, i = 0;
    while (i < m) {
        if (len+i >= m) {
            i = m;
        }
        for (int j = len-1; j >= 0 && j+i < m; j--) {
            if (s[j+i] == ' ' || s[j+i] == '-') {
                i += j + 1;
                break;
            }
        }
        cnt++;
        if (cnt > n) return false;
    }
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    getchar();
    for (m = 0;; m++) {
        if (scanf("%c", &s[m]) == EOF) break;
        if (s[m] == '\n') break;
    }

    int left = 1, right = m;
    while (left < right) {
        int mid = (left+right) >> 1;
        if (solve(mid)) right = mid;
        else left = mid+1;
    }
    cout << left << endl;


    return 0;
}