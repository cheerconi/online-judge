#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
int d;
string s;
LL count(){
    LL cur = 1, ret = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'C') cur *= 2;
        else ret += cur;
    }
    while (!s.empty() && s.back() == 'C'){
        s.pop_back();
    }
    return ret;
}
int solve (){
    int cnt = 0;
    LL cur = count();
    while (cur > d) {
        if (s.size() == 1) {
            cnt = -1;
            break;
        }
        bool flag = false;
        for (int j = (int)s.size()-1; j >=1; j--) {
            if (s[j-1] == 'C' && s[j] == 'S') {
                swap(s[j-1], s[j]);
                flag = true;
                break;
            }
        }
        if (!flag) {
            cnt = -1;
            break;
        }
        cur = count();
        cnt++;
    }
    return cnt;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    for (int k = 1; k <= cs; k++){
        cin >> d >> s;
        int ret = solve();
        cout << "Case #" << k << ": ";
        if (ret == -1) cout << "IMPOSSIBLE\n";
        else cout << ret << '\n';
    }
    return 0;
}