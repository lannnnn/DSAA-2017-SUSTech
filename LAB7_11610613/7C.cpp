#include <cstdio>
#include <algorithm>
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
const int MAXN = 2e6 + 10;
int n, num[MAXN];
inline void heapify(int i) {
    int l, r, least;
    for (int j = i; j < n;) {
        l = j << 1;
        r = j << 1 | 1;
        if (l <= n && r <= n) {
            least = j;
            if (num[l] < num[least]) least = l;
            if (num[r] < num[least]) least = r;
            if (least != j)
                swap(num[least], num[j]), j = least;
            else
                return;
        }
        else {
            if (l <= n && num[l] < num[j]) swap(num[l], num[j]);
            if (r <= n && num[r] < num[j]) swap(num[r], num[j]);
            return;
        }
    }
}
inline void insert(int x) {
    ++n;
    num[n] = x;
    int p = n;
    while (p >> 1) {
        if (num[p] < num[p >> 1]) swap(num[p], num[p >> 1]);
        p >>= 1;
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T, q, k, x;
    T = fastInput::nextInt();
    while (T--) {
        n = fastInput::nextInt();
        for (int i = 1; i <= n; ++i) num[i] = fastInput::nextInt();
        for (int i = (n >> 1); i; --i) heapify(i);
        q = fastInput::nextInt();
        for (int i = 1; i <= q; ++i) {
            k = fastInput::nextInt();
            switch (k) {
                case 1: x = fastInput::nextInt(); insert(x); break;
                case 2: num[1] = num[n]; --n; heapify(1); break;
                case 3: printf("%d\n", num[1]); break;
            }
        }
    }
    return 0;
}
