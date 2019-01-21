#include <iostream>
using namespace std;

string s;
int k;

int solve(char c) {
    int cur = 0, ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != c) {
            ret += cur / k;
            cur = 0;
            continue;
        }
        cur++;
    }
    ret += cur / k;
    return ret;
}


int main() {
    int n;
    cin >> n >> k  >> s;
    int x = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        x = max(x, solve(c));
    }
    cout << x << endl;
    return 0;
}