#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 1e5 + 10;
int pos[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    pos[n] = 1; pos[n+1] = 1e6;
    n += 2;
    sort(pos, pos+n);
    int ret = INT_MAX, end = 1e6;
    for (int i = 0; i+1 < n; i++) {
        ret = min(ret, max(pos[i]-1, end-pos[i+1]));
    }
    cout << ret << endl;

    return 0;
}