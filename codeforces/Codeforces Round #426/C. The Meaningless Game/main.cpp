#include <iostream>
using namespace std;
typedef long long LL;

bool check(LL a, LL b) {
    if (a*a == b || b*b == a) return true;
    LL c = a*b;
    LL left = 1;
    LL right = 1000000;
    while (left < right) {
        LL mid = (left+right) >> 1;
        LL tmp = mid*mid*mid;
        if (tmp == c) {
            left = mid;
            break;
        }
        if (tmp > c) right = mid;
        else left = mid+1;
    }
    if (left*left*left != c) return false;
    if (a%left==0 && b%left==0) return true;
    return false;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (check(a, b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}