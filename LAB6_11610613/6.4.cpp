#include<stdio.h>
#include<malloc.h>

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int  elem;
};

struct TreeNode* BinaryTreeFromOrderings(int* in, int* post, int len)
{
	if (len == 0) return NULL;
	struct TreeNode* node =(struct TreeNode*) malloc(sizeof(struct TreeNode*));
	node->elem = *(post + len - 1);
	printf("%d ", node->elem);
	int rootIndex = 0;
	for (; rootIndex < len; rootIndex++)
	{
		if (in[rootIndex] == *(post + len - 1)) break;
	}
	node->left = BinaryTreeFromOrderings(in, post, rootIndex);
	node->right = BinaryTreeFromOrderings(in + rootIndex + 1, post + rootIndex, len - (rootIndex + 1));

	return node;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		int in [1024], post[1024];
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%d", &in[i]);
		for (int i = 0; i<n; i++) scanf("%d", &post[i]);
		BinaryTreeFromOrderings(in, post, n);
		printf("\n");
	}
}
