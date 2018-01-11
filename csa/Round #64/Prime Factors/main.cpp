#include <iostream>
using namespace std;
int primes[4] = {2, 3, 5, 7};
int solve(int p) {
    cout << "Q " << p << endl;
    int val;
    cin >> val;
    return val;
}

int main() {
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int val = solve(primes[i]);
        while (val > 0) {
            val--;
            ret *= primes[i];
        }
    }
    cout << "A " << ret << endl;

    return 0;
}