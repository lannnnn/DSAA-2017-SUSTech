#include<stdio.h>

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i<cases; i++) {
		bool found = false;
		int array_len, num;
		scanf("%d %d", &array_len, &num);
		int given_num;
		for (int j = 0; j<array_len; j++) {
			scanf("%d ", &given_num);
			if (given_num == num && found == false) {
				found = true;
				printf("YES\n");
			}
		}
		if (found == false) {
			printf("NO\n");
		}
	}
}