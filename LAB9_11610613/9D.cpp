#include<stdio.h>
#include<cstdlib>
#define MAX 10001  
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
struct Node{
	int ini;
	int dis;
	int cost;
}node[MAX];
int point[MAX],rank[MAX];

void Init(int n) {
	for (int i = 1; i <= n; i++) {
		rank[i] = 0;
		point[i] = i;
	}
}

int cmp(const void*a, const void *b) {
	return ((struct Node*)a)->cost - ((struct Node*)b)->cost;
}

int find(int x){  
    if(point[x] == x) return x;
    return point[x] = find(point[x]); 
} 

void unite(int x, int y){  
    x = find(x);  
    y = find(y);  
    if(rank[x] < rank[y]){  
        point[x] = y;  
    }  
    else{  
        point[y] = x;  
        if(rank[x] == rank[y]) rank[x]++;  
    }  
}  

int kruskal(int n, int m)
{
	int nEdge = 0, res = 0;   
    qsort(&node[1], n, sizeof(node[0]), cmp);  
    for(int i = 1; i <= n && nEdge != m - 1; i++){  
        if(find(node[i].ini) != find(node[i].dis)){  
            unite(node[i].ini, node[i].dis);  
            res += node[i].cost;  
            nEdge++;  
        }  
    }  
    if(nEdge < m-1) res = -1;  
    return res;
}
int main() {
	int T;
	T = fastInput::nextInt();
	while (T--) {
		int n, m, K, tol, cost;
		n = fastInput::nextInt();
		m = fastInput::nextInt();
		K = fastInput::nextInt();
		//scanf("%d %d %d", &n, &m, &K);
		tol = m + K;
		Init(n);
		for(int i=1;i<=tol;i++) {
			//scanf("%d %d %d", &node[i].ini, &node[i].dis, &node[i].cost);
			node[i].ini = fastInput::nextInt();
			node[i].dis = fastInput::nextInt();
			node[i].cost = fastInput::nextInt();
		}
		cost = kruskal(tol, n);
		printf("%d\n", cost);
	}
}



