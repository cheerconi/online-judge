#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ret;

bool check (int a, int b) {
    string s = to_string(a);
    for (char c : s) {
        a += c - '0';
    }
    return a==b;
}

void solve (int n) {
    for (int i = 0; i <= 100; i++) {
        if (n-i <= 0) break;
        if (check(n - i, n)) ret.push_back(n - i);
    }
}
int main() {
    int n;
    cin >> n;
    solve(n);
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }

}