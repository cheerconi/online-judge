#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int code[71], base[25];
void make_table() {
    vector<int> primes;
    for (int i = 2; i <= 69; i++) {
        bool flag = true;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes.push_back(i);
    }
    for (int i = 1; i <= 70; i++) {
        int val = 0, num = i;
        for (int j = 0; j < primes.size() && primes[j] <= num; j++) {
            while (num % primes[j] == 0) {
                num /= primes[j];
                val ^= 1<<j;
            }
        }
        code[i] = val;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    make_table();
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        val = code[val];
        for (int i = 20; i >= 0 && val != 0; i--) {
            if (val & (1<<i)) {
                if (base[i] == 0) {
                    base[i] = val;
                    break;
                }
                else {
                    val ^= base[i];
                }
            }
        }
    }
    int m = 0;
    for (int i = 0; i < 25; i++) {
        if (base[i] != 0) m++;
    }
    int ret = 1;
    for (int i = m; i < n; i++) {
        ret = ret * 2 % mod;
    }
    ret = (ret + mod - 1) % mod;
    cout << ret << endl;
}