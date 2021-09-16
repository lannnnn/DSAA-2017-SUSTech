#include<stdio.h>
#include<math.h>
#include<queue>
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
int station[100001],know[100001];
priority_queue<int> len;
queue<int> circle;
inline long long pow2(int x) {
  return x*x;
}
int main() {
	int T;
	//scanf("%d", &T);
	T = fastInput::nextInt();
	while(T--) {
		memset(know,0,sizeof(know));
		//while(!len.empty()) len.pop();
		int n, tmp1, tmp2;
		//scanf("%d", &n);
		n = fastInput::nextInt();
		for(int i = 1; i <= n ; i++) {
			//scanf(" %d", &station[i]);
			station[i] = fastInput::nextInt();
		}
		for(int i = 1; i <= n ; i++) {
			if(know[i]) continue;
			circle.push(i);
			know[i] = 1;
			while(!circle.empty()) {
				tmp1 = circle.front();
				circle.pop();
				tmp2 = station[tmp1];
				if(!know[tmp2]) {
					know[tmp2] = know[tmp1] + 1;
					circle.push(tmp2);
				}
			}
			len.push(know[tmp1] - know[tmp2] + 1);
		}
		long long ans = 0;
		if(len.size() >= 2) {
			int x, y;
			x = len.top(); len.pop();
			y = len.top(); len.pop();
			ans += pow2(x+y);
		}
		while(!len.empty()) {
			int x;
			x = len.top(); len.pop();
			ans += pow2(x);
		}
		printf("%lld\n",ans);
	}
}