#include<stdio.h> 
#include<math.h>
int main() {
	int T;
	scanf("%d",&T);
	while(T) {
		char str[1000];
		scanf("%s",str);
		int len = strlen(str);
		int num = (len + 1) * len / 2;
		printf("%d",num);
		T--;
	}
}
