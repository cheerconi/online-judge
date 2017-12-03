#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 4000 + 10;
int nums[4][MAXN];
int data[MAXN*MAXN];

inline int read() {
    register int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    n = read();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            nums[j][i] = read();
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            data[idx++] = nums[0][i] + nums[1][j];
        }
    }
    sort(data, data+idx);
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = -nums[2][i]-nums[3][j];
            ret += upper_bound(data, data+idx, val) - lower_bound(data, data+idx, val);
        }
    }
    cout << ret << endl;
    return 0;
}