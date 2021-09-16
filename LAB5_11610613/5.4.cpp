#define N 1000001
#include<cstdio>
#include<cstring>

using namespace std;
int next[N]= {0},pnext[N];
char str[N],sstr[N],fin[N];

void getNext(char b[],int len)  
{   
    int j=0;            
    next[0]=next[1]=0;  
    for(int i=1;i<len;i++) {
        while(j>0&&b[i]!=b[j]) {
			j=next[j];  
		}
        if(b[i]==b[j]) {
			j++;  
		}
        next[i+1]=j;  
    }            
}  

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int sl,ssl;
		scanf("%d",&sl);
		scanf("%s",str);
		scanf("%d",&ssl);
		scanf("%s",sstr);
		getNext(sstr,ssl);
		int j = 0,pos = 0;
		for (int i = 0; i < sl; i++) {
			fin[pos] = str[i];  
        	while (j > 0 && str[i] != sstr[j])  
            	j = next[j];  
        	if (str[i] == sstr[j])  
            	j++;  
            pnext[pos] = j;
        	if (j == ssl) {  
            	pos -= ssl;
            	j = pnext[pos];
        	} 
			pos++; 
   	 	} 
		for (int i = 0; i < pos; i++) {
			printf("%c",fin[i]);
		} 
		printf("\n");
	}
}
