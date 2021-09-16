#include<stdio.h>

void find_num(int mid,int num, int low, int high,int a);

int array[5000];
int count , upper, lower;;

int main() {
	int cases;
	scanf("%d\n", &cases);
	for (int i = 0; i < cases; i++) {
		count = 0;
		int count1, num;
		scanf("%d %d",&count1, &num);
		for (int j = 0; j < count1; j++) {		//获取数组
			scanf("%d", &array[j]);
		}
		for (int a = 0; a < count1 - 1; a++) {
			upper = count1 - 1;
			lower = a + 1;
			int mid = (upper + lower) / 2;
			find_num(mid , num, lower,upper,a);
		}
		printf("%d\n", count);
	}
	system("pause");
}

void find_num(int mid,int num,int lower,int high ,int a) {
	if (lower > high) {
		return;
	}
	if (array[a] + array[mid] == num) {
		count++;
	}
	else if (array[a] + array[mid] < num) {
		lower = mid + 1;
		mid = (lower + high ) / 2;
		find_num(mid, num, lower, high, a);
	}
	else {
		high = mid - 1;
		mid = (lower + high) / 2;
		find_num(mid, num, lower, high, a);
	}
}
