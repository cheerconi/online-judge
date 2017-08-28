#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long LL;
const int MAXN = 20000 + 10;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    LL sum = 0;
    LL cnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        pq.push(tmp);
        sum += tmp;
    }
    while (pq.size() >= 2) {
        tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        cnt += tmp;
    }
    cout << cnt << endl;

}