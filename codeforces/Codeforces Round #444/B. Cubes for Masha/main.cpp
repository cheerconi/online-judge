#include <iostream>
#include <set>
using namespace std;
set<int> cubes[3];

bool check (int val) {
    if (val >= 1000) return false;
    if (val <= 9) {
        for (int i = 0; i < 3; i++) {
            if (cubes[i].find(val) != cubes[i].end()) return true;
        }
        return false;
    }
    if (val <= 99) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (cubes[i].find(val/10) != cubes[i].end() && cubes[j].find(val%10) != cubes[j].end()) return true;
            }
        }
        return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            for (int k = 0; k < 3; k++) {
                if (j == k || i == k) continue;
                if (cubes[i].find(val%10) == cubes[i].end()) continue;
                if (cubes[j].find(val/100) == cubes[j].end()) continue;
                int tmp = val / 10 % 10;
                if (cubes[k].find(tmp) != cubes[k].end()) return true;
            }
        }
    }
    return false;
}
int main() {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> val;
            cubes[i].insert(val);
        }
    }
    int i = 1;
    while (true) {
        if (!check(i)) break;
        i++;
    }
    cout << i-1 << endl;
    return 0;
}