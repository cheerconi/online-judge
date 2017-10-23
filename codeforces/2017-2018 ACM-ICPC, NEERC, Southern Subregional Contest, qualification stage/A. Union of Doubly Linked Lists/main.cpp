#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 110;
int neg[MAXN][2];


int main() {
    int n;
    cin >> n;
    stack<int> ed;
    for (int i = 1; i <= n; i++) {
        cin >> neg[i][0] >> neg[i][1];
        if (neg[i][1] == 0) ed.push(i);
    }
    int ban = 1;
    while (neg[ban][1] != 0) ban = neg[ban][1];
    int start = 1;
    while (!ed.empty()) {
        int num = ed.top();
        ed.pop();
        if (num == ban) continue;
        while (neg[start][0] != 0) start = neg[start][0];
        neg[start][0] = num;
        neg[num][1] = start;
    }

    for (int i = 1; i <= n; i++) {
        cout << neg[i][0] << ' ' << neg[i][1] << endl;
    }

    return 0;
}