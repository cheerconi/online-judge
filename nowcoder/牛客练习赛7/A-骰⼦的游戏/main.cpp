#include <iostream>
using namespace std;
int a[6], b[6];
int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
        for (int i = 0; i < 6; i++) scanf("%d", &b[i]);
        int alice = 0, bob = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (a[i] > b[j]) alice++;
                else if (a[i] < b[j]) bob++;
            }
        }
        if (alice == bob) printf("Tie\n");
        else if (alice > bob) printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}