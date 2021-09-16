#include<stdio.h>
#include<stdlib.h>

int a[100000], b[100000], c[200000];

int main() {	
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int n, m;
		scanf("%d %d", &n,&m);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[j]);
		}
		int x = 0, y = 0, z = 0;
		while (x < n || y < m) {
			if (x == n) {
				for (; y < m; y++) {
					c[z] = b[y];
					z++;
				}
				break;
			}
			if (y == m) {
				for (; x < n; x++) {
					c[z] = a[x];
					z++;
				}
				break;
			}
			if (a[x] <= b[y]) {
				c[z] = a[x];
				z++;
				x++;
			}
			else {
				c[z] = b[y];
				z++;
				y++;
			}
		}
		for (int k = 0; k < z; k++) {
			printf("%d ", c[k]);
		}
		printf("\n");
	}
	return 0;
}