#include<stdio.h>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define INF (0x7f7f7f7f)
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

struct Node {
	int next;
	int cost;
	Node (int _n, int _c) {
		next = _n;
		cost = _c;
	}
};

std::vector<Node> city[6001];


int dis1[6001], dis2[6001];
bool vis[6001];

struct Cost1 {
	bool operator() (int a, int b){
        return dis1[a] > dis1[b];
    }  
};

struct Cost2 {
	bool operator() (int a, int b){
        return dis2[a] > dis2[b];
    }  
};

priority_queue<int,vector<int>,Cost1> qs;
priority_queue<int,vector<int>,Cost2> qt;

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n, m, u, v, w;
		//scanf("%d %d", &n, &m);
		T = fastInput::nextInt();
		for (int i = 1; i <= n; ++ i)
			city[i].clear();
		while(m--) {
			//scanf("%d %d %d", &u, &v, &w);
			u = fastInput::nextInt();
			v = fastInput::nextInt();
			w = fastInput::nextInt();
			city[u].push_back(Node(v, w));
			city[v].push_back(Node(u, w));
		}
		int s, t, tmp1, tmp2;
		//scanf("%d %d", &s, &t);
		s = fastInput::nextInt();
		t = fastInput::nextInt();
		memset(dis1, 0x7f, sizeof(dis1));
		memset(vis, 0, sizeof(vis));
		dis1[s] = 0;
		qs.push(s);
		while (!qs.empty()) {
			tmp1 = qs.top();
			qs.pop();
			if (vis[tmp1]) 
				continue;
			else
				vis[tmp1] = 1;
			for (int i = 0; i < city[tmp1].size(); i++) {
				tmp2 = city[tmp1][i].next;
				if (dis1[tmp2] > dis1[tmp1] + city[tmp1][i].cost) {
					dis1[tmp2] = dis1[tmp1] + city[tmp1][i].cost;
					qs.push(tmp2);
				}
			}
		}
		memset(dis2, 0x7f, sizeof(dis2));
		memset(vis, 0, sizeof(vis));
		dis2[t] = 0;
		qt.push(t);
		while (!qt.empty()) {
			tmp1 = qt.top();
			qt.pop();
			if (vis[tmp1]) 
				continue;
			else
				vis[tmp1] = 1;
			for (int i = 0; i < city[tmp1].size(); i++) {
				tmp2 = city[tmp1][i].next;
				if (dis2[tmp2] > dis2[tmp1] + city[tmp1][i].cost) {
					dis2[tmp2] = dis2[tmp1] + city[tmp1][i].cost;
					qt.push(tmp2);
				}
			}
		}
		int ans = INF, sum;
		for (int i = 1; i <= n; ++ i) {
			sum = (dis1[i] < dis2[i]) ? dis2[i] : dis1[i];
			if (sum < ans)
				ans = sum;
		}
		printf("%d\n", ans);
	}
}