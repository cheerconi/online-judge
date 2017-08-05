#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int x[MAXN];
int y[MAXN];
int ret = 0;
int a, b;

bool check(int i, int j) {
    int tmpx = x[i]+x[j];
    int tmpy = max(y[i],y[j]);
    if (min(tmpx, tmpy) <= min(a, b) && max(tmpx, tmpy) <= max(a,b)) return true;
    tmpx = x[i] + y[j];
    tmpy = max(y[i], x[j]);
    if (min(tmpx, tmpy) <= min(a, b) && max(tmpx, tmpy) <= max(a,b)) return true;
    tmpx = y[i] + x[j];
    tmpy = max(x[i], y[j]);
    if (min(tmpx, tmpy) <= min(a, b) && max(tmpx, tmpy) <= max(a,b)) return true;
    tmpx = y[i] + y[j];
    tmpy = max(x[i], x[j]);
    if (min(tmpx, tmpy) <= min(a, b) && max(tmpx, tmpy) <= max(a,b)) return true;
    return false;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (check(i, j)) {
                ret = max(ret, x[i]*y[i]+x[j]*y[j]);
            }
        }
    }
    cout << ret << endl;


    return 0;
}