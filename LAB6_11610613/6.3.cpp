#include<stdio.h>

struct node{
	int notRoot;
	int lch;
	int rch;
};

void pre(int root,struct node* tree) {
	printf("%d ",root);
	if(tree[root].lch) pre(tree[root].lch,tree);				
	if(tree[root].rch) pre(tree[root].rch,tree);			
} 

void in(int root,struct node* tree) {
	if(tree[root].lch) in(tree[root].lch,tree);
	printf("%d ",root); 					
	if(tree[root].rch) in(tree[root].rch,tree);
}

void post(int root,struct node* tree) {
	if(tree[root].lch) post(tree[root].lch,tree);
	if(tree[root].rch) post(tree[root].rch,tree);
	printf("%d ",root);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		struct node tree[1025] = {0,0,0};
		int m,f,s,root;
		scanf("%d",&m);
		if(m == 1) {
			printf("1\n1\n1\n"); 
			continue;
		}
		while(--m) {
			scanf("%d %d",&f,&s);
			if(!tree[f].lch) tree[f].lch = s;
			else tree[f].rch = s;
			tree[s].notRoot = 1;
		}
		for(int i = 0;i<1025;i++) {
			if(!tree[i].notRoot && tree[i].lch) {
				root = i;
				break;
			}
		}
		pre(root,tree);
		printf("\n");
		in(root,tree);
		printf("\n");
		post(root,tree);
		printf("\n");
	}
}
