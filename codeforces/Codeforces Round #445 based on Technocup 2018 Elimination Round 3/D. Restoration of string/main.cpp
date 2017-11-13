#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
bool graph[26][26];
bool used[26];

bool check() {
    for (int i = 0; i < 26; i++) {
        if (graph[i][i]) return false;
        int in = 0, out = 0;
        for (int j = 0; j < 26; j++) {
            if (graph[i][j]) out++;
            if (graph[j][i]) in++;
        }
        if (in > 1 || out > 1) return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        used[s[0]-'a'] = true;
        for (int i = 1; i < s.size(); i++) {
            used[s[i]-'a'] = true;
            int a = s[i-1] - 'a';
            int b = s[i] - 'a';
            graph[a][b] = true;
        }
    }
    if (!check()) {
        cout << "NO" << endl;
        return 0;
    }

    string ret;
    for (int i = 0; i < 26; i++) {
        if (!used[i]) continue;
        bool start = true;
        for (int j = 0; j < 26; j++) {
            if (graph[j][i]) {
                start = false;
                break;
            }
        }
        if (start) {
            int cur = i;
            while (cur != -1) {
                ret.push_back(cur+'a');
                int nxt = cur;
                for (int j = 0; j < 26; j++) {
                    if (graph[cur][j]) {
                        nxt = j;
                        break;
                    }
                }
                if (nxt == cur) cur = -1;
                else cur = nxt;
            }
        }
    }
    int m = 0;
    for (int i = 0; i < 26; i++) m += used[i];
    if (ret.size() != m) {
        ret = "NO";
    }
    cout << ret << endl;


}