#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL cnt[100];
int main() {
//    freopen("test.txt", "r", stdin);
    string s =  "What are you doing at the end of the world? Are you busy? Will you save us?";
    string b = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
    string t = "What are you doing while sending \"";
    string u = "\"? Are you busy? Will you send \"";
    string v = "\"?";
    cnt[0] = s.size();
    for (int i = 1; i <= 55; i++) {
        cnt[i] = cnt[i-1] * 2 + b.size();
    }
    int q;
    cin >> q;
    while (q--) {
        LL n, k;
        cin >> n >> k;
        k--;
        while (n > 56 && k >= t.size()) {
            k -= t.size();
            n--;
        }
        if (n == 56) {
            if (k >= t.size() && k < cnt[n-1]+t.size()) {
                k -= t.size();
                n--;
            }
            else if (k >= cnt[n-1]+t.size()) {
                k -= cnt[n-1]+t.size();
                n--;
            }
        }
        while (n > 0 && k >= t.size()) {
            if (k >= cnt[n]) {
                printf(".");
                k = -1;
                break;
            }
            if (k < cnt[n-1]+t.size()) {
                k -= t.size();
                n--;
            }
            else if (k >= cnt[n-1]+t.size() && k < cnt[n-1]+t.size()+u.size()) {
                k -= cnt[n-1] + t.size();
                printf("%c", u[k]);
                k = -1;
                break;
            }
            else if (k >= cnt[n-1]+t.size()+u.size() && k < 2LL*cnt[n-1]+t.size()+u.size()) {
                k -= cnt[n-1]+t.size()+u.size();
                n--;
            }
            else if (k >= 2LL*cnt[n-1]+t.size()+u.size()) {
                k -= 2LL * cnt[n-1] +t.size() + u.size();
                printf("%c", v[k]);
                k = -1;
                break;
            }
        }
        if (k >= 0 && k < t.size() && n >= 1) {
            printf("%c", t[k]);
            continue;
        }
        if (n == 0) {
            if (k < s.size() && k >= 0) printf("%c", s[k]);
            else if (k > s.size())printf(".");
        }
    }
    cout << endl;
    return 0;
}