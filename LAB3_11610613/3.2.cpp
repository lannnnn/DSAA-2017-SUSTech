#include<stdio.h>
#include<map>
using namespace std;

int main() {
	map<int, int> poly;
	map<int, int>::iterator it;
	int cases;
	scanf("%d", &cases);
	for (int j = 0; j < cases; j++) {
		int len1,len2;
		scanf("%d", &len1);
		int coe, pow, max=0;
		for (int i = 0; i < len1; i++) {
			scanf("%d %d", &coe, &pow);
			poly[pow] += coe;
			if (max < pow) {
				max = pow;
			}
		}
		scanf("%d", &len2);
		for (int i = 0; i < len2; i++) {
			scanf("%d %d", &coe, &pow);
			poly[pow] += coe;
			if (max < pow) {
				max = pow;
			}
		}
		while (poly[max] == 0 && max > 0) {
			max--;
		}
		bool isFirst = true;
		it = poly.begin();
		while (it != poly.end()) {
			if (max == 0) {
				printf("%d",(*it).second);
				break;
			}
			if ((*it).first == 0 && (*it).second != 0) {
				printf("%d", (*it).second);
				isFirst = false;
				it++;
				continue;
			}
			if ((*it).second == 0) {
				it++;
				continue;
			}
			if ((*it).second > 0 && !isFirst) {
				printf("+");
			}
			if ((*it).second != 1 && (*it).second != -1) {
				printf("%d", (*it).second);
			}
			if ((*it).second == -1) {
				if ((*it).first != 0) {
					printf("-");
				}
				else {
					printf("-1");
				}
			}
			if ((*it).first != 0 && (*it).first != 1) {
				printf("x^%d", (*it).first);
			}
			if ((*it).first == 1) {
				printf("x");
			}
			isFirst = false;
			it++;
		}
		printf("\n");
		poly.clear();
		system("pause");
	}
}