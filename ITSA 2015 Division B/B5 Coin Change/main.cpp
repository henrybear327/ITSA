#include <cstdio>

const int c[5] = {1, 5, 10, 20, 50};

int main()
{
    int cases;
    while (scanf("%d", &cases) == 1) {
        while (cases--) {
            long long int target;
            scanf("%lld", &target);

            long long int cnt[15010] = {0};
            cnt[0] = 1; // If target = 0

            for (int i = 0; i < 5; i++) {
                for (long long int j = c[i]; j <= target; j++) {
                    cnt[j] += cnt[j - c[i]];
                }
            }

            printf("%lld\n", cnt[target]);
        }
    }

    return 0;
}
