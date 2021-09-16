#include<stdio.h>
#include<queue>

using namespace std;

struct node{
	int notRoot;
	int lch;
	int rch;
};

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		struct node tree[1025] = {0,0,0};
		int m,f,s,root;
		scanf("%d",&m);
		if(m == 1) printf("1");
		while(--m) {
			scanf("%d %d",&f,&s);
			if(!tree[f].lch) tree[f].lch = s;
			else tree[f].rch = s;
			tree[s].notRoot = 1;
		}
		queue<int> nodeQueue;
		for(int i = 0;i<1025;i++) {
			if(!tree[i].notRoot && tree[i].lch) {
				nodeQueue.push(i);
				break;
			}
		}
		while(!nodeQueue.empty()) {
			root = nodeQueue.front();
			nodeQueue.pop();
			printf("%d ",root);
			if(tree[root].lch) 	nodeQueue.push(tree[root].lch);
			if(tree[root].rch) 	nodeQueue.push(tree[root].rch);
		}
		printf("\n");
	}
}

