#include <iostream>
using namespace std;
const int MAXN = 2e5 + 10;
bool used[MAXN];
int main() {

    int n, val;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (used[val]) {
            cnt++;
        }
        else used[val] = true;
    }
    cout << cnt << endl;
    return 0;
}