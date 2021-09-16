#include<stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m,x,y;
		int matrix[501][501] = {0};
		scanf("%d %d",&n,&m);
		while(m--) {
			scanf("%d %d",&x,&y);
			matrix[x-1][y-1] = 1;
		}
		for(int i=0;i < n;i++) {
			for(int j=0;j < n;j++) {
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}
	}
}
