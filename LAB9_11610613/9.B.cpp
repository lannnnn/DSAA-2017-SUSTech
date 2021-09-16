#include<stdio.h>
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
vector<int> vec[1001];
int poi[1001],isCon;

void findPath(int x,int y) {
	if(isCon == 1) return;
	int i=0;
	for(;i < vec[x].size();i++) {
		if(isCon == 1) return;
		if(poi[vec[x].at(i)] == 1) continue;
		poi[vec[x].at(i)] = 1;
		if(vec[x].at(i) == y) {isCon = 1;return;}
		findPath(vec[x].at(i),y);
	}	
	return;
}

int main() {
	int T;
	T = fastInput::nextInt();
	while(T--) {
		int n,m,sta,des,Q,x,y;
		n = fastInput::nextInt();
		m = fastInput::nextInt();
		while(m--) {
			sta = fastInput::nextInt();
			des = fastInput::nextInt();
			vec[sta].push_back(des);
		}
		Q = fastInput::nextInt();
		while(Q--) {
			memset(poi,0,(n+1)*sizeof(int));
			isCon = 0;
			x = fastInput::nextInt();
			y = fastInput::nextInt();
			findPath(x,y);
			if(isCon) printf("YES\n");
			else printf("NO\n");
		}
		for(int i=1;i<=n;i++) {
			vec[i].clear();
		}
	} 
}
