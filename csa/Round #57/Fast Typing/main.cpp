#include <iostream>
#include <algorithm>
using namespace std;
int nums[26];
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        cin >> nums[i];
    }
    int ret = 0;
    for (char c : s) {
        ret += nums[c-'a'];
    }
    cout << ret << endl;
    return 0;
}