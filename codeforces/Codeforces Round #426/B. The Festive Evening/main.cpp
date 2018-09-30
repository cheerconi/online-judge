#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
int last[26];
bool door[26];

int main() {
//    freopen("test.txt", "r", stdin);
    memset(last, -1, sizeof(last));
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        last[s[i]-'A'] = i;
    }
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (!door[s[i]-'A'] && last[s[i]-'A'] != i) {
            cnt++;
            door[s[i]-'A'] = true;
        }
        else if (door[s[i]-'A'] && last[s[i]-'A'] == i) {
            cnt--;
        }
        else if (!door[s[i]-'A'] && last[s[i]-'A'] == i) {
            if (cnt == k) {
                flag = false;
                break;
            }
        }
        if (cnt > k) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}