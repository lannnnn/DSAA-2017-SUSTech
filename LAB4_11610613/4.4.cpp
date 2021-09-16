#include<stdio.h>
#include<deque>
#include<algorithm>
using namespace std;
int main() {
	int cases, i, j;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		int n;
		scanf("%d", &n);
		deque<int> queue(0);
		deque<int>::iterator it;
		for (j = 0; j < n; j++) {
			int que, opt, num;
			scanf("%d %d", &que, &opt);
			switch (opt) {
			case 1:
				scanf("%d", &num);
				if (que == 1) {
					queue.push_front(num);
				}
				else {
					queue.push_back(num);
				}
				break;
			case 2:
				if (que == 1) {
					queue.pop_front();
				}
				else {
					queue.pop_back();
				}
				break;
			}
		}
		for (it = queue.begin(); it != queue.end(); it++) {
			printf("%d\n", *it);
		}
	}
}
