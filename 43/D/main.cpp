#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int node, start, endd, mid;
bool map[110][110];

int visited[110];
int step[110];
int bfs()
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 110; i++)
        step[i] = INT_MAX;

    queue<int> q[2];

    int q_idx = 0;
    q[q_idx].push(start);
    step[start] = 0;

    bool target_reached = false;
    while (q[q_idx].empty() == false) {
        int curr = q[q_idx].front();
        q[q_idx].pop();

        visited[curr] = 1;

        int next_q_idx = q_idx == 1 ? 0 : 1;
        for (int i = 1; i <= node; i++) {
            if (visited[i] == 0 && map[curr][i] == true &&
                step[curr] + 1 <= step[i]) {
                if (i == endd) {
                    target_reached = true;
                }
                q[next_q_idx].push(i);
                step[i] = step[curr] + 1;
            }
        }

        if (q[q_idx].empty() == true) {
            q_idx = next_q_idx;
            if (target_reached) {
                int cnt = 0;
                while (q[q_idx].empty() == false) {
                    if (q[q_idx].front() == endd) {
                        cnt++;
                    }
                    q[q_idx].pop();
                }

                return cnt;
            }
        }
    }

    return 0;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d,%d,%d,%d", &node, &start, &endd, &mid);

        for (int i = 1; i <= node; i++) {
            for (int j = 1; j <= node; j++) {
                int tmp;
                scanf("%d", &tmp);

                map[i][j] = tmp == 1 ? true : false;
            }
        }

        int total = bfs();

        int orig_endd = endd;
        endd = mid;
        int pass_mid = bfs();

        start = mid;
        endd = orig_endd;
        pass_mid *= bfs();

        printf("%d %d\n", total, pass_mid);
    }

    return 0;
}
