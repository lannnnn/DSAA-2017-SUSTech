#include<stdio.h>
#include<queue>
#include<vector>
#include<cstring>
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
int path[201][201];
int know[201];
vector<int> nexts[201];
queue<int> way;
int main() {
	int T;
	//scanf("%d",&T);
	T = fastInput::nextInt();
	while(T--) {
		int k, n, q, t, x, y, tar, tmp1, tmp2;
		memset(path,0,sizeof(path));
		for(int i = 1; i <= 200; i++){
			nexts[i].clear();
		}
		//scanf("%d %d %d", &k, &n, &q);
		k = fastInput::nextInt();
		n = fastInput::nextInt();
		q = fastInput::nextInt();
		while(n--) {
			//scanf("%d %d", &t, &y);
			t = fastInput::nextInt();
			y = fastInput::nextInt();
			while(--t) {
				x = y;
				//scanf(" %d", &y);
				y = fastInput::nextInt();
				nexts[x].push_back(y);
				path[x][y] = 1;
			}
		}
		for(int i = 1; i <= k; i++) {
			memset(know,0,sizeof(know));
			way.push(i);
			while(!way.empty()) {
				tmp1 = way.front();
				way.pop();
				for(int k = 0; k < nexts[tmp1].size(); k++) {
					tmp2 = nexts[tmp1].at(k);
					if(!know[tmp2]) {
						way.push(tmp2);
						path[i][tmp2] = path[i][tmp1] + path[tmp1][tmp2];
						know[tmp2] = 1;
					}
				}
			}
		}
		while(q--) {
			//scanf(" %d",&tar);
			tar = fastInput::nextInt();
			if(!path[tar][tar]) printf("-1\n");
			else printf("%d\n",path[tar][tar]);
		}
	}
}