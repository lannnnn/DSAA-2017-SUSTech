#include<stdio.h>

long long a[1000];
int b[1000];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int N, K, X;
		scanf("%d %d %d", &N, &K, &X);
		for (int j = 0; j < N; j++) {
			scanf("%lld ", &a[j]);
		}
		int num1, num2;
		num1 = K / N;
		for (int k = 0; k < N; k++) {
			b[k] = num1;
		}
		num2 = K % N;
		for (int k = 0; k < num2; k++) {
			if (X == N || X + k == N) {
				X -= N;
			}
			b[X + k] += 1;
		}
		for (int k = 0; k < N; k++) {
			int ans = 1;
			long long c = 123456789;
			a[k] = a[k] % c;
			while (b[k]>0)
			{
				if (b[k] % 2 == 1) {
					ans = (ans * a[k]) % c;
				}				
				b[k] = b[k] / 2;
				a[k] = (a[k] * a[k]) % c;
			}
			printf("%d ", ans);
		}
		printf("\n");
	}
}