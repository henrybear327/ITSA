#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

long long int check(int n1, int w1, int n2, int w2, int n3, int w3)
{
    return (long long int)n1 * w1 + (long long int)n2 * w2 +
           (long long int)n3 * w3;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        sort(inp, inp + n);

        for (int i = 1; i < n; i++)
            inp[i] += inp[i - 1];

        int left = n / 3 - 1, right = 2 * (n / 3) - 1;
        long long int ans = LLONG_MAX;

        while (right < n) {
            while (left < right) {
                if (left >= (right - left) && (right - left) >= (n - right))
                    ans = min(ans, check(left, inp[left - 1], right - left,
                                         inp[right - 1] - inp[left - 1], n - right,
                                         inp[n - 1] - inp[right - 1]));

                // printf("%d\n", ans);
                left++;
            }
            right++;
            left = n / 3 - 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
