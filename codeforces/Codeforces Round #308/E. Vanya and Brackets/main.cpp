#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long LL;
string s;
vector<int> idx;
LL solve () {
    LL ret = 0;
    for (int i = 0; i < idx.size(); i++) {
        for (int j = i+1; j < idx.size(); j++) {
            stack<LL> stk;
            for (int a = 0; a < idx[i]; a++) {
                if (isdigit(s[a])) {
                    stk.push(s[a]-'0');
                }
                else if (s[a] == '*') {
                    a++;
                    LL cur = stk.top(); stk.pop();
                    stk.push(cur*(s[a]-'0'));
                }
            }
            int sz = stk.size();
            for (int a = idx[i]+1; a < idx[j]; a++) {
                if (isdigit(s[a])) {
                    stk.push(s[a]-'0');
                }
                else if (s[a] == '*') {
                    a++;
                    LL cur = stk.top(); stk.pop();
                    stk.push(cur*(s[a]-'0'));
                }
            }
            while (stk.size() > sz+1) {
                LL cur = stk.top(); stk.pop();
                cur += stk.top(); stk.pop();
                stk.push(cur);
            }
            LL cur = stk.top(); stk.pop();
            cur *= stk.top(); stk.pop();
            stk.push(cur);
            for (int a = idx[j]; a < s.size(); a++) {
                if (isdigit(s[a])) {
                    stk.push(s[a]-'0');
                }
                else if (s[a] == '*') {
                    a++;
                    LL cur = stk.top(); stk.pop();
                    stk.push(cur*(s[a]-'0'));
                }
            }
            LL tmp = 0;
            while (!stk.empty()) {
                tmp += stk.top();
                stk.pop();
            }
            ret = max(ret, tmp);
        }
    }
    return ret;

}


int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    s = "1*" + s + "*1";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') idx.push_back(i);
    }
    cout << solve() << endl;


}