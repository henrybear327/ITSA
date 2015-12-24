#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int cnt;
} Data;

int cmp(const void *a, const void *b)
{
    return (int *)a - (int *)b;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int f[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);

        int g[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &g[i]);

        qsort(f, n, sizeof(f), cmp);
        qsort(g, n, sizeof(g), cmp);

	Data ff[n], gg[n];
        memset(ff, 0, sizeof(ff));
        memset(gg, 0, sizeof(gg));

        int idxf = 0, idxg =0;
        for (int i = 0; i < n - 1; i++) {
            ff[idxf].num = f[i];
            ff[idxf].cnt++;
            if (f[i] != f[i + 1]) {
                idxf++;
            }

            gg[idxg].num = g[i];
            gg[idxg].cnt++;
            if (g[i] != g[i + 1]) {
                idxg++;
            }
        }
	
	for(int i = 1; i < idxg; i++)
	    gg[i].cnt += gg[i - 1].cnt;

	int currg = 0, ans = 0;
	for(int i = 0; i < idxf && currg < idxg; i++) {
	    if(ff[i].num > gg[currg].num) {
		ans += gg[currg].
	    }
	}
    }

    return 0;
}
