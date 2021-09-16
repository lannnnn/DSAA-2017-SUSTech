#include<stdio.h>
#include<malloc.h>

struct TreeNode;
typedef struct TreeNode *SearchTree;
SearchTree T1,T2;

struct TreeNode {
	int num;
	SearchTree lch;
	SearchTree rch;
};

SearchTree MakeEmpty( SearchTree T) {
	if(T != NULL) {
		MakeEmpty( T->lch );
		MakeEmpty( T->rch );
		T = NULL;
	}
	return T;
}

SearchTree Insert( int num, SearchTree T) {
	if(T == NULL) {
		T = (SearchTree)malloc( sizeof(struct TreeNode ));
		T->num = num;
		T->lch = T->rch = NULL;
	}else 
	if( num < T->num ) T->lch = Insert( num, T->lch);
	else 
	if( num > T->num ) T->rch = Insert( num, T->rch);
	return T;
}

int Compare( SearchTree T1, SearchTree T2)
{
  if (T1 == NULL && T2 == NULL)
    return 1;
  if((T1 != NULL && T2 == NULL) || (T1 == NULL && T2 != NULL))
    return 0;
  if(T1->num != T2->num)
    return 0;
  int left_compare = Compare(T1->lch, T2->lch);
  int right_compare = Compare(T1->rch, T2->rch);
  return (left_compare * right_compare);
}

int main() {
	int T,isSame;
	//SearchTree T1,T2;
	scanf("%d",&T);
	while(T--) {
		int n, m, tmp;
		scanf("%d %d", &n, &m);
		T1 = MakeEmpty(T1);
		for(int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			T1 = Insert(tmp,T1);
		}
		while(n--) {
			T2 = MakeEmpty(T2);
			for(int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			T2 = Insert(tmp,T2);
			}
			isSame = Compare(T1,T2);
			if(isSame) printf("YES\n");
			else printf("NO\n");
		}
	}
}
