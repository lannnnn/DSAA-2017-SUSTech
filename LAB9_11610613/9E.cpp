#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
namespace fastInput {
    inline char nc() {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? '@' : *p1++;
    }
    int over;
    inline int nextInt() {
        char ch = nc();
        int s = 0;
        while(!(ch >= '0' && ch <= '9')) {
            ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        while(ch >= '0' && ch <= '9') {
            s = s * 10 + ch - 48, ch = nc();
            if(ch == '@') { over = 1; break; }
        }
        return s;
    }
};
const int MAXN = 5050;
vector<int> edge[MAXN];
int n, m, flg[MAXN], know[MAXN];
bool flag;
inline void init() {
    flag = false;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    memset(flg, -1, sizeof flg);
    memset(know,0,sizeof know);
}
void dfs(int u, int tag) {
	know[u] = 1;
    if (flag) return;
    if (flg[u] != -1) {
        if (flg[u] != tag) flag = true;
        return;
    }
    flg[u] = tag;
    for (auto& v : edge[u]) {
        if (flag) break;
        dfs(v, !tag);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    T = fastInput::nextInt();
    while(T--) {
        init();
        //scanf("%d%d", &n, &m);
        n = fastInput::nextInt();
        m = fastInput::nextInt();
        for (int i = 0; i < m; ++i) {
            int x, y;
            //scanf("%d%d", &x, &y);
            x = fastInput::nextInt();
            y = fastInput::nextInt();
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for (int i = 1; i <= n && !know[i]; ++i) {
            if (flag) break;
            if (flg[i] == -1) dfs(i, 0);
        }
        if (flag)
            printf("illegal\n");
        else
            printf("legal\n");
    }
    return 0;
}
