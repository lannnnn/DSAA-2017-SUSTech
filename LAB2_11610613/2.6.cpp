#include<stdio.h>
#include <algorithm>

int seat[100000];

int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int seat_counter(int len,int seats) {
	int now = 0, count = 0;
	for (int k = 1; k < seats; k++) {
		if (seat[k] - seat[now] >= len) {
			now=k;
		}
		else {
			count++;
		}
	}
	return seats - count;
}

int main() {
	int cases;
	scanf("%d\n", &cases);
	for(int j=0;j<cases;j++) {
		int seats, students;
		scanf("%d %d\n", &seats, &students);
		for (int i = 0; i < seats; i++) {		//获取座位数组
			scanf("%d ", &seat[i]);
		}
		qsort(seat,seats,sizeof(int),compare);
		int max_len, min_len,len,mid;
		min_len = 1;
		max_len = seat[seats - 1] - seat[0];
		while (min_len <= max_len) {
			mid = (min_len + max_len) / 2;
			if (seat_counter(mid, seats) < students) {
				max_len = mid - 1;;
			}
			else {
				min_len = mid + 1;
				len = mid;
			}
		}
		printf("%d\n", len);
	}
}