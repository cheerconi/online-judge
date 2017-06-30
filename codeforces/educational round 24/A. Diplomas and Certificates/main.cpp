#include <iostream>

typedef long long LL;

using namespace std;

int main() {
    LL n, k;
    cin >> n >> k;
    LL winner = n >> 1;
    LL dip = winner / (k+1);
    LL cert = dip * k;
    LL other = n - cert - dip;
    cout << dip << ' ' << cert << ' ' << other << endl;
    return 0;
}