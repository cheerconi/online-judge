#include <iostream>
#include <string>
using namespace std;
bool state[105];

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if(s[i] == 'K' && s[i-1] == 'V') {
            cnt++;
            state[i] = state[i-1] = true;
            i++;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (!state[i] && !state[i-1] && s[i] == s[i-1]) {
            cnt++;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}