#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];
int cur;
bool solve(int left, int right, int k) {
    k--;
    if (k < 0 || k % 2 != 0) return false;
    if (k == 0) {
        for (int i = right-1; i >= left; i--) {
            nums[i] = cur--;
        }
        return true;
    }
    if (left+1 == right) return false;
    int mid = (right + left) / 2;
    int tmp = k/2;
    if (tmp % 2 == 0) tmp--;
    if (!solve(left, mid, tmp)) return false;
    if (!solve(mid, right, k - tmp)) return false;
    return true;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    cur = n;
    if (solve(0, n, k)) {
        for (int i = 0; i < n; i++) {
            printf("%d", nums[i]);
            if (i+1 == n) printf("\n");
            else printf(" ");
        }
    }
    else cout << -1 << endl;

    return 0;
}