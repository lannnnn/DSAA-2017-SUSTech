#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int n, k;
priority_queue<long long, vector<long long>, greater<long long> >       PriQ;
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    long long x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        while (!PriQ.empty()) PriQ.pop();
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            PriQ.push(x);
        }
        long long ans = 0;
        while (PriQ.size() > 1) {
            long long t = 0;
            for (int i = 0; i < k; ++i) {
                t += PriQ.top();
                PriQ.pop();
            }
            ans += t;
            PriQ.push(t);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
