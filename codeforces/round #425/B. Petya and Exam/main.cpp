#include <iostream>
#include <string>
using namespace std;
bool good[256];

int main() {
//    freopen("test.txt", "r", stdin);
    string tmp;
    cin >> tmp;
    for (char c : tmp) good[c] = true;
    string pattern;
    cin >> pattern;
    int n;
    scanf("%d", &n);
    while(n--) {
        cin >> tmp;
        int jump = (int)tmp.size() - (int)pattern.size() + 1;
        if (jump < 0) {
            cout << "NO" << endl;
            continue;
        }
        int j = 0;
        bool flag = true;
        for (char c : pattern) {
            if (c == '*') {
                for (int k = 0; k < jump; k++) {
                    if (good[tmp[j+k]]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
                j += jump - 1;
            }
            else if (c == '?'){
                if (!good[tmp[j]]) {
                    flag = false;
                    break;
                }
            }
            else {
                if (c != tmp[j]) {
                    flag = false;
                    break;
                }
            }
            j++;
        }
        if (j != tmp.size()) flag = false;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}