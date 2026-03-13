#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long k;
        scanf("%lld", &k);
        if (k % 3 == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
