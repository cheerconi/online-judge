#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

bool check(vector<int> ind, int i) {
    if (abs(i - ind[0]) < 10) return false;
    if (abs(i - ind[1]) < 10) return false;
    if ((i-ind[0]) % 10 == 0) return false;
    if ((i-ind[1]) % 10 == 0) return false;
    if (i % 11 == 0 && i <= ind[1]) return false;
    if (abs(ind[0]+100-i) < 10) return false;
    if (abs(i+100-ind[1]) < 10) return false;
    return true;
}

void solve (vector<int> ind) {
    int tmp;
    if (ind.size() == 2) {
        int cnt = 11 - ind[1]/11 - 1;
        int i = (ind[1] + 11) % 100;
        while (cnt) {
            if (check(ind, i)) {
                cout << i << endl;
                cin >> tmp;
                assert(tmp == 0);
                cnt--;
            }
            i = (i + 1) % 100;
        }
    }
    else {
        cout << (ind[0]+10)%100 << endl;
        cin >> tmp;
        assert(tmp == 1);
    }
}

int main() {
    int tests, tmp;
    cin >> tests;
    while (tests--) {
        vector<int> ind;
        for (int i = 0; i < 100; i += 11) {
            cout << i << endl;
            cin >> tmp;
            if (tmp == 1) ind.push_back(i);
            if (ind.size() == 2) break;
        }
        solve(ind);
    }

}

