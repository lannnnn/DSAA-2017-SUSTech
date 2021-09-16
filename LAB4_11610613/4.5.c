#include<stdio.h>
struct {
	int pre;
	int num;
	int b_n;
}bn[500000];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int n,num, top=0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &num);
			if (top == 0) {
				top = 1;
				bn[top].b_n = 0;
				bn[top].num = num;
				bn[top].pre = 0;
				continue;
			}
			while (num > bn[top].num && top > 0) {
				bn[top].b_n = j;
				top = bn[top].pre;
			}
			bn[j].pre = top;
			bn[j].num = num;
			bn[j].b_n = 0;
			top = j;
		}
		for (int k = 1; k <= n; k++) {
			printf("%d\n", bn[k].b_n);
		}
	}
}
