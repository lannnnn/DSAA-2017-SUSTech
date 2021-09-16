#define N 1000001
#include<iostream>
#include<string>

using namespace std;
int next[N]= {0};

void getNext(string b,int len)  
{   
    int j=0;            
    next[0]=next[1]=0;  
    for(int i=1;i<len;i++) {
        while(j>0&&b.at(i)!=b.at(j)) {
			j=next[j];  
		}
        if(b.at(i)==b.at(j)) {
			j++;  
		}
        next[i+1]=j;  
    }            
}  

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int sl,ssl,time = 0;
		string str,sstr;
		scanf("%d",&sl);
		cin >> str;
		scanf("%d",&ssl);
		cin >> sstr;
		getNext(sstr,ssl);
		int j = 0;
		for (int i = 0; i < sl; i++) {  
        	while (j > 0 && str.at(i) != sstr.at(j))  
            	j = next[j];  
        	if (str.at(i) == sstr.at(j))  
            	j++;  
        	if (j == ssl) {  
            	time ++;  
            	j = next[j];  
        	}  
   	 	} 
		printf("%d\n",time); 
	}
}
