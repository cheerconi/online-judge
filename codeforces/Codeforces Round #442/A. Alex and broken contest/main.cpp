#include <iostream>
#include <string>
using namespace std;
string s;

int solve(string pa) {
    int m = pa.size();
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, m) == pa) cnt++;
    }
    return cnt;
}

int main() {

    cin >> s;
    int cnt = 0;
    cnt += solve("Danil");
    cnt += solve("Olya");
    cnt += solve("Slava");
    cnt += solve("Ann");
    cnt += solve("Nikita");
    if (cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}