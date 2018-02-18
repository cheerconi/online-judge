#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
int nums[MAXN];

bool solve(int n, int a, int b) {
    if (b > a) swap(b, a);
    for (int k = 0; b*k <= n; k++) {
        int m = n - b*k;
        if (m % a == 0) {
            int i = 1;
            while (i <= m) {
                int bk = i;
                for (int j = 0; j < a; j++) {
                    nums[i] = i+1;
                    i++;
                }
                nums[bk+a-1] = bk;
            }
            while (i <= n) {
                int bk = i;
                for (int j = 0; j < b; j++) {
                    nums[i] = i+1;
                    i++;
                }
                nums[bk+b-1] = bk;
            }
            return true;
        }
    }
    return false;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    if (solve(n, a, b)) {
        for (int i = 1; i <= n; i++) {
            cout << nums[i];
            if (i == n) cout << endl;
            else cout << ' ';
        }

    }
    else cout << -1 << endl;

    return 0;
}