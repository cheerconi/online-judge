#include <iostream>
#include <string>
using namespace std;

bool big(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    char table[256];
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        table[s1[i]] = s2[i];
    }
    string s3;
    cin >> s3;
    string ret;
    for (int i = 0; i < s3.size(); i++) {
        if (big(s3[i])) {
            ret.push_back(table[s3[i]-'A'+'a']-'a'+'A');
        }
        else if(isdigit(s3[i])) {
            ret.push_back(s3[i]);
        }
        else{
            ret.push_back(table[s3[i]]);
        }

    }
    cout << ret << endl;
    return 0;
}