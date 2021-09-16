#include<stdio.h> 

int main() {
	_int64 sum,N;
	int count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%I64d", &N);
		sum = N*(N + 1)*(2 * N + 1) / 6;
		printf("%I64d\n", sum);
	}
}