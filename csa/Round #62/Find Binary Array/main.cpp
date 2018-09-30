#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], ret[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == a[i-1]+1) {
            ret[i-1] = 0;
        }
        else ret[i-1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (b[n-1] == 1) ret[n] = 0;
    else ret[n] = 1;
    for (int i = 1; i <= n; i++) cout << ret[i];
    cout << endl;
    return 0;
}