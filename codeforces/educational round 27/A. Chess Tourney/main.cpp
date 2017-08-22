#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;
int rating[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n; i++) scanf("%d", &rating[i]);
    sort(rating, rating+2*n);
    int i = n - 1;
    int j = n;
    if (rating[i] < rating[j]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}