#include <iostream>
#include <string>
using namespace std;

int ret = 0;

bool checkop(char c) {
    if (c == '+' || c == '-') return true;
    if (c == '*' || c == '/') return true;
    return false;
}

void solve(string & s) {
    int num[2] = {0};
    char op;
    int cnt = 0;
    int i = 0;
    int j;
    while (i < s.size()) {
        j = i;
        while (j < s.size()) {
            if (s[j] == '(') {
                if (i == j) j++;
                else {
                    i = j;
                    num[0] = num[1] = 0;
                    cnt = 0;
                }
                continue;
            }
            if ((i == j && s[j]=='-') || (i+1==j) && s[i]=='(' && s[j]=='-' || (j>=1 && s[j]=='-' && checkop(s[j-1]))) {
                j++;
                while (j < s.size() && isdigit(s[j])) num[cnt] = num[cnt]*10 + s[j++]-'0';
                num[cnt] = -num[cnt];
                continue;
            }
            if (isdigit(s[j])) num[cnt] = num[cnt]*10 + s[j++] - '0';
            else {
                cnt++;
                if (s[j] != ')' && cnt == 1) op = s[j++];
                else break;
            }
        }
        if (j == s.size()) cnt++;
        if (cnt == 1) {
            if (s[i] == '(' && s[j] == ')') {
                s = s.substr(0,i) + to_string(num[0]) + s.substr(j+1);
                solve(s);
            }
            else {
                ret = num[0];
            }
            return;
        }
        if (j==s.size() || op=='*' || op=='/' || s[j]==')' || s[j]=='+' || s[j]=='-') {
            if (op == '+') num[0] = num[0] + num[1];
            else if (op == '-') num[0] = num[0] - num[1];
            else if (op == '*') num[0] = num[0] * num[1];
            else if (op == '/') num[0] = num[0] / num[1];
            if (s[i] == '(') i++;
            s = s.substr(0, i) + to_string(num[0]) + s.substr(j);
            solve(s);
            return;
        }
        else {
            cnt = 0;
            num[0] = num[1] = 0;
            while (s[i] != op) i++;
            i++;
        }

    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    solve(s);
    cout << ret << endl;
    return 0;
}