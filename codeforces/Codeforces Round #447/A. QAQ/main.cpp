#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >>s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            int a = 0, b = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == 'Q') a++;
            }
            for (int j = i+1; j < n; j++) {
                if (s[j] == 'Q') b++;
            }
            cnt += a*b;
        }
    }
    cout << cnt << endl;


    return 0;
}