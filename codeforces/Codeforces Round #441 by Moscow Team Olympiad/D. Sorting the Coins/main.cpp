#include <iostream>
using namespace std;
const int MAXN = 300000 + 10;
bool state[MAXN];
int main () {
//    freopen("test.txt", "r", stdin);
    int n, cnt = 0, val;
    cin >> n;
    int cur = n;
    cout << 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        state[val] = true;
        cnt++;
        while (state[cur]) {
            cur--;
            cnt--;
        }
        printf(" %d", cnt+1);
    }
    cout << endl;
}