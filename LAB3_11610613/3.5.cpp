#include<stdio.h>
#include<map>
using namespace std;

int main() {
	map<int, int> poly1,poly2,poly3;
	map<int, int>::iterator it,it2;
	int cases;
	scanf("%d", &cases);
	for (int j = 0; j < cases; j++) {
		int len1, len2;
		scanf("%d", &len1);
		int coe, pow;
		for (int i = 0; i < len1; i++) {
			scanf("%d %d", &coe, &pow);
			if (coe != 0) {
				poly1[pow] += coe;
			}
		}
		scanf("%d", &len2);
		for (int i = 0; i < len2; i++) {
			scanf("%d %d", &coe, &pow);
			if (coe != 0) {
				poly2[pow] += coe;
			}
		}
		it = poly1.begin();
		it2 = poly2.begin();
		while (it != poly1.end()) {
			while (it2 != poly2.end()) {
				poly3[(*it).first + (*it2).first] += (*it).second * (*it2).second;
				it2++;
			}
			it2 = poly2.begin();
			it++;
		}
		bool isFirst = true;
		it = poly3.begin();
		while (it != poly3.end()) {
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
		poly1.clear();
		poly2.clear();
		poly3.clear();
		system("pause");
	}
}