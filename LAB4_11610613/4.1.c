#include<stdio.h>

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int stack[1000];
		int n, m, top=-1;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; j++) {
			int opt,num;
			scanf("%d", &opt);
			switch (opt) {
			case 1:
				scanf("%d", &num);
				if (top < n-1) {
					stack[++top] = num;
				}
				else {
					printf("%d\n", num);
				}
				break;
			case 2:
				if (top>=0) {
					printf("%d\n", stack[top--]);
				}
				break;
			}
		}
		while (top>=0) {
			printf("%d\n", stack[top--]);
		}
	}
}
