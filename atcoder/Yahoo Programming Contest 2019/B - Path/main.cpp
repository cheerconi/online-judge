#include <iostream>
using namespace std;

int cnt[10];

int main() {
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 1; i <= 4; i++) {
        if (cnt[i] == 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}