#include <iostream>
using namespace std;
const int MAXN = 200;
int lft[MAXN], rght[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf("%c", &c);
            if (c == 'W') {
                if (lft[i] == 0) lft[i] = j;
                rght[i] = j;
            }
        }
    }
    int ret = 0;
    int i = 1, j = 1;
    int delta = 1;
    while (i <= n) {
        if (delta == 1) {
            if (rght[i] > j || rght[i+1] > j) {
                j++;
                ret++;
            }
            else {
                i++;
                delta = -delta;
                ret++;
            }

        }
        else {
            if ((lft[i]!=0 && lft[i] < j) || (lft[i+1]!=0 && lft[i+1] < j)) {
                j--;
                ret++;
            }
            else {
                i++;
                delta = -delta;
                ret++;
            }

        }
    }
    for (int i = n+1; i >= 1; i--) {
        if (lft[i] == 0) ret--;
        else break;
    }
    cout << ret << endl;


    return 0;
}