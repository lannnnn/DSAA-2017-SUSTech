#include<stdio.h>
#include<malloc.h>
#include<memory.h>
const int MAXN = 1e5 + 10;
int lastVisit;

struct TreeNode {
	int nodeNum; 
	int notRoot;
	long long num;
	long long lch;
	long long rch;
};

struct TreeNode nodes[MAXN];
int notBT;

void Insert(long long fat, long long son) {
	nodes[son].notRoot = 1;
	if(nodes[fat].nodeNum < 2) {
		if(nodes[fat].lch) {
			if(nodes[son].num <= nodes[fat].num) {
				notBT = 1;
				return;
			}
			else { nodes[fat].rch = son; nodes[fat].nodeNum++;}
		}
		else if(nodes[fat].rch) {
			if(nodes[son].num >= nodes[fat].num) {
				notBT = 1;
				return;
			}
			else { nodes[fat].lch = son; nodes[fat].nodeNum++;}		
		}
		else if(nodes[son].num < nodes[fat].num) { nodes[fat].lch = son; nodes[fat].nodeNum++;}
		else { nodes[fat].rch = son; nodes[fat].nodeNum++;}
	}
	else notBT = 1;
}
int IsBinaryTree(long long root) 
{  
    if(root == 0 || nodes[root].num == 0){
        return 0;
    }
    int judgeLeft = IsBinaryTree(nodes[root].lch);
    if( (nodes[root].num >= lastVisit) && judgeLeft == 0){
        lastVisit = nodes[root].num;
    }else{
        return 1;
    }
    int judgeRight = IsBinaryTree(nodes[root].rch);
    return judgeRight;
} 


int main() {
	int T;
	//SearchTree T1,T2;
	scanf("%d",&T);
	int time = 0;
	while(T--) {
		memset(nodes,0,MAXN*sizeof(struct TreeNode));
		notBT = 0;
		lastVisit = 0;
		time++;
		long long n, m, fat, son, root;
		scanf("%lld", &n);
		//T1 = MakeEmpty(T1);
		for(long long i = 1; i <= n; i++) {
			scanf("%lld", &nodes[i].num);
		}
		for(long long j = 1; j < n; j++) {
			scanf("%lld %lld", &fat, &son);
			Insert(fat,son);
		}
		for(long long k = 1; k <= n; k++) {
			if(!nodes[k].notRoot) {	root = k; break;}
		}
		if(notBT) {printf("Case #%d: NO\n",time); continue;}
		notBT = IsBinaryTree(root);
		if(notBT) {printf("Case #%d: NO\n",time); continue;}
		else printf("Case #%d: YES\n",time);
	}
}
