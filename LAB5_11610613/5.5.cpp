#define N 1000001
#include<cstdio>
#include<cstring>

using namespace std;
int next[N];
char str[N];
long cnt[N];

void getNext(char sstr[],int len)  
{   
    int j=0;            
    next[0]=next[1]=0;  
    for(int i=1;i<len;i++) {
        while(j>0&&sstr[i]!=sstr[j]) {
			j=next[j];  
		}
        if(sstr[i]==sstr[j]) {
			j++;  
		}
        next[i+1]=j;  
    }            
}  
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int sl;
		long shash = 0;
		scanf("%d",&sl);
		scanf("%s",str);
		getNext(str,sl); 
    	for (int i=1; i<=sl; i++){
       		cnt[i] = 1L;
    	}     
    	cnt[0] = 0L;
    	for (int i=sl; i>0; i--) {
        	cnt[next[i]] += cnt[i];
        	shash+=(long)i*cnt[i];
    	}
		printf("%ld\n",shash);
	}
}
