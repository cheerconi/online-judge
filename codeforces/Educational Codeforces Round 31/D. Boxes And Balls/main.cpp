#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> > pq;
int n;
LL solve () {
    LL sum = 0;
    if (n % 2 == 0) pq.push(0);
    LL a, b, c;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = pq.top();
        pq.pop();
        sum += a + b + c;
        pq.push(a+b+c);
    }
    return sum;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        pq.push((LL)val);
    }
    cout << solve() << endl;
    return 0;
}