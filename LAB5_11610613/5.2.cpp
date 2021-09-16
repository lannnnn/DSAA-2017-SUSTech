#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T) {
		string str;
		cin>> str;
		int n;
		scanf("%d", &n);
		while (n) {
			char opt[7];
			scanf("%s", opt);
			if (opt[0] == 'D') {
				int pos;
				scanf("%d", &pos);
				str.erase(pos, 1);
				printf("%s\n",str.c_str());
			}
			else if (opt[0] == 'A') {
				string x;
				int pos;
				cin >> x;
				scanf("%d", &pos);
				str.insert(pos, x);
				printf("%s\n", str.c_str());
			}
			else if (opt[0] == 'S') {
				int pos1, pos2;
				scanf("%d %d", &pos1, &pos2);
				printf("%s\n", str.substr(pos1, pos2-pos1+1).c_str());
			}
			else {
				int pos1, pos2;
				scanf("%d %d", &pos1, &pos2);
				char temp;
				while (pos1 < pos2) {
					temp = str[pos1];
					str[pos1] = str[pos2];
					str[pos2] = temp;
					pos1++;
					pos2--;
				}
				printf("%s\n", str.c_str());
			}
			n--;
		}
		T--;
	}
}
