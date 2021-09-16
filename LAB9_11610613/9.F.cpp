#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
//#include<algorithm>
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
int cou[5001], n, m, x, y;
vector<int> p[5001];
int way[5001], course[5001], currentsize;
inline bool empty() {
    return currentsize == 0;
}
 
inline void clear() {
    currentsize = 0;
}
 
inline void insert(int x){
    course[++currentsize] = x;
    int tmp = currentsize;
    while(tmp>1 && course[tmp]>course[tmp/2]){
        int temp = course[tmp];
        course[tmp] = course[tmp/2];
        course[tmp/2] = temp;
        tmp /= 2;
    }
}
 
 
inline int pop(){
    int val = course[1];
    int tmp = course[1];
    course[1] = course[currentsize];
    course[currentsize--] = tmp;
    int j = 1;
    int x;
    while(j*2<currentsize+1){
        x = 2*j;
        if(x<currentsize && course[x]<course[x+1]) x++;
        if(course[x]>course[j]){
            int t = course[x];
            course[x] = course[j];
            course[j] = t;
            j = x;
        }else{
            break;
        }
    }
    return val;
}

void findPath() {
    int nexts, cnt = n;
    for(int i = 1;i <= n; i++) {
        if(!cou[i]) {
            insert(i);
        }
    }
    while(!empty()) {
        nexts = pop();
        way[cnt--] = nexts;
        for (int i = 0; i < p[nexts].size(); ++i) {
            if(--cou[p[nexts][i]] == 0)
                insert(p[nexts][i]);
        }
    }
    if (cnt) printf("impossible");
    else {
        for (int i = 1; i <= n; ++ i)
            printf("%d ", way[i]);
    } 
    printf("\n");
}
 
int main() {
    int T;
    T = fastInput::nextInt();
    // scanf("%d",&T);
    while(T--) {
    	clear();
        // scanf("%d %d", &n, &m);
        for(int i =1; i<=n; i++) p[i].clear();
        n = fastInput::nextInt();
        m = fastInput::nextInt();
        memset(cou, 0, sizeof(cou));
        while(m--) {
            // scanf("%d %d", &x, &y);
            x = fastInput::nextInt();
            y = fastInput::nextInt();
            p[y].push_back(x);
            cou[x]++;
        }
        findPath();
    }
}