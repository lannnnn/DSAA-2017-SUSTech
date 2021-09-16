#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 10;
class CNode {
public:
    int x, nxt;
};
bool isroot[MAXN];
int n, val[MAXN], h[MAXN], cnt;
CNode edge[MAXN];
inline void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].x = v;
    edge[cnt].nxt = h[u];
    h[u] = cnt;
}
long long dfs(int u) {
    long long tmax = 0, t;
    for (int p = h[u]; p; p = edge[p].nxt) {
        t = dfs(edge[p].x);
        if (t > tmax) tmax = t;
    }
    return tmax + val[u];
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
        memset(isroot, true, sizeof isroot);
        memset(h, 0, sizeof h);
        cnt = 0;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            isroot[v] = false;
            addEdge(u, v);
        }
        for (int i = 1; i <= n; ++i)
            if (isroot[i]) {
                printf("%lld\n", dfs(i));
                break;
            }
    }
    return 0;
}
