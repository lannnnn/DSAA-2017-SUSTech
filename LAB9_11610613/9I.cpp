#include<stdio.h>
#include<memory.h>
#include<queue>
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
int city[1200][1200], n, len[1200];
queue<int> way;

void find(int tar) {
	way.push(1);
	int pre;
	while(!way.empty()) {
		pre = way.front();
		way.pop();
		for(int i = 2; i <= n; i++ ) {
			if(!len[i] && city[pre][i] == tar) {
					way.push(i);
					len[i] = len[pre] + 1;
			}
		}
	}
}

int main() {
	int T;
	//scanf("%d", &T);
	T = fastInput::nextInt();
	while(T--) {
		int m, x, y;
		memset(city,0,sizeof(city));
		memset(len,0,sizeof(len));
		//scanf("%d %d", &n, &m);
		n = fastInput::nextInt();
		m = fastInput::nextInt();
		while(m--) {
			//scanf("%d %d", &x, &y);
			x = fastInput::nextInt();
			y = fastInput::nextInt();
			city[x][y] = 1;
			city[y][x] = 1;
		}
		if (city[1][n]) find(0);
		else find(1);
		if(len[n]) printf("%d\n", len[n]);
		else printf("-1\n");
	}
}