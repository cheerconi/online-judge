#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL a[MAXN], b[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    LL x = a[0], y = b[0], cnt = 0, i = 1, j = 1;
    while (i < n && j < m) {
        if (x == y) {
            cnt++;
            x += a[i++];
            y += b[j++];
        }
        else if (x > y) {
            y += b[j++];
        }
        else {
            x += a[i++];
        }
    }
    cnt++;
    cout << cnt << endl;


    return 0;
}