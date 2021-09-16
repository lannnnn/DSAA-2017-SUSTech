#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	long p;
	long d;
};
const int MAXN = 2e6 + 10;
int n;
struct node num[MAXN];
inline void heapify(long m) {
	long l, r, least;
	for (long j = m; j < n;) {
		l = j << 1;
		r = j << 1 | 1;
		if (l <= n && r <= n) {
			least = j;
			if (num[l].p < num[least].p) least = l;
			else if (num[l].p == num[least].p)
				if (num[l].d < num[least].d) least = l;
			if (num[r].p < num[least].p) least = r;
			else if (num[r].p == num[least].p)
				if (num[r].d < num[least].d) least = r;
			if (least != j)
				swap(num[least], num[j]), j = least;
			else
				return;
		}
		else {
			if (l <= n && (num[l].p < num[j].p || (num[l].p == num[j].p && num[l].d < num[j].d))) swap(num[l], num[j]);
			if (r <= n && (num[r].p < num[j].p || (num[r].p == num[j].p && num[r].d < num[j].d))) swap(num[r], num[j]);
			return;
		}
	}
}
inline void insert(long x, long y) {
	++n;
	num[n].p = x;
	num[n].d = y;
	long p = n;
	while (p >> 1) {
		if (num[p].p < num[p >> 1].p || (num[p].p == num[p >> 1].p && num[p].d < num[p >> 1].d))swap(num[p], num[p >> 1]);
		p >>= 1;
	}
}
int main() {
	long T, q;
	scanf("%d",&T);//fastInput::nextInt();
	while (T--) {
		scanf("%d", &n);//fastInput::nextInt();
		for (long i = 1; i <= n; ++i) {
			scanf("%ld", &num[i].p );
			scanf("%ld", &num[i].d);
		}
		for (long i = (n >> 1); i; --i) heapify(i);
		for (long i = 1; n != 0; ++i) {
			switch (i % 2) {
			case 1: insert(num[1].p + num[1].d, num[1].d);
				num[1] = num[n]; --n; 
				heapify(1); break;
			case 0: if (n == 1) { printf("%ld\n", num[1].p);n--;
				break;}
					num[1] = num[n]; 
					--n; heapify(1);
				break;
			}
		}
	}
	return 0;
}
