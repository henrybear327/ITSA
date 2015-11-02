/*
From 
https://github.com/Sharknevercries/Online-Judge/blob/master/ACM-ICPC%20Live%20Archive/6692%20Lucky%20Number.cpp
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAX_N 1000005

pair<int, int> S[MAX_N];

bool cmp(pair<int, int> A, pair<int, int> B)
{
    return A.first < B.first || (A.first == B.first && A.second < B.second);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            S[i] = make_pair(tmp, i);
        }
        sort(S, S + n, cmp);
        int L = INF, ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            for (; j < n && S[i].first == S[j].first; j++)
                ;
            ans = max(ans, S[j - 1].second - L);
            L = min(S[i].second, L);
            printf("%d %d\n", ans, L);
        }
        printf("%d\n", ans);
    }
    return 0;
}
