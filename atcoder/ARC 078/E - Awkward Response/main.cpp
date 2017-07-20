#include <iostream>
#include <string>
using namespace std;
typedef long long LL;


void findzero() {
    int ret = 1;
    for (int i = 2; 2*i/2 == i; i *= 10) {
        cout << "? " << i << endl;
        string s;
        cin >> s;
        if (s == "Y") {
            break;
        }
        else ret *= 10;
    }
    cout << "! " << ret << endl;
}
int findbase() {
    for (int i = 100000000; i >= 1; i /= 10) {
        cout << "? " << i << endl;
        string s;
        cin >> s;
        if (s == "Y") {
            return i;
        }
    }
}
void search(LL base) {
    LL left = base + 1;
    LL right = base * 10 - 1;
    while (left < right) {
        LL mid = (left+right) >> 1;
        cout << "? " << mid*10 << endl;
        string s;
        cin >> s;
        if (s == "Y") {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << "! " << left << endl;
}

int main() {
    cout << "? " << 1000000000 << endl;
    string s;
    cin >> s;
    if (s == "Y") {
        findzero();
    }
    else {
        int base = findbase();
        search(base);
    }
    return 0;
}