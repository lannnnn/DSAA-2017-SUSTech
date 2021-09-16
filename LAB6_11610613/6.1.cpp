#include<stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int nodes,m=0;
		scanf("%d ",&nodes);
		while(nodes>0) {
			nodes = nodes >> 1;
			m++;
		}
		printf("%d\n",m-1);
	}
}

