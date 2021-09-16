#include<stdio.h>

int main() {
	int cases,i,j;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		int stack[1001];
		int n, m, top=-1, bottom=-1, size=0;
		scanf("%d %d", &n, &m); 
		for (j = 0; j < m; j++) {
			int opt,num;
			scanf("%d", &opt);
			switch (opt) {
			case 1:
				scanf("%d", &num);
				if (size < n) {
					stack[(++top)%n] = num;
					size++;
				}
				else {
					printf("%d\n", num);
				}
				break;
			case 2:
				if (size>0) {
					printf("%d\n", stack[(++bottom)%n]);
					size--;
				}
				break;
			}
		}
		while (size>0) {
			printf("%d\n", stack[(++bottom)%n]);
			size--;
		}
	}
}
