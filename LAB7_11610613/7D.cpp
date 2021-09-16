#include<stdio.h>
#include<vector> 

using namespace std;
vector<long long> path;

void printPath() {
	vector<long long>::iterator p;
	p=path.end();
	p--;
	for(;p!=path.begin()-1;p--) {
		printf("%lld ",*p);
	}
	path.clear();
}
  
void findPath(long long n,long long k) {
    while(n != 1) {
    	path.push_back(n);
    	n=(long long)(n+k-2)/(long long)k;
	}
	path.push_back(1);
	printPath();
}
  
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        long long n,k;
        scanf("%lld %lld",&n,&k);
        findPath(n,k);
        printf("\n");
    }
}
