#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
int color[2][MAXN], cnt[123];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> color[0][i];
        cnt[color[0][i]]++;
    }
    int ma = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt[i] > cnt[ma]) ma = i;
    }
    sort (color[0], color[0]+n);
    int ret = 0, bias0 = 0, bias1 = 0;
    while (color[0][bias0] != ma) bias0++;
    bias1 = bias0;
    while (bias1 < n && color[0][bias0] == color[0][bias1]) bias1++;
    for (int i = 0; i < n; i++) {
        color[1][(i+bias0)%n] = color[0][(i+bias1)%n];
        if (color[1][(i+bias0)%n] != color[0][(i+bias0)%n]) ret++;
    }
    cout << ret << endl;
    for (int i = 0; i < n; i++) {
        cout << color[0][i] << ' ' << color[1][i] << endl;
    }
    return 0;
}