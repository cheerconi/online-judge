#include <iostream>
#include <string>
using namespace std;

int count(char c) {
    if (c == '0' || c == '6' || c == '9') return 1;
    if (c == '8') return 2;
    return 0;
}
int main() {
    int a, b;
    cin >> a >> b;
    int ret = 0, id = a;
    for (int i = a; i <= b; i++) {
        string s; s = to_string(i);
        int cur = 0;
        for (char c : s) {
            cur += count(c);
        }
        if (cur > ret) {
            id = i;
            ret = cur;
        }
    }
    cout << id << endl;
    return 0;
}