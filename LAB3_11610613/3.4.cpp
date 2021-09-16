#include<stdio.h>

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int n, k;
		int s = 0;
		scanf("%d %d", &n, &k);
		for (int i = 2; i <= n; i++) {
			s = (s + k + 1) % i;
		}
		printf("%d\n", s);
	}
}