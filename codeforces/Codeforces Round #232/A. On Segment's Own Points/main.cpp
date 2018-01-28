#include <iostream>
using namespace std;
const int MAXN = 123;
bool vis[MAXN];
int main() {
    int n; cin >> n;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        vis[i] = true;
    }
    for (int i = b; i < 100; i++) {
        vis[i] = true;
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            vis[j] = true;
        }
    }
    int ret = 0;
    for (int i = 0; i < 100; i++) {
        if (!vis[i]) ret++;
    }
    cout << ret << endl;

    return 0;
}