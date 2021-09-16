#include<stdio.h>

void find_num(int num, int low, int high,int a);

int array[5000];
int upper, lower;
bool found;

int main() {
	int cases;
	scanf("%d\n", &cases);
	for (int i = 0; i < cases; i++) {
		found = false;
		int count1, num;
		scanf("%d %d",&count1, &num);
		for (int j = 0; j < count1; j++) {		//获取数组
			scanf("%d", &array[j]);
		}
		for (int a = 0; a < count1 - 1; a++) {
			upper = count1 - 1;
			lower = a + 1;
			find_num( num, lower,upper,a);
		}
		if (found == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}

void find_num(int num,int lower,int high ,int a) {
	if (lower == high) {
		return;
	}
	if (array[a] + array[lower] + array[high] == num) {
		found = true;
		return;
	}
	else if (array[a] + array[lower] + array[high] < num) {
		lower = lower + 1;
		find_num( num, lower, high, a);
	}
	else {
		high = high - 1;
		find_num( num, lower, high, a);
	}
}
