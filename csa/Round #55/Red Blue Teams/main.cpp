#include <iostream>
using namespace std;

int solve0 (int n, int r, int k) {
    if (r >= k) return r-k;
    k -= r;
    return k;
}
int solve1(int n, int r, int k) {
    if (n-r >= k) return r+k;
    k -= (n-r);
    return n-k;
}

int main() {
    int n, r, k;
    cin >> n >> r >> k;
    cout << solve0(n, r, k) << ' ' << solve1(n, r, k) << endl;

    return 0;
}