#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
string s1[MAXN];
string s2[MAXN];
int num[MAXN];
int ind[MAXN];

bool cmp (int i, int j) {
    if (s1[i] != s1[j]) return s1[i] < s1[j];
    return num[i] < num[j];
}

int romanToInt(string s) {
    int i = 0;
    int len = s.size();
    int num =0;
    while(i < len) {
        if (s[i] == 'M') {
            num += 1000;
            i++;
            continue;
        }
        if (s[i] == 'D') {
            num += 500;
            i++;
            continue;
        }
        if (s[i] == 'C' && i+1 < len && s[i+1]=='M') {
            num += 900;
            i += 2;
            continue;
        }
        else if (s[i] == 'C' && i+1 < len && s[i+1]=='D') {
            num += 400;
            i += 2;
            continue;
        }
        else if (s[i] == 'C') {
            num += 100;
            i++;
            continue;
        }
        if (s[i] == 'L') {
            num += 50;
            i++;
            continue;
        }
        if (s[i] == 'X' && i+1 < len && s[i+1]=='C') {
            num += 90;
            i += 2;
            continue;
        }
        else if (s[i] == 'X' && i+1 < len && s[i+1]=='L') {
            num += 40;
            i += 2;
            continue;
        }
        else if (s[i] == 'X') {
            num += 10;
            i++;
            continue;
        }
        if (s[i] == 'V') {
            num += 5;
            i++;
            continue;
        }
        if (s[i] == 'I' && i+1 < len && s[i+1]=='X') {
            num += 9;
            i += 2;
            continue;
        }
        else if (s[i] == 'I' && i+1 < len && s[i+1]=='V') {
            num += 4;
            i += 2;
            continue;
        }
        else if (s[i] == 'I') {
            num += 1;
            i++;
            continue;
        }
    }
    return num;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        s1[i] = a;
        s2[i] = b;
        num[i] = romanToInt(b);
        ind[i] = i;
    }
    sort(ind, ind+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s1[ind[i]] << ' ' << s2[ind[i]] << endl;
    }
    return 0;
}