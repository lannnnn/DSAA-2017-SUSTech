#include<stdio.h>
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

struct poi{
	int tar1;
	int tar2;
}point;
int j[1001][1001], k[1001][1001], cnt, tmp;
queue<struct poi> que;

void findBlock(int n, int m, int tar1,int tar2) {
	que.pop();
	//if (k[tar1][tar2] == 1) return;
	//que.push(tar);
	if ((tar2 - 1) >= 0 && j[tar1][tar2 - 1] == tmp && k[tar1][tar2 - 1] != 1) {
		point.tar1 = tar1;
		point.tar2 = tar2 - 1;
		k[tar1][tar2-1] = 1;
		que.push(point);
	}
	if ((tar1 - 1) >= 0 && j[tar1 - 1][tar2] == tmp && k[tar1 - 1][tar2] != 1) {
		point.tar1 = tar1 - 1;
		point.tar2 = tar2;
		k[tar1-1][tar2] = 1;
		que.push(point);
	}
	if ( (tar2 + 1) < m && j[tar1][tar2+1] == tmp && k[tar1][tar2+1] != 1) {
		point.tar1 = tar1;
		point.tar2 = tar2 + 1;
		k[tar1][tar2+1] = 1;
		que.push(point);
	}
	if ((tar1 + 1) < n && j[tar1+1][tar2] == tmp && k[tar1 + 1][tar2] != 1) {
		point.tar1 = tar1 + 1;
		point.tar2 = tar2;
		k[tar1+1][tar2] = 1;
		que.push(point);
	}
	while (!que.empty())	findBlock(n, m, que.front().tar1 ,que.front().tar2 );
	return;
}

int main() {
	int T;
	T = fastInput::nextInt();
	while (T--) {
		int n, m, C, tol, i = 1;
		n = fastInput::nextInt();
		m = fastInput::nextInt();
		C = fastInput::nextInt();
		tol = n*m;
		cnt = 0;
		memset(k, 0, sizeof(k));
		for (int p = 0; p < tol; p++) {
			j[p / m][p%m] = fastInput::nextInt();;
		}
		for (int i = 0; i<n; i++) {
			for (int p = 0; p < m; p++) {
				if (k[i][p] == 1) continue;
				point.tar1 = i;
				point.tar2 = p;
				que.push(point);
				tmp = j[i][p];
				findBlock(n, m, i, p);
				cnt++;
			}	
		}
		printf("%d\n", cnt);
	}
}
