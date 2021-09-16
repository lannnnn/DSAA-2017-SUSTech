#include<stdio.h>

int main() {
	int cases,i,j,YoN=1;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		int n, top=-1, YoN=1;
		char ch[30001];
		char left[15000];
		scanf("%d", &n); 
		scanf("%s", &ch);
		if(n%2 == 1) {
			printf("NO\n");
			continue;
		}
		for (j = 0; j < n; j++) {			
			switch(ch[j]) {
				case '(':case '{':case '[':
					left[++top] = ch[j];
					break;
				case ')':   
					if(left[top] == '(') {
						top--;
					}else {
						YoN=0;
						j = n;
					}
					break;
				case '}':   
					if(left[top] == '{') {
						top--;
					}else {
						YoN=0;
						j = n;
					}
					break;
				case ']':   
					if(left[top] == '[') {
						top--;
					}else {
						YoN=0;
						j = n;
					}
					break;
				default:break;
			}			
		}
		if(YoN == 1 && top == -1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}	
	}
}
