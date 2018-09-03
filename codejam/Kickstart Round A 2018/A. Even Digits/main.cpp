#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
LL my_minus (LL num) {
    string s = to_string(num);
    string ret;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        if ((s[i]-'0') % 2 == 0) {
            ret.push_back(s[i]);
            continue;
        }
        ret.push_back(s[i]-1);
        ret.append(string(n-i-1, '8'));
        break;
    }
    return stoll(ret);
}
LL my_add (LL num) {
    string s = to_string(num);
    string ret;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        if ((s[i]-'0') % 2 == 0) {
            ret.push_back(s[i]);
            continue;
        }
        if (s[i] == '9') {
            ret = string(1, '0') + s;
            ret[i] = ret[i] + 1;
            for (int j = i+1; j < ret.size(); j++) ret[j] = '0';
            return my_add (stoll(ret));
        }
        ret.push_back(s[i]+1);
        ret.append(string(n-i-1, '0'));
        break;
    }
    return stoll(ret);
}
int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL cs, val, a, b, ret;
    cin >> cs;
    for (int i = 1; i <= cs; i++) {
        cin >> val;
        a = my_minus(val);
        b = my_add(val);
        ret = min(abs(a-val), abs(b-val));
        cout << "Case #" << i << ": " << ret << '\n';
    }
    return 0;
}