#include<stdio.h>

struct Node {
    int lch;
    int rch;
    int notRoot;
};

int len = 0;

int FindMax(struct Node* tree,int i)
{
    int llen = 0,rlen = 0;
	if(tree[i].lch) llen = FindMax(tree,tree[i].lch);
    if(tree[i].rch) rlen = FindMax(tree,tree[i].rch);
    len = len > (llen+rlen) ? len : (llen+rlen);
    return llen>rlen?llen+1:rlen+1;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		struct Node tree[10001] = {0,0,1};
		int n,root;
		scanf("%d",&n);
		if(n == 1) {
			printf("0\n");
			continue;
		}
		while(--n) {
			int fat,son;
			scanf("%d %d",&fat,&son);
			if(tree[fat].lch) tree[fat].rch = son;
			else tree[fat].lch = son;
			tree[son].notRoot = 1;
		}
		for(int i = 0;i<1025;i++) {
			if(!tree[i].notRoot && tree[i].lch) {
				root = i;
				break;
			}
		}
		FindMax(tree,root);
		printf("%d\n",len);
		len = 0;
	}
}
