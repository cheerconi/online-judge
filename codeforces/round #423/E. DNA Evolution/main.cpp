#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 100000 + 10;
int tree[4][11][11][MAXN];
int n;
inline int lowbit(int pos) {
    return pos & (-pos);
}

void update(int kind, int period, int phase, int pos, int val) {
    while (pos <= n) {
        tree[kind][period][phase][pos] += val;
        pos += lowbit(pos);
    }
}
int sum(int kind, int period, int phase, int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += tree[kind][period][phase][pos];
        pos -= lowbit(pos);
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    map<char, int> symbol;
    symbol['A'] = 0;
    symbol['T'] = 1;
    symbol['G'] = 2;
    symbol['C'] = 3;
    string s;
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        for (int period = 1; period <= 10; period++) {
            int kind = symbol[s[i]];
            update(kind, period, i % period, i, 1);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int flag;
        scanf("%d", &flag);
        if (flag == 2) {
            int left, right, period, cnt = 0;
            string t;
            scanf("%d%d", &left, &right);
            cin >> t;
            period = t.size();
            t = ' ' + t;
            for (int j = 1; j <= period; j++) {
                int kind = symbol[t[j]];
                cnt += sum(kind, period, (left+j-1)%period, right) - sum(kind, period, (left+j-1)%period, left-1);
            }
            printf("%d\n", cnt);
        }
        else { // flag == 1
            int pos, kind, prekind;
            char c;
            scanf("%d", &pos);
            getchar();
            scanf("%c", &c);
            kind = symbol[c];
            prekind = symbol[s[pos]];
            s[pos] = c;
            for (int period = 1; period <= 10; period++) {
                update(prekind, period, pos%period, pos, -1);
                update(kind, period, pos%period, pos, 1);
            }

        }
    }



    return 0;
}